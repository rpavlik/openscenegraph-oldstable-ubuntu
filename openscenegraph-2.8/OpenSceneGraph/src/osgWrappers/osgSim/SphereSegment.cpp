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

#include <osg/Array>
#include <osg/CopyOp>
#include <osg/Drawable>
#include <osg/Matrixd>
#include <osg/Node>
#include <osg/NodeVisitor>
#include <osg/Object>
#include <osg/Vec3>
#include <osg/Vec4>
#include <osgSim/SphereSegment>

// Must undefine IN and OUT macros defined in Windows headers
#ifdef IN
#undef IN
#endif
#ifdef OUT
#undef OUT
#endif

TYPE_NAME_ALIAS(std::vector< osg::ref_ptr< osg::Vec3Array > >, osgSim::SphereSegment::LineList)

BEGIN_ENUM_REFLECTOR(osgSim::SphereSegment::DrawMask)
	I_DeclaringFile("osgSim/SphereSegment");
	I_EnumLabel(osgSim::SphereSegment::SURFACE);
	I_EnumLabel(osgSim::SphereSegment::SPOKES);
	I_EnumLabel(osgSim::SphereSegment::EDGELINE);
	I_EnumLabel(osgSim::SphereSegment::SIDES);
	I_EnumLabel(osgSim::SphereSegment::ALL);
END_REFLECTOR

BEGIN_OBJECT_REFLECTOR(osgSim::SphereSegment)
	I_DeclaringFile("osgSim/SphereSegment");
	I_BaseType(osg::Geode);
	I_Constructor0(____SphereSegment,
	               "Default constructor. ",
	               "");
	I_Constructor7(IN, const osg::Vec3 &, centre, IN, float, radius, IN, float, azMin, IN, float, azMax, IN, float, elevMin, IN, float, elevMax, IN, int, density,
	               ____SphereSegment__C5_osg_Vec3_R1__float__float__float__float__float__int,
	               "Construct by angle ranges. ",
	               " param centre sphere centre  radius radius of sphere  azMin azimuth minimum  azMax azimuth maximum  elevMin elevation minimum  elevMax elevation maximum  density number of units to divide the azimuth and elevation ranges into  ");
	I_Constructor6(IN, const osg::Vec3 &, centre, IN, float, radius, IN, const osg::Vec3 &, vec, IN, float, azRange, IN, float, elevRange, IN, int, density,
	               ____SphereSegment__C5_osg_Vec3_R1__float__C5_osg_Vec3_R1__float__float__int,
	               "Construct by vector. ",
	               " param centre sphere centre  radius radius of sphere  vec vector pointing from sphere centre to centre point of rendered area on sphere surface  azRange azimuth range in radians (with centre along vec)  elevRange elevation range in radians (with centre along vec)  density number of units to divide the azimuth and elevation ranges into  ");
	I_Constructor2(IN, const osgSim::SphereSegment &, rhs, IN, const osg::CopyOp &, co,
	               ____SphereSegment__C5_SphereSegment_R1__C5_osg_CopyOp_R1,
	               "Copy constructor. ",
	               "");
	I_Method1(void, setCentre, IN, const osg::Vec3 &, c,
	          Properties::NON_VIRTUAL,
	          __void__setCentre__C5_osg_Vec3_R1,
	          "Set the centre point of the SphereSegment. ",
	          "");
	I_Method0(const osg::Vec3 &, getCentre,
	          Properties::NON_VIRTUAL,
	          __C5_osg_Vec3_R1__getCentre,
	          "Get the centre point of the SphereSegment. ",
	          "");
	I_Method1(void, setRadius, IN, float, r,
	          Properties::NON_VIRTUAL,
	          __void__setRadius__float,
	          "Set the radius of the SphereSegment. ",
	          "");
	I_Method0(float, getRadius,
	          Properties::NON_VIRTUAL,
	          __float__getRadius,
	          "Get the radius of the SphereSegment. ",
	          "");
	I_Method3(void, setArea, IN, const osg::Vec3 &, vec, IN, float, azRange, IN, float, elevRange,
	          Properties::NON_VIRTUAL,
	          __void__setArea__C5_osg_Vec3_R1__float__float,
	          "Set the area of the sphere segment. ",
	          " param vec vector pointing from sphere centre to centre point of rendered area on sphere surface  azRange azimuth range in radians (with centre along vec)  elevRange elevation range in radians (with centre along vec)  ");
	I_Method3(void, getArea, IN, osg::Vec3 &, vec, IN, float &, azRange, IN, float &, elevRange,
	          Properties::NON_VIRTUAL,
	          __void__getArea__osg_Vec3_R1__float_R1__float_R1,
	          "Get the area of the sphere segment. ",
	          " param vec vector pointing from sphere centre to centre point of rendered area on sphere surface (normalized)  azRange azimuth range in radians (with centre along vec)  elevRange elevation range in radians (with centre along vec)  ");
	I_Method4(void, setArea, IN, float, azMin, IN, float, azMax, IN, float, elevMin, IN, float, elevMax,
	          Properties::NON_VIRTUAL,
	          __void__setArea__float__float__float__float,
	          "Set the area of the sphere segment. ",
	          " param azMin azimuth minimum  azMax azimuth maximum  elevMin elevation minimum  elevMax elevation maximum  ");
	I_Method4(void, getArea, IN, float &, azMin, IN, float &, azMax, IN, float &, elevMin, IN, float &, elevMax,
	          Properties::NON_VIRTUAL,
	          __void__getArea__float_R1__float_R1__float_R1__float_R1,
	          "Get the area of the sphere segment. ",
	          " param azMin azimuth minimum  azMax azimuth maximum  elevMin elevation minimum  elevMax elevation maximum  ");
	I_Method1(void, setDensity, IN, int, d,
	          Properties::NON_VIRTUAL,
	          __void__setDensity__int,
	          "Set the density of the sphere segment. ",
	          "");
	I_Method0(int, getDensity,
	          Properties::NON_VIRTUAL,
	          __int__getDensity,
	          "Get the density of the sphere segment. ",
	          "");
	I_Method1(void, setDrawMask, IN, osgSim::SphereSegment::DrawMask, dm,
	          Properties::NON_VIRTUAL,
	          __void__setDrawMask__DrawMask,
	          "Specify the DrawMask. ",
	          " param dm Bitmask specifying which parts of the sphere segment should be drawn.   see DrawMask ");
	I_Method0(osgSim::SphereSegment::DrawMask, getDrawMask,
	          Properties::NON_VIRTUAL,
	          __DrawMask__getDrawMask,
	          "Get the DrawMask. ",
	          "");
	I_Method1(void, setSurfaceColor, IN, const osg::Vec4 &, c,
	          Properties::NON_VIRTUAL,
	          __void__setSurfaceColor__C5_osg_Vec4_R1,
	          "Set the color of the surface. ",
	          "");
	I_Method0(osg::Vec4, getSurfaceColor,
	          Properties::NON_VIRTUAL,
	          __osg_Vec4__getSurfaceColor,
	          "Get the color of the surface. ",
	          "");
	I_Method1(void, setSpokeColor, IN, const osg::Vec4 &, c,
	          Properties::NON_VIRTUAL,
	          __void__setSpokeColor__C5_osg_Vec4_R1,
	          "Set the color of the spokes. ",
	          "");
	I_Method0(osg::Vec4, getSpokeColor,
	          Properties::NON_VIRTUAL,
	          __osg_Vec4__getSpokeColor,
	          "Get the color of the spokes. ",
	          "");
	I_Method1(void, setEdgeLineColor, IN, const osg::Vec4 &, c,
	          Properties::NON_VIRTUAL,
	          __void__setEdgeLineColor__C5_osg_Vec4_R1,
	          "Set the color of the edge line. ",
	          "");
	I_Method0(osg::Vec4, getEdgeLineColor,
	          Properties::NON_VIRTUAL,
	          __osg_Vec4__getEdgeLineColor,
	          "Get the color of the edge line. ",
	          "");
	I_Method1(void, setSideColor, IN, const osg::Vec4 &, c,
	          Properties::NON_VIRTUAL,
	          __void__setSideColor__C5_osg_Vec4_R1,
	          "Set the color of the planes. ",
	          "");
	I_Method0(osg::Vec4, getSideColor,
	          Properties::NON_VIRTUAL,
	          __osg_Vec4__getSideColor,
	          "Get the color of the planes. ",
	          "");
	I_Method1(void, setAllColors, IN, const osg::Vec4 &, c,
	          Properties::NON_VIRTUAL,
	          __void__setAllColors__C5_osg_Vec4_R1,
	          "Set color of all components. ",
	          "");
	I_Method0(osg::Object *, cloneType,
	          Properties::VIRTUAL,
	          __osg_Object_P1__cloneType,
	          "clone an object of the same type as the node. ",
	          "");
	I_Method1(osg::Object *, clone, IN, const osg::CopyOp &, copyop,
	          Properties::VIRTUAL,
	          __osg_Object_P1__clone__C5_osg_CopyOp_R1,
	          "return a clone of a node, with Object* return type. ",
	          "");
	I_Method1(bool, isSameKindAs, IN, const osg::Object *, obj,
	          Properties::VIRTUAL,
	          __bool__isSameKindAs__C5_osg_Object_P1,
	          "return true if this and obj are of the same kind of object. ",
	          "");
	I_Method0(const char *, className,
	          Properties::VIRTUAL,
	          __C5_char_P1__className,
	          "return the name of the node's class type. ",
	          "");
	I_Method0(const char *, libraryName,
	          Properties::VIRTUAL,
	          __C5_char_P1__libraryName,
	          "return the name of the node's library. ",
	          "");
	I_Method1(void, accept, IN, osg::NodeVisitor &, nv,
	          Properties::VIRTUAL,
	          __void__accept__osg_NodeVisitor_R1,
	          "Visitor Pattern : calls the apply method of a NodeVisitor with this node's type. ",
	          "");
	I_Method2(osgSim::SphereSegment::LineList, computeIntersection, IN, const osg::Matrixd &, matrix, IN, osg::Node *, subgraph,
	          Properties::NON_VIRTUAL,
	          __LineList__computeIntersection__C5_osg_Matrixd_R1__osg_Node_P1,
	          "Compute the interesection lines between subgraph and this sphere segment. ",
	          "The matrix is the transform that takes the subgraph into the same coordiante frame as the sphere segment. The resulting intersections are in the coordinate frame of the sphere segment. ");
	I_Method2(osgSim::SphereSegment::LineList, computeIntersection, IN, const osg::Matrixd &, matrix, IN, osg::Drawable *, drawable,
	          Properties::NON_VIRTUAL,
	          __LineList__computeIntersection__C5_osg_Matrixd_R1__osg_Drawable_P1,
	          "Compute the interesection lines between specified drawable and this sphere segment. ",
	          "The matrix is the transform that takes the subgraph into the same coordiante frame as the sphere segment. The resulting intersections are in the coordinate frame of the sphere segment. ");
	I_Method2(osg::Node *, computeIntersectionSubgraph, IN, const osg::Matrixd &, matrix, IN, osg::Node *, subgraph,
	          Properties::NON_VIRTUAL,
	          __osg_Node_P1__computeIntersectionSubgraph__C5_osg_Matrixd_R1__osg_Node_P1,
	          "Compute the interesection lines between subgraph and this sphere segment. ",
	          "The matrix is the transform that takes the subgraph into the same coordiante frame as the sphere segment. The resulting intersections are in the coordinate frame of the sphere segment. ");
	I_Method2(osg::Node *, computeIntersectionSubgraph, IN, const osg::Matrixd &, matrix, IN, osg::Drawable *, drawable,
	          Properties::NON_VIRTUAL,
	          __osg_Node_P1__computeIntersectionSubgraph__C5_osg_Matrixd_R1__osg_Drawable_P1,
	          "Compute the interesection lines between specified drawable and this sphere segment. ",
	          "The matrix is the transform that takes the subgraph into the same coordiante frame as the sphere segment. The resulting intersections are in the coordinate frame of the sphere segment. ");
	I_SimpleProperty(const osg::Vec4 &, AllColors, 
	                 0, 
	                 __void__setAllColors__C5_osg_Vec4_R1);
	I_SimpleProperty(const osg::Vec3 &, Centre, 
	                 __C5_osg_Vec3_R1__getCentre, 
	                 __void__setCentre__C5_osg_Vec3_R1);
	I_SimpleProperty(int, Density, 
	                 __int__getDensity, 
	                 __void__setDensity__int);
	I_SimpleProperty(osgSim::SphereSegment::DrawMask, DrawMask, 
	                 __DrawMask__getDrawMask, 
	                 __void__setDrawMask__DrawMask);
	I_SimpleProperty(osg::Vec4, EdgeLineColor, 
	                 __osg_Vec4__getEdgeLineColor, 
	                 __void__setEdgeLineColor__C5_osg_Vec4_R1);
	I_SimpleProperty(float, Radius, 
	                 __float__getRadius, 
	                 __void__setRadius__float);
	I_SimpleProperty(osg::Vec4, SideColor, 
	                 __osg_Vec4__getSideColor, 
	                 __void__setSideColor__C5_osg_Vec4_R1);
	I_SimpleProperty(osg::Vec4, SpokeColor, 
	                 __osg_Vec4__getSpokeColor, 
	                 __void__setSpokeColor__C5_osg_Vec4_R1);
	I_SimpleProperty(osg::Vec4, SurfaceColor, 
	                 __osg_Vec4__getSurfaceColor, 
	                 __void__setSurfaceColor__C5_osg_Vec4_R1);
END_REFLECTOR

BEGIN_VALUE_REFLECTOR(osg::ref_ptr< osg::Vec3Array >)
	I_DeclaringFile("osg/ref_ptr");
	I_Constructor0(____ref_ptr,
	               "",
	               "");
	I_Constructor1(IN, osg::Vec3Array *, ptr,
	               Properties::NON_EXPLICIT,
	               ____ref_ptr__T_P1,
	               "",
	               "");
	I_Constructor1(IN, const osg::ref_ptr< osg::Vec3Array > &, rp,
	               Properties::NON_EXPLICIT,
	               ____ref_ptr__C5_ref_ptr_R1,
	               "",
	               "");
	I_Method0(osg::Vec3Array *, get,
	          Properties::NON_VIRTUAL,
	          __T_P1__get,
	          "",
	          "");
	I_Method0(bool, valid,
	          Properties::NON_VIRTUAL,
	          __bool__valid,
	          "",
	          "");
	I_Method0(osg::Vec3Array *, release,
	          Properties::NON_VIRTUAL,
	          __T_P1__release,
	          "",
	          "");
	I_Method1(void, swap, IN, osg::ref_ptr< osg::Vec3Array > &, rp,
	          Properties::NON_VIRTUAL,
	          __void__swap__ref_ptr_R1,
	          "",
	          "");
	I_SimpleProperty(osg::Vec3Array *, , 
	                 __T_P1__get, 
	                 0);
END_REFLECTOR

STD_VECTOR_REFLECTOR(std::vector< osg::ref_ptr< osg::Vec3Array > >)

