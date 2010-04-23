/**********************************************************************
 *
 *    FILE:            PolygonMode.cpp
 *
 *    DESCRIPTION:    Read/Write osg::PolygonMode in binary format to disk.
 *
 *    CREATED BY:        Auto generated by iveGenerator
 *                    and later modified by Rune Schmidt Jensen.
 *
 *    HISTORY:        Created 6.10.2005
 *
 *    Copyright 2003 VR-C
 **********************************************************************/

#include "Exception.h"
#include "PolygonMode.h"
#include "Object.h"

using namespace ive;

void PolygonMode::write(DataOutputStream* out){
    // Write PolygonMode's identification.
    out->writeInt(IVEPOLYGONMODE);
    // If the osg class is inherited by any other class we should also write this to file.
    osg::Object*  obj = dynamic_cast<osg::Object*>(this);
    if(obj){
        ((ive::Object*)(obj))->write(out);
    }
    else
        throw Exception("PolygonMode::write(): Could not cast this osg::PolygonMode to an osg::Object.");
    // Write PolygonMode's properties.
    out->writeInt(getMode(osg::PolygonMode::FRONT));
    out->writeInt(getMode(osg::PolygonMode::BACK));
}

void PolygonMode::read(DataInputStream* in){
    // Peek on PolygonMode's identification.
    int id = in->peekInt();
    if(id == IVEPOLYGONMODE){
        // Read PolygonMode's identification.
        id = in->readInt();
        // If the osg class is inherited by any other class we should also read this from file.
        osg::Object*  obj = dynamic_cast<osg::Object*>(this);
        if(obj){
            ((ive::Object*)(obj))->read(in);
        }
        else
            throw Exception("PolygonMode::read(): Could not cast this osg::PolygonMode to an osg::Object.");
        // Read PolygonMode's properties
        setMode(osg::PolygonMode::FRONT,(Mode)in->readInt());
        setMode(osg::PolygonMode::BACK,(Mode)in->readInt());
    }
    else{
        throw Exception("PolygonMode::read(): Expected PolygonMode identification.");
    }
}


