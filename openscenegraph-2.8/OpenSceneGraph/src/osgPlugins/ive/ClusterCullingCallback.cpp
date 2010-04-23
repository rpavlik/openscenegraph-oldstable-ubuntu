/**********************************************************************
 *
 *    FILE:            ClusterCullingCallback.cpp
 *
 *    DESCRIPTION:    Read/Write osg::ClusterCullingCallback in binary format to disk.
 *
 *    CREATED BY:        Auto generated by iveGenerate
 *                    and later modified by Rune Schmidt Jensen.
 *
 *    HISTORY:        Created 25.3.2003
 *
 *    Copyright 2003 VR-C
 **********************************************************************/

#include "Exception.h"
#include "ClusterCullingCallback.h"
#include "Object.h"

using namespace ive;

void ClusterCullingCallback::write(DataOutputStream* out)
{
    // Write ClusterCullingCallback's identification.
    out->writeInt(IVECLUSTERCULLINGCALLBACK);
    // If the osg class is inherited by any other class we should also write this to file.
    osg::Object*  obj = dynamic_cast<osg::Object*>(this);
    if(obj)
    {
        ((ive::Object*)(obj))->write(out);
    }
    else
        throw Exception("ClusterCullingCallback::write(): Could not cast this osg::ClusterCullingCallback to an osg::Object.");
    // Write ClusterCullingCallback's properties.

    out->writeVec3(_controlPoint);
    out->writeVec3(_normal);
    out->writeFloat(_radius);
    out->writeFloat(_deviation);
}

void ClusterCullingCallback::read(DataInputStream* in)
{
    // Peek on ClusterCullingCallback's identification.
    int id = in->peekInt();
    if(id == IVECLUSTERCULLINGCALLBACK)
    {
        // Read ClusterCullingCallback's identification.
        id = in->readInt();
        // If the osg class is inherited by any other class we should also read this from file.
        osg::Object*  obj = dynamic_cast<osg::Object*>(this);
        if(obj)
        {
            ((ive::Object*)(obj))->read(in);
        }
        else
            throw Exception("ClusterCullingCallback::read(): Could not cast this osg::ClusterCullingCallback to an osg::Object.");
    
        // Read ClusterCullingCallback's properties
        
        _controlPoint = in->readVec3();
        _normal = in->readVec3();
        _radius = in->readFloat();
        _deviation = in->readFloat();
        
    }
    else
    {
        throw Exception("ClusterCullingCallback::read(): Expected ClusterCullingCallback identification.");
    }
}
