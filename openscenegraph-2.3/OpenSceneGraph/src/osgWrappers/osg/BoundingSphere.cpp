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

#include <osg/BoundingBox>
#include <osg/BoundingSphere>
#include <osg/Vec3>

// Must undefine IN and OUT macros defined in Windows headers
#ifdef IN
#undef IN
#endif
#ifdef OUT
#undef OUT
#endif

BEGIN_VALUE_REFLECTOR(osg::BoundingSphere)
	I_DeclaringFile("osg/BoundingSphere");
	I_Constructor0(____BoundingSphere,
	               "Construct a default bounding sphere with radius to -1.0f, representing an invalid/unset bounding sphere. ",
	               "");
	I_Constructor2(IN, const osg::Vec3 &, center, IN, float, radius,
	               ____BoundingSphere__C5_Vec3_R1__float,
	               "Creates a bounding sphere initialized to the given extents. ",
	               "");
	I_Constructor1(IN, const osg::BoundingSphere &, bs,
	               Properties::NON_EXPLICIT,
	               ____BoundingSphere__C5_BoundingSphere_R1,
	               "Creates a bounding sphere initialized to the given extents. ",
	               "");
	I_Constructor1(IN, const osg::BoundingBox &, bb,
	               Properties::NON_EXPLICIT,
	               ____BoundingSphere__C5_BoundingBox_R1,
	               "Creates a bounding sphere initialized to the given extents. ",
	               "");
	I_Method0(void, init,
	          Properties::NON_VIRTUAL,
	          __void__init,
	          "Clear the bounding sphere. ",
	          "Reset to default values. ");
	I_Method0(bool, valid,
	          Properties::NON_VIRTUAL,
	          __bool__valid,
	          "Returns true of the bounding sphere extents are valid, false otherwise. ",
	          "");
	I_Method2(void, set, IN, const osg::Vec3 &, center, IN, float, radius,
	          Properties::NON_VIRTUAL,
	          __void__set__C5_Vec3_R1__float,
	          "Set the bounding sphere to the given center/radius. ",
	          "");
	I_Method0(osg::Vec3 &, center,
	          Properties::NON_VIRTUAL,
	          __Vec3_R1__center,
	          "Returns the center of the bounding sphere. ",
	          "");
	I_Method0(const osg::Vec3 &, center,
	          Properties::NON_VIRTUAL,
	          __C5_Vec3_R1__center,
	          "Returns the const center of the bounding sphere. ",
	          "");
	I_Method0(float &, radius,
	          Properties::NON_VIRTUAL,
	          __float_R1__radius,
	          "Returns the radius of the bounding sphere. ",
	          "");
	I_Method0(float, radius,
	          Properties::NON_VIRTUAL,
	          __float__radius,
	          "Returns the const radius of the bounding sphere. ",
	          "");
	I_Method0(float, radius2,
	          Properties::NON_VIRTUAL,
	          __float__radius2,
	          "Returns the squared length of the radius. ",
	          "Note, For performance reasons, the calling method is responsible for checking to make sure the sphere is valid. ");
	I_Method1(void, expandBy, IN, const osg::Vec3 &, v,
	          Properties::NON_VIRTUAL,
	          __void__expandBy__C5_Vec3_R1,
	          "Expands the sphere to encompass the given point. ",
	          "Repositions the sphere center to minimize the radius increase. If the sphere is uninitialized, set its center to v and radius to zero. ");
	I_Method1(void, expandRadiusBy, IN, const osg::Vec3 &, v,
	          Properties::NON_VIRTUAL,
	          __void__expandRadiusBy__C5_Vec3_R1,
	          "Expands the sphere to encompass the given point. ",
	          "Does not reposition the sphere center. If the sphere is uninitialized, set its center to v and radius to zero. ");
	I_Method1(void, expandBy, IN, const osg::BoundingSphere &, sh,
	          Properties::NON_VIRTUAL,
	          __void__expandBy__C5_BoundingSphere_R1,
	          "Expands the sphere to encompass the given sphere. ",
	          "Repositions the sphere center to minimize the radius increase. If the sphere is uninitialized, set its center and radius to match sh. ");
	I_Method1(void, expandRadiusBy, IN, const osg::BoundingSphere &, sh,
	          Properties::NON_VIRTUAL,
	          __void__expandRadiusBy__C5_BoundingSphere_R1,
	          "Expands the sphere to encompass the given sphere. ",
	          "Does not repositions the sphere center. If the sphere is uninitialized, set its center and radius to match sh. ");
	I_Method1(void, expandBy, IN, const osg::BoundingBox &, bb,
	          Properties::NON_VIRTUAL,
	          __void__expandBy__C5_BoundingBox_R1,
	          "Expands the sphere to encompass the given box. ",
	          "Repositions the sphere center to minimize the radius increase. ");
	I_Method1(void, expandRadiusBy, IN, const osg::BoundingBox &, bb,
	          Properties::NON_VIRTUAL,
	          __void__expandRadiusBy__C5_BoundingBox_R1,
	          "Expands the sphere to encompass the given box. ",
	          "Does not repositions the sphere center. ");
	I_Method1(bool, contains, IN, const osg::Vec3 &, v,
	          Properties::NON_VIRTUAL,
	          __bool__contains__C5_Vec3_R1,
	          "Returns true if v is within the sphere. ",
	          "");
	I_Method1(bool, intersects, IN, const osg::BoundingSphere &, bs,
	          Properties::NON_VIRTUAL,
	          __bool__intersects__C5_BoundingSphere_R1,
	          "Returns true if there is a non-empty intersection with the given bounding sphere. ",
	          "");
	I_PublicMemberProperty(osg::Vec3, _center);
	I_PublicMemberProperty(float, _radius);
END_REFLECTOR
