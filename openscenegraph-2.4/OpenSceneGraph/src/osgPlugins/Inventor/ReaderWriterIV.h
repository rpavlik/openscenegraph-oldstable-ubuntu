#ifndef _READERWRITERIV_H_
#define _READERWRITERIV_H_

#include <osgDB/Registry>
#include <osgDB/FileNameUtils>

class ReaderWriterIV : public osgDB::ReaderWriter
{
    public:
        ReaderWriterIV();
        
        virtual const char* className() const
        { 
            return "Inventor reader/writer"; 
        }
        
        bool isInventorExtension(const std::string& extension) const
        {
            return osgDB::equalCaseInsensitive(extension, "iv") ? true : false;
        }

        virtual bool acceptsExtension(const std::string& extension) const
        {
            return isInventorExtension(extension) ? true :
                   osgDB::equalCaseInsensitive(extension, "wrl") ? true : false;
        }
        
        virtual ReadResult readNode(const std::string& filename, 
                                    const osgDB::ReaderWriter::Options *) const;

        virtual WriteResult writeNode(const osg::Node& node, const std::string& filename,
                                      const osgDB::ReaderWriter::Options* options = NULL) const;
};

#endif