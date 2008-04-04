#include <osgDB/FileNameUtils>
#include <osgDB/FileUtils>
#include <osgDB/Registry>
#include <osg/Notify>

#include "FreeTypeLibrary.h"

class ReaderWriterFreeType : public osgDB::ReaderWriter
{
    public:
        virtual const char* className() const { return "FreeType Font Reader/Writer"; }
        
        virtual bool acceptsExtension(const std::string& extension) const
        {
            return osgDB::equalCaseInsensitive(extension,"ttf") ||  // true type
                   osgDB::equalCaseInsensitive(extension,"ttc") ||  // true type
                   osgDB::equalCaseInsensitive(extension,"pfb") ||  // type1 binary
                   osgDB::equalCaseInsensitive(extension,"pfa") ||  // type2 ascii
                   osgDB::equalCaseInsensitive(extension,"cid") ||  // Postscript CID-Fonts
                   osgDB::equalCaseInsensitive(extension,"cff") ||  // OpenType
                   osgDB::equalCaseInsensitive(extension,"cef") ||  // OpenType
                   osgDB::equalCaseInsensitive(extension,"fon") ||  // Windows bitmap fonts
                   osgDB::equalCaseInsensitive(extension,"fnt");    // Windows bitmap fonts
        }

        static unsigned int getFlags(const osgDB::ReaderWriter::Options* options)
        {
            unsigned int flags = 0;
            if (options && options->getOptionString().find("monochrome") != std::string::npos)
            {
                flags |= FT_LOAD_MONOCHROME;
            }
            
            return flags;
        }

        virtual ReadResult readObject(const std::string& file, const osgDB::ReaderWriter::Options* options) const
        {
            std::string ext = osgDB::getLowerCaseFileExtension(file);
            if (!acceptsExtension(ext)) return ReadResult::FILE_NOT_HANDLED;

            std::string fileName = osgDB::findDataFile( file, options );
            if (fileName.empty()) return ReadResult::FILE_NOT_FOUND;
            
            FreeTypeLibrary* freeTypeLibrary = FreeTypeLibrary::instance();
            if (!freeTypeLibrary) 
            {
                osg::notify(osg::WARN)<<"Warning:: cannot create freetype font after freetype library has been deleted."<<std::endl;
                return ReadResult::ERROR_IN_READING_FILE;
            }

            if (options->getPluginData("3D"))
                return freeTypeLibrary->getFont3D(fileName,0,getFlags(options));
            else
                return freeTypeLibrary->getFont(fileName,0,getFlags(options));
        }

        virtual ReadResult readObject(std::istream& stream, const osgDB::ReaderWriter::Options* options) const
        {
            FreeTypeLibrary* freeTypeLibrary = FreeTypeLibrary::instance();
            if (!freeTypeLibrary) 
            {
                osg::notify(osg::WARN)<<"Warning:: cannot create freetype font after freetype library has been deleted."<<std::endl;
                return ReadResult::ERROR_IN_READING_FILE;
            }

            return freeTypeLibrary->getFont(stream, 0, getFlags(options));
        }
};

// now register with Registry to instantiate the above
// reader/writer.
REGISTER_OSGPLUGIN(freetype, ReaderWriterFreeType)