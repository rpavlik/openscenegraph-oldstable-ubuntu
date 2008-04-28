/* -*-c++-*- OpenSceneGraph - Copyright (C) 1998-2006 Robert Osfield 
 *
 * This library is open source and may be redistributed and/or modified under  
 * the terms of the OpenSceneGraph Public License (OSGPL) version 0.0 or 
 * (at your option) any later version.  The full license is in LICENSE file
 * included with this distribution, and on the openscenegraph.org website.
 * 
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
 * OpenSceneGraph Public License for more details.
*/

//
// OpenFlight� loader for OpenSceneGraph
//
//  Copyright (C) 2005-2007  Brede Johansen
//

#include <stdexcept>
#include <osg/Notify>
#include <osg/ProxyNode>
#include <osgDB/FileNameUtils>
#include <osgDB/FileUtils>
#include <osgDB/Registry>
#include <osgDB/ReadFile>
#include <OpenThreads/ReentrantMutex>
#include <osgUtil/Optimizer>

#include "Registry.h"
#include "Document.h"
#include "RecordInputStream.h"
#include "DataOutputStream.h"
#include "FltExportVisitor.h"
#include "ExportOptions.h"

#define SERIALIZER() OpenThreads::ScopedLock<OpenThreads::ReentrantMutex> lock(_serializerMutex)  

using namespace flt;
using namespace osg;
using namespace osgDB;


class ReadExternalsVisitor : public osg::NodeVisitor
{
    osg::ref_ptr<ReaderWriter::Options> _options;
    bool _cloneExternalReferences;

public:

    ReadExternalsVisitor(ReaderWriter::Options* options) :
        osg::NodeVisitor(osg::NodeVisitor::TRAVERSE_ALL_CHILDREN),
        _options(options),
        _cloneExternalReferences(false)
    {
        if (options)
            _cloneExternalReferences = (options->getOptionString().find("cloneExternalReferences")!=std::string::npos);
    }

    virtual ~ReadExternalsVisitor() {}

    virtual void apply(ProxyNode& node)
    {
        // Transfer ownership of pools.
        _options->setUserData( node.getUserData() );
        node.setUserData(NULL);

        for (unsigned int pos=0; pos<node.getNumFileNames(); pos++)
        {
            std::string filename = node.getFileName(pos);

            // read external
            osg::ref_ptr<osg::Node> external = osgDB::readNodeFile(filename,_options.get());
            if (external.valid())
            {
                if (_cloneExternalReferences)
                    external = dynamic_cast<osg::Node*>(external->clone(osg::CopyOp(osg::CopyOp::DEEP_COPY_NODES)));

                node.addChild(external.get());
            }
        }
    }
};



/*!

FLTReaderWriter supports importing and exporting OSG scene grqphs
from/to OpenFlight files.

<table>
  <tr>
    <th></th>
    <th align="center">Node</th>
    <th align="center">Object</th>
    <th align="center">Image</th>
    <th align="center">HeightField</th>
  </tr>
  <tr>
    <td align="right">Read</td>
    <td align="center"><strong>X</strong></td>
    <td></td>
    <td></td>
    <td></td>
  </tr>
  <tr>
    <td align="right">Write</td>
    <td align="center"><strong>X</strong></td>
    <td></td>
    <td></td>
    <td></td>
  </tr>
</table>

*/

class FLTReaderWriter : public ReaderWriter
{
    public:
        FLTReaderWriter()
          : _implicitPath( "." )
        {}

        virtual const char* className() const { return "FLT Reader/Writer"; }

        virtual bool acceptsExtension(const std::string& extension) const
        {
            return equalCaseInsensitive(extension,"flt") || extension.empty();
        }

        virtual ReadResult readObject(const std::string& file, const Options* options) const
        {
            return readNode(file, options);
        }
        
        virtual ReadResult readNode(const std::string& file, const Options* options) const
        {
            SERIALIZER();

            std::string ext = osgDB::getLowerCaseFileExtension(file);
            if (!acceptsExtension(ext)) return ReadResult::FILE_NOT_HANDLED;

            std::string fileName = osgDB::findDataFile(file, options);
            if (fileName.empty()) return ReadResult::FILE_NOT_FOUND;

            // in local cache?
            {
                osg::Node* node = flt::Registry::instance()->getExternalFromLocalCache(fileName);
                if (node)
                    return ReadResult(node, ReaderWriter::ReadResult::FILE_LOADED_FROM_CACHE);
            }

            // setting up the database path so that internally referenced file are searched for on relative paths. 
            osg::ref_ptr<Options> local_opt = options ? static_cast<Options*>(options->clone(osg::CopyOp::SHALLOW_COPY)) : new Options;
            local_opt->setDatabasePath(osgDB::getFilePath(fileName));

            ReadResult rr;

            // read file
            {
                std::ifstream istream;
                istream.imbue(std::locale::classic());
                istream.open(fileName.c_str(), std::ios::in | std::ios::binary);

                if (istream)
                {
                    rr = readNode(istream,local_opt.get());
                }
            }

            static int nestedExternalsLevel = 0;
            if (rr.success())
            {
                // add to local cache.
                flt::Registry::instance()->addExternalToLocalCache(fileName,rr.getNode());
        
                bool keepExternalReferences = false;
                if (options)
                    keepExternalReferences = (options->getOptionString().find("keepExternalReferences")!=std::string::npos);


                if ( !keepExternalReferences )
                {
                    osg::notify(osg::DEBUG_INFO) << "keepExternalReferences not found, so externals will be re-readed"<<std::endl;
                    // read externals.
                    if (rr.getNode())
                    {
                        nestedExternalsLevel++;
                        ReadExternalsVisitor visitor(local_opt.get());
                        rr.getNode()->accept(visitor);
                        nestedExternalsLevel--;
                    }
                }
                else
                {
                    osg::notify(osg::DEBUG_INFO) << "keepExternalReferences found, so externals will be left as ProxyNodes"<<std::endl;    
                }
            }

            // clear local cache.
            if (nestedExternalsLevel==0)
                flt::Registry::instance()->clearLocalCache();

            return rr;
        }
        
        virtual ReadResult readObject(std::istream& fin, const Options* options) const
        {
            return readNode(fin, options);
        }
        
        virtual ReadResult readNode(std::istream& fin, const Options* options) const
        {
            Document document;
            document.setOptions(options);

            // option string and parent pools
            if (options)
            {
                const char readerMsg[] = "flt reader option: ";
                
                document.setReplaceClampWithClampToEdge((options->getOptionString().find("clampToEdge")!=std::string::npos));
                osg::notify(osg::DEBUG_INFO) << readerMsg << "clampToEdge=" << document.getReplaceClampWithClampToEdge() << std::endl;

                document.setKeepExternalReferences((options->getOptionString().find("keepExternalReferences")!=std::string::npos));
                osg::notify(osg::DEBUG_INFO) << readerMsg << "keepExternalReferences=" << document.getKeepExternalReferences() << std::endl;

                document.setPreserveFace((options->getOptionString().find("preserveFace")!=std::string::npos));
                osg::notify(osg::DEBUG_INFO) << readerMsg << "preserveFace=" << document.getPreserveFace() << std::endl;

                document.setPreserveObject((options->getOptionString().find("preserveObject")!=std::string::npos));
                osg::notify(osg::DEBUG_INFO) << readerMsg << "preserveObject=" << document.getPreserveObject() << std::endl;

                document.setDefaultDOFAnimationState((options->getOptionString().find("dofAnimation")!=std::string::npos));
                osg::notify(osg::DEBUG_INFO) << readerMsg << "dofAnimation=" << document.getDefaultDOFAnimationState() << std::endl;

                document.setUseBillboardCenter((options->getOptionString().find("billboardCenter")!=std::string::npos));
                osg::notify(osg::DEBUG_INFO) << readerMsg << "billboardCenter=" << document.getUseBillboardCenter() << std::endl;

                document.setUseTextureAlphaForTransparancyBinning(options->getOptionString().find("noTextureAlphaForTransparancyBinning")==std::string::npos);
                osg::notify(osg::DEBUG_INFO) << readerMsg << "noTextureAlphaForTransparancyBinning=" << !document.getUseTextureAlphaForTransparancyBinning() << std::endl;

                document.setReadObjectRecordData(options->getOptionString().find("readObjectRecordData")==std::string::npos);
                osg::notify(osg::DEBUG_INFO) << readerMsg << "readObjectRecordData=" << !document.getReadObjectRecordData() << std::endl;

                document.setDoUnitsConversion((options->getOptionString().find("noUnitsConversion")==std::string::npos)); // default to true, unless noUnitsConversion is specified.
                osg::notify(osg::DEBUG_INFO) << readerMsg << "noUnitsConversion=" << !document.getDoUnitsConversion() << std::endl;

                if (document.getDoUnitsConversion())
                {
                    if (options->getOptionString().find("convertToFeet")!=std::string::npos)
                        document.setDesiredUnits(FEET);
                    else if (options->getOptionString().find("convertToInches")!=std::string::npos)
                        document.setDesiredUnits(INCHES);
                    else if (options->getOptionString().find("convertToMeters")!=std::string::npos)
                        document.setDesiredUnits(METERS);
                    else if (options->getOptionString().find("convertToKilometers")!=std::string::npos)
                        document.setDesiredUnits(KILOMETERS);
                    else if (options->getOptionString().find("convertToNauticalMiles")!=std::string::npos)
                        document.setDesiredUnits(NAUTICAL_MILES);
                }

                const ParentPools* pools = dynamic_cast<const ParentPools*>( options->getUserData() );
                if (pools)
                {
                    // This file is an external reference. The individual pools will
                    // be non-NULL if the parent is overriding the ext ref model's pools.
                    if (pools->getColorPool())
                        document.setColorPool( pools->getColorPool(), true );
                    if (pools->getTexturePool())
                        document.setTexturePool( pools->getTexturePool(), true );
                    if (pools->getMaterialPool())
                        document.setMaterialPool( pools->getMaterialPool(), true );
                    if (pools->getLightSourcePool())
                        document.setLightSourcePool( pools->getLightSourcePool(), true );
                    if (pools->getLPAppearancePool())
                        document.setLightPointAppearancePool( pools->getLPAppearancePool(), true );
                    if (pools->getLPAnimationPool())
                        document.setLightPointAnimationPool( pools->getLPAnimationPool(), true );
                    if (pools->getShaderPool())
                        document.setShaderPool( pools->getShaderPool(), true );
                }
            }

            const int RECORD_HEADER_SIZE = 4;
            opcode_type continuationOpcode = -1;
            std::string continuationBuffer;

            while (fin.good() && !document.done())
            {
                // The continuation record complicates things a bit.

                // Get current read position in stream.
                std::istream::pos_type pos = fin.tellg();

                // get opcode and size
                flt::DataInputStream dataStream(fin.rdbuf());
                opcode_type opcode = (opcode_type)dataStream.readUInt16();
                size_type   size   = (size_type)dataStream.readUInt16();

                // variable length record complete?
                if (!continuationBuffer.empty() && opcode!=CONTINUATION_OP)
                {
                    // parse variable length record
                    std::stringbuf sb(continuationBuffer);
                    flt::RecordInputStream recordStream(&sb);
                    recordStream.readRecordBody(continuationOpcode, continuationBuffer.length(), document);

                    continuationOpcode = -1;
                    continuationBuffer.clear();
                }

                // variable length record use continuation buffer in case next
                // record is a continuation record.
                if (opcode==EXTENSION_OP ||
                    opcode==NAME_TABLE_OP ||
                    opcode==LOCAL_VERTEX_POOL_OP ||
                    opcode==MESH_PRIMITIVE_OP)
                {
                    continuationOpcode = opcode;

                    if (size > RECORD_HEADER_SIZE)
                    {
                        // Put record in buffer.
                        std::string buffer((std::string::size_type)size-RECORD_HEADER_SIZE,'\0');
                        fin.read(&buffer[0], size-RECORD_HEADER_SIZE);

                        // Can't parse it until we know we have the complete record.
                        continuationBuffer = buffer;
                    }
                }
                else if (opcode==CONTINUATION_OP)
                {
                    if (size > RECORD_HEADER_SIZE)
                    {
                        std::string buffer((std::string::size_type)size-RECORD_HEADER_SIZE,'\0');
                        fin.read(&buffer[0], size-RECORD_HEADER_SIZE);

                        // The record continues.
                        continuationBuffer.append(buffer);
                    }
                }
                else if (opcode==VERTEX_PALETTE_OP)
                {
                    // Vertex Palette needs the file stream as it reads beyond the current record.
                    flt::RecordInputStream recordStream(fin.rdbuf());
                    recordStream.readRecordBody(opcode, size, document);
                }
                else // normal (fixed size) record.
                {
                    // Put record in buffer.
                    std::string buffer((std::string::size_type)size,'\0');
                    if (size > RECORD_HEADER_SIZE)
                        fin.read(&buffer[0], size-RECORD_HEADER_SIZE);

                    // Parse buffer.
                    std::stringbuf sb(buffer);
                    flt::RecordInputStream recordStream(&sb);
                    recordStream.readRecordBody(opcode, size, document);
                }
            }

            if (!document.getHeaderNode())
                return ReadResult::ERROR_IN_READING_FILE;

            if (!document.getPreserveFace())
            {
                osgUtil::Optimizer optimizer;
                optimizer.optimize(document.getHeaderNode(),
                    osgUtil::Optimizer::SHARE_DUPLICATE_STATE |
                    osgUtil::Optimizer::MERGE_GEOMETRY | 
                    osgUtil::Optimizer::MERGE_GEODES | 
                    osgUtil::Optimizer::TESSELLATE_GEOMETRY |
                    osgUtil::Optimizer::STATIC_OBJECT_DETECTION);
            }

            return document.getHeaderNode();
        }

        virtual WriteResult writeObject(const Object& object,const std::string& fileName, const osgDB::ReaderWriter::Options* options) const
        {
            const Node* node = dynamic_cast<const Node*>(&object);
            if (node) return writeNode( *node, fileName, options );
            return WriteResult::FILE_NOT_HANDLED;
        }

        virtual WriteResult writeNode( const osg::Node& node, const std::string& fileName, const Options* options ) const
        {
            if ( fileName.empty() )
            {
                osg::notify( osg::FATAL ) << "fltexp: writeNode: empty file name" << std::endl;
                return WriteResult::FILE_NOT_HANDLED;
            }
            std::string ext = osgDB::getLowerCaseFileExtension( fileName );
            if ( !acceptsExtension(ext) )
                return WriteResult::FILE_NOT_HANDLED;

            // Get and save the implicit path name (in case a path wasn't specified in Options).
            std::string filePath = osgDB::getFilePath( fileName );
            if (!filePath.empty())
                _implicitPath = filePath;

            std::ofstream fOut;
            fOut.open( fileName.c_str(), std::ios::out | std::ios::binary );
            if ( fOut.fail())
            {
                osg::notify( osg::FATAL ) << "fltexp: Failed to open output stream." << std::endl;
                return WriteResult::ERROR_IN_WRITING_FILE;
            }

            WriteResult wr = WriteResult::FILE_NOT_HANDLED;
            wr = writeNode( node, fOut, options );
            fOut.close();

            return wr;
        }


        virtual WriteResult writeObject(const Object& object,std::ostream& fout, const osgDB::ReaderWriter::Options* options) const
        {
            const Node* node = dynamic_cast<const Node*>(&object);
            if (node) return writeNode( *node, fout, options );
            return WriteResult::FILE_NOT_HANDLED;
        }

        virtual WriteResult writeNode( const osg::Node& node, std::ostream& fOut, const Options* options ) const
        {
            // Convert Options to FltOptions.
            ExportOptions* fltOpt = new ExportOptions( options );
            fltOpt->parseOptionsString();

            // If user didn't specify a temp dir, use the output directory
            //   that was implicit in the output file name.
            if (fltOpt->getTempDir().empty())
                fltOpt->setTempDir( _implicitPath );
            if (!fltOpt->getTempDir().empty())
            {
                // If the temp directory doesn't already exist, make it.
                if ( !osgDB::makeDirectory( fltOpt->getTempDir() ) )
                {
                    osg::notify( osg::FATAL ) << "fltexp: Error creating temp dir: " << fltOpt->getTempDir() << std::endl;
                    return WriteResult::ERROR_IN_WRITING_FILE;
                }
            }

            flt::DataOutputStream dos( fOut.rdbuf(), fltOpt->getValidateOnly() );
            flt::FltExportVisitor fnv( &dos, fltOpt );

            // Hm. 'node' is const, but in order to write out this scene graph,
            //   must use Node::accept() which requires 'node' to be non-const.
            //   Pretty much requires casting away const.
            osg::Node* nodeNonConst = const_cast<osg::Node*>( &node );
            if (!nodeNonConst)
                return WriteResult::ERROR_IN_WRITING_FILE;
            nodeNonConst->accept( fnv );
            fnv.complete( node );

            return fltOpt->getWriteResult();
        }

    protected:
        mutable std::string _implicitPath;

        mutable OpenThreads::ReentrantMutex _serializerMutex;
};

// now register with Registry to instantiate the above
// reader/writer.
REGISTER_OSGPLUGIN(OpenFlight, FLTReaderWriter)