/**********************************************************************
 *
 *    FILE:            Scissor.cpp
 *
 *    DESCRIPTION:    Read/Write osg::Scissor in binary format to disk.
 *
 *    CREATED BY:        Auto generated by iveGenerated
 *                    and later modified by Rune Schmidt Jensen.
 *
 *    HISTORY:        Created 21.3.2003
 *
 *    Copyright 2003 VR-C
 **********************************************************************/

#include "Exception.h"
#include "Scissor.h"
#include "Object.h"

using namespace ive;

void Scissor::write(DataOutputStream* out){
    // Write Scissor's identification.
    out->writeInt(IVESCISSOR);
    // If the osg class is inherited by any other class we should also write this to file.
    osg::Object*  obj = dynamic_cast<osg::Object*>(this);
    if(obj){
        ((ive::Object*)(obj))->write(out);
    }
    else
        throw Exception("Scissor::write(): Could not cast this osg::Scissor to an osg::Object.");
    // Write Scissor's properties.

    out->writeInt(x());
    out->writeInt(y());
    out->writeInt(width());
    out->writeInt(height());
}

void Scissor::read(DataInputStream* in){
    // Peek on Scissor's identification.
    int id = in->peekInt();
    if(id == IVESCISSOR){
        // Read Scissor's identification.
        id = in->readInt();
        // If the osg class is inherited by any other class we should also read this from file.
        osg::Object*  obj = dynamic_cast<osg::Object*>(this);
        if(obj){
            ((ive::Object*)(obj))->read(in);
        }
        else
            throw Exception("Scissor::read(): Could not cast this osg::Scissor to an osg::Object.");

        // Read Scissor's properties
        x() = (GLenum)in->readInt();
        y() = (GLenum)in->readInt();
        width() = (GLenum)in->readInt();
        height() = (GLenum)in->readInt();

    }
    else{
        throw Exception("Scissor::read(): Expected Scissor identification.");
    }
}
