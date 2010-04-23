// ***************************************************************************
//
//   Generated automatically by genwrapper.
//   Please DO NOT EDIT this file!
//
// ***************************************************************************

#include <osgIntrospection/ReflectionMacros>
#include <osgIntrospection/TypedMethodInfo>
#include <osgIntrospection/StaticMethodInfo>
#include <osgIntrospection/Attributes>

#include <osg/Drawable>
#include <osg/Matrix>
#include <osg/Vec3>
#include <osgUtil/TransformAttributeFunctor>

// Must undefine IN and OUT macros defined in Windows headers
#ifdef IN
#undef IN
#endif
#ifdef OUT
#undef OUT
#endif

BEGIN_OBJECT_REFLECTOR(osgUtil::TransformAttributeFunctor)
	I_DeclaringFile("osgUtil/TransformAttributeFunctor");
	I_BaseType(osg::Drawable::AttributeFunctor);
	I_Constructor1(IN, const osg::Matrix &, m,
	               Properties::NON_EXPLICIT,
	               ____TransformAttributeFunctor__C5_osg_Matrix_R1,
	               "Construct a functor to transform a drawable's vertex and normal attributes by specified matrix. ",
	               "");
	I_Method3(void, apply, IN, osg::Drawable::AttributeType, type, IN, unsigned int, count, IN, osg::Vec3 *, begin,
	          Properties::VIRTUAL,
	          __void__apply__osg_Drawable_AttributeType__unsigned_int__osg_Vec3_P1,
	          "Do the work of transforming vertex and normal attributes. ",
	          "");
	I_PublicMemberProperty(osg::Matrix, _m);
	I_PublicMemberProperty(osg::Matrix, _im);
END_REFLECTOR

