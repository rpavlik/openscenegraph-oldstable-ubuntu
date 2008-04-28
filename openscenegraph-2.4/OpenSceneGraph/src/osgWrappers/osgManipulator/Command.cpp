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

#include <osg/LineSegment>
#include <osg/Matrix>
#include <osg/Plane>
#include <osg/Quat>
#include <osg/Vec2>
#include <osg/Vec3>
#include <osgManipulator/Command>
#include <osgManipulator/Constraint>
#include <osgManipulator/Selection>

// Must undefine IN and OUT macros defined in Windows headers
#ifdef IN
#undef IN
#endif
#ifdef OUT
#undef OUT
#endif

BEGIN_ENUM_REFLECTOR(osgManipulator::MotionCommand::Stage)
	I_DeclaringFile("osgManipulator/Command");
	I_EnumLabel(osgManipulator::MotionCommand::NONE);
	I_EnumLabel(osgManipulator::MotionCommand::START);
	I_EnumLabel(osgManipulator::MotionCommand::MOVE);
	I_EnumLabel(osgManipulator::MotionCommand::FINISH);
END_REFLECTOR

BEGIN_ABSTRACT_OBJECT_REFLECTOR(osgManipulator::MotionCommand)
	I_DeclaringFile("osgManipulator/Command");
	I_BaseType(osg::Referenced);
	I_Constructor0(____MotionCommand,
	               "",
	               "");
	I_Method0(bool, execute,
	          Properties::PURE_VIRTUAL,
	          __bool__execute,
	          "Execute the command. ",
	          "");
	I_Method0(bool, unexecute,
	          Properties::PURE_VIRTUAL,
	          __bool__unexecute,
	          "Undo the command. ",
	          "The inverse of this command is executed. ");
	I_Method1(void, applyConstraint, IN, const osgManipulator::Constraint *, x,
	          Properties::PURE_VIRTUAL,
	          __void__applyConstraint__C5_Constraint_P1,
	          "Apply a constraint to the command. ",
	          "");
	I_Method1(void, addSelection, IN, osgManipulator::Selection *, x,
	          Properties::NON_VIRTUAL,
	          __void__addSelection__Selection_P1,
	          "Add Selection (receiver) to the command. ",
	          "The command will be executed on all the selections. ");
	I_Method1(void, removeSelection, IN, osgManipulator::Selection *, x,
	          Properties::NON_VIRTUAL,
	          __void__removeSelection__Selection_P1,
	          "Remove Selection (receiver) from the command. ",
	          "");
	I_Method0(osg::Matrix, getMotionMatrix,
	          Properties::PURE_VIRTUAL,
	          __osg_Matrix__getMotionMatrix,
	          "Gets the matrix for transforming the Selection. ",
	          "This matrix is in the command's coordinate systems. ");
	I_Method2(void, setLocalToWorldAndWorldToLocal, IN, const osg::Matrix &, localToWorld, IN, const osg::Matrix &, worldToLocal,
	          Properties::NON_VIRTUAL,
	          __void__setLocalToWorldAndWorldToLocal__C5_osg_Matrix_R1__C5_osg_Matrix_R1,
	          "Sets the matrix for transforming the command's local coordinate system to the world/object coordinate system. ",
	          "");
	I_Method0(const osg::Matrix &, getLocalToWorld,
	          Properties::NON_VIRTUAL,
	          __C5_osg_Matrix_R1__getLocalToWorld,
	          "Gets the matrix for transforming the command's local coordinate system to the world/object coordinate system. ",
	          "");
	I_Method0(const osg::Matrix &, getWorldToLocal,
	          Properties::NON_VIRTUAL,
	          __C5_osg_Matrix_R1__getWorldToLocal,
	          "Gets the matrix for transforming the command's world/object coordinate system to the command's local coordinate system. ",
	          "");
	I_Method1(void, setStage, IN, const osgManipulator::MotionCommand::Stage, s,
	          Properties::NON_VIRTUAL,
	          __void__setStage__C5_Stage,
	          "",
	          "");
	I_Method0(osgManipulator::MotionCommand::Stage, getStage,
	          Properties::NON_VIRTUAL,
	          __Stage__getStage,
	          "",
	          "");


	I_SimpleProperty(const osg::Matrix &, LocalToWorld, 
	                 __C5_osg_Matrix_R1__getLocalToWorld, 
	                 0);
	I_SimpleProperty(osg::Matrix, MotionMatrix, 
	                 __osg_Matrix__getMotionMatrix, 
	                 0);
	I_SimpleProperty(osgManipulator::MotionCommand::Stage, Stage, 
	                 __Stage__getStage, 
	                 0);
	I_SimpleProperty(const osg::Matrix &, WorldToLocal, 
	                 __C5_osg_Matrix_R1__getWorldToLocal, 
	                 0);
END_REFLECTOR

BEGIN_OBJECT_REFLECTOR(osgManipulator::Rotate3DCommand)
	I_DeclaringFile("osgManipulator/Command");
	I_BaseType(osgManipulator::MotionCommand);
	I_Constructor0(____Rotate3DCommand,
	               "",
	               "");
	I_Method0(bool, execute,
	          Properties::VIRTUAL,
	          __bool__execute,
	          "Execute the command. ",
	          "");
	I_Method0(bool, unexecute,
	          Properties::VIRTUAL,
	          __bool__unexecute,
	          "Undo the command. ",
	          "The inverse of this command is executed. ");
	I_Method1(void, applyConstraint, IN, const osgManipulator::Constraint *, x,
	          Properties::VIRTUAL,
	          __void__applyConstraint__C5_Constraint_P1,
	          "Apply a constraint to the command. ",
	          "");
	I_Method1(void, setRotation, IN, const osg::Quat &, rotation,
	          Properties::NON_VIRTUAL,
	          __void__setRotation__C5_osg_Quat_R1,
	          "",
	          "");
	I_Method0(const osg::Quat &, getRotation,
	          Properties::NON_VIRTUAL,
	          __C5_osg_Quat_R1__getRotation,
	          "",
	          "");
	I_Method0(osg::Matrix, getMotionMatrix,
	          Properties::VIRTUAL,
	          __osg_Matrix__getMotionMatrix,
	          "Gets the matrix for transforming the Selection. ",
	          "This matrix is in the command's coordinate systems. ");
	I_SimpleProperty(osg::Matrix, MotionMatrix, 
	                 __osg_Matrix__getMotionMatrix, 
	                 0);
	I_SimpleProperty(const osg::Quat &, Rotation, 
	                 __C5_osg_Quat_R1__getRotation, 
	                 __void__setRotation__C5_osg_Quat_R1);
END_REFLECTOR

BEGIN_OBJECT_REFLECTOR(osgManipulator::Scale1DCommand)
	I_DeclaringFile("osgManipulator/Command");
	I_BaseType(osgManipulator::MotionCommand);
	I_Constructor0(____Scale1DCommand,
	               "",
	               "");
	I_Method0(bool, execute,
	          Properties::VIRTUAL,
	          __bool__execute,
	          "Execute the command. ",
	          "");
	I_Method0(bool, unexecute,
	          Properties::VIRTUAL,
	          __bool__unexecute,
	          "Undo the command. ",
	          "The inverse of this command is executed. ");
	I_Method1(void, applyConstraint, IN, const osgManipulator::Constraint *, x,
	          Properties::VIRTUAL,
	          __void__applyConstraint__C5_Constraint_P1,
	          "Apply a constraint to the command. ",
	          "");
	I_Method1(void, setScale, IN, float, s,
	          Properties::NON_VIRTUAL,
	          __void__setScale__float,
	          "",
	          "");
	I_Method0(float, getScale,
	          Properties::NON_VIRTUAL,
	          __float__getScale,
	          "",
	          "");
	I_Method1(void, setScaleCenter, IN, float, center,
	          Properties::NON_VIRTUAL,
	          __void__setScaleCenter__float,
	          "",
	          "");
	I_Method0(float, getScaleCenter,
	          Properties::NON_VIRTUAL,
	          __float__getScaleCenter,
	          "",
	          "");
	I_Method1(void, setReferencePoint, IN, float, rp,
	          Properties::NON_VIRTUAL,
	          __void__setReferencePoint__float,
	          "ReferencePoint is used only for snapping. ",
	          "");
	I_Method0(float, getReferencePoint,
	          Properties::NON_VIRTUAL,
	          __float__getReferencePoint,
	          "",
	          "");
	I_Method1(void, setMinScale, IN, float, min,
	          Properties::NON_VIRTUAL,
	          __void__setMinScale__float,
	          "",
	          "");
	I_Method0(float, getMinScale,
	          Properties::NON_VIRTUAL,
	          __float__getMinScale,
	          "",
	          "");
	I_Method0(osg::Matrix, getMotionMatrix,
	          Properties::VIRTUAL,
	          __osg_Matrix__getMotionMatrix,
	          "Gets the matrix for transforming the Selection. ",
	          "This matrix is in the command's coordinate systems. ");
	I_SimpleProperty(float, MinScale, 
	                 __float__getMinScale, 
	                 __void__setMinScale__float);
	I_SimpleProperty(osg::Matrix, MotionMatrix, 
	                 __osg_Matrix__getMotionMatrix, 
	                 0);
	I_SimpleProperty(float, ReferencePoint, 
	                 __float__getReferencePoint, 
	                 __void__setReferencePoint__float);
	I_SimpleProperty(float, Scale, 
	                 __float__getScale, 
	                 __void__setScale__float);
	I_SimpleProperty(float, ScaleCenter, 
	                 __float__getScaleCenter, 
	                 __void__setScaleCenter__float);
END_REFLECTOR

BEGIN_OBJECT_REFLECTOR(osgManipulator::Scale2DCommand)
	I_DeclaringFile("osgManipulator/Command");
	I_BaseType(osgManipulator::MotionCommand);
	I_Constructor0(____Scale2DCommand,
	               "",
	               "");
	I_Method0(bool, execute,
	          Properties::VIRTUAL,
	          __bool__execute,
	          "Execute the command. ",
	          "");
	I_Method0(bool, unexecute,
	          Properties::VIRTUAL,
	          __bool__unexecute,
	          "Undo the command. ",
	          "The inverse of this command is executed. ");
	I_Method1(void, applyConstraint, IN, const osgManipulator::Constraint *, x,
	          Properties::VIRTUAL,
	          __void__applyConstraint__C5_Constraint_P1,
	          "Apply a constraint to the command. ",
	          "");
	I_Method1(void, setScale, IN, const osg::Vec2 &, s,
	          Properties::NON_VIRTUAL,
	          __void__setScale__C5_osg_Vec2_R1,
	          "",
	          "");
	I_Method0(const osg::Vec2 &, getScale,
	          Properties::NON_VIRTUAL,
	          __C5_osg_Vec2_R1__getScale,
	          "",
	          "");
	I_Method1(void, setScaleCenter, IN, const osg::Vec2 &, center,
	          Properties::NON_VIRTUAL,
	          __void__setScaleCenter__C5_osg_Vec2_R1,
	          "",
	          "");
	I_Method0(const osg::Vec2 &, getScaleCenter,
	          Properties::NON_VIRTUAL,
	          __C5_osg_Vec2_R1__getScaleCenter,
	          "",
	          "");
	I_Method1(void, setReferencePoint, IN, const osg::Vec2 &, rp,
	          Properties::NON_VIRTUAL,
	          __void__setReferencePoint__C5_osg_Vec2_R1,
	          "ReferencePoint is used only for snapping. ",
	          "");
	I_Method0(const osg::Vec2 &, getReferencePoint,
	          Properties::NON_VIRTUAL,
	          __C5_osg_Vec2_R1__getReferencePoint,
	          "",
	          "");
	I_Method1(void, setMinScale, IN, const osg::Vec2 &, min,
	          Properties::NON_VIRTUAL,
	          __void__setMinScale__C5_osg_Vec2_R1,
	          "",
	          "");
	I_Method0(const osg::Vec2 &, getMinScale,
	          Properties::NON_VIRTUAL,
	          __C5_osg_Vec2_R1__getMinScale,
	          "",
	          "");
	I_Method0(osg::Matrix, getMotionMatrix,
	          Properties::VIRTUAL,
	          __osg_Matrix__getMotionMatrix,
	          "Gets the matrix for transforming the Selection. ",
	          "This matrix is in the command's coordinate systems. ");
	I_SimpleProperty(const osg::Vec2 &, MinScale, 
	                 __C5_osg_Vec2_R1__getMinScale, 
	                 __void__setMinScale__C5_osg_Vec2_R1);
	I_SimpleProperty(osg::Matrix, MotionMatrix, 
	                 __osg_Matrix__getMotionMatrix, 
	                 0);
	I_SimpleProperty(const osg::Vec2 &, ReferencePoint, 
	                 __C5_osg_Vec2_R1__getReferencePoint, 
	                 __void__setReferencePoint__C5_osg_Vec2_R1);
	I_SimpleProperty(const osg::Vec2 &, Scale, 
	                 __C5_osg_Vec2_R1__getScale, 
	                 __void__setScale__C5_osg_Vec2_R1);
	I_SimpleProperty(const osg::Vec2 &, ScaleCenter, 
	                 __C5_osg_Vec2_R1__getScaleCenter, 
	                 __void__setScaleCenter__C5_osg_Vec2_R1);
END_REFLECTOR

BEGIN_OBJECT_REFLECTOR(osgManipulator::ScaleUniformCommand)
	I_DeclaringFile("osgManipulator/Command");
	I_BaseType(osgManipulator::MotionCommand);
	I_Constructor0(____ScaleUniformCommand,
	               "",
	               "");
	I_Method0(bool, execute,
	          Properties::VIRTUAL,
	          __bool__execute,
	          "Execute the command. ",
	          "");
	I_Method0(bool, unexecute,
	          Properties::VIRTUAL,
	          __bool__unexecute,
	          "Undo the command. ",
	          "The inverse of this command is executed. ");
	I_Method1(void, applyConstraint, IN, const osgManipulator::Constraint *, x,
	          Properties::VIRTUAL,
	          __void__applyConstraint__C5_Constraint_P1,
	          "Apply a constraint to the command. ",
	          "");
	I_Method1(void, setScale, IN, float, s,
	          Properties::NON_VIRTUAL,
	          __void__setScale__float,
	          "",
	          "");
	I_Method0(float, getScale,
	          Properties::NON_VIRTUAL,
	          __float__getScale,
	          "",
	          "");
	I_Method1(void, setScaleCenter, IN, const osg::Vec3 &, center,
	          Properties::NON_VIRTUAL,
	          __void__setScaleCenter__C5_osg_Vec3_R1,
	          "",
	          "");
	I_Method0(const osg::Vec3 &, getScaleCenter,
	          Properties::NON_VIRTUAL,
	          __C5_osg_Vec3_R1__getScaleCenter,
	          "",
	          "");
	I_Method0(osg::Matrix, getMotionMatrix,
	          Properties::VIRTUAL,
	          __osg_Matrix__getMotionMatrix,
	          "Gets the matrix for transforming the Selection. ",
	          "This matrix is in the command's coordinate systems. ");
	I_SimpleProperty(osg::Matrix, MotionMatrix, 
	                 __osg_Matrix__getMotionMatrix, 
	                 0);
	I_SimpleProperty(float, Scale, 
	                 __float__getScale, 
	                 __void__setScale__float);
	I_SimpleProperty(const osg::Vec3 &, ScaleCenter, 
	                 __C5_osg_Vec3_R1__getScaleCenter, 
	                 __void__setScaleCenter__C5_osg_Vec3_R1);
END_REFLECTOR

BEGIN_OBJECT_REFLECTOR(osgManipulator::TranslateInLineCommand)
	I_DeclaringFile("osgManipulator/Command");
	I_BaseType(osgManipulator::MotionCommand);
	I_Constructor0(____TranslateInLineCommand,
	               "",
	               "");
	I_Constructor2(IN, const osg::LineSegment::vec_type &, s, IN, const osg::LineSegment::vec_type &, e,
	               ____TranslateInLineCommand__C5_osg_LineSegment_vec_type_R1__C5_osg_LineSegment_vec_type_R1,
	               "",
	               "");
	I_Method0(bool, execute,
	          Properties::VIRTUAL,
	          __bool__execute,
	          "Execute the command. ",
	          "");
	I_Method0(bool, unexecute,
	          Properties::VIRTUAL,
	          __bool__unexecute,
	          "Undo the command. ",
	          "The inverse of this command is executed. ");
	I_Method1(void, applyConstraint, IN, const osgManipulator::Constraint *, x,
	          Properties::VIRTUAL,
	          __void__applyConstraint__C5_Constraint_P1,
	          "Apply a constraint to the command. ",
	          "");
	I_Method2(void, setLine, IN, const osg::LineSegment::vec_type &, s, IN, const osg::LineSegment::vec_type &, e,
	          Properties::NON_VIRTUAL,
	          __void__setLine__C5_osg_LineSegment_vec_type_R1__C5_osg_LineSegment_vec_type_R1,
	          "",
	          "");
	I_Method0(const osg::LineSegment::vec_type &, getLineStart,
	          Properties::NON_VIRTUAL,
	          __C5_osg_LineSegment_vec_type_R1__getLineStart,
	          "",
	          "");
	I_Method0(const osg::LineSegment::vec_type &, getLineEnd,
	          Properties::NON_VIRTUAL,
	          __C5_osg_LineSegment_vec_type_R1__getLineEnd,
	          "",
	          "");
	I_Method1(void, setTranslation, IN, const osg::Vec3 &, t,
	          Properties::NON_VIRTUAL,
	          __void__setTranslation__C5_osg_Vec3_R1,
	          "",
	          "");
	I_Method0(const osg::Vec3 &, getTranslation,
	          Properties::NON_VIRTUAL,
	          __C5_osg_Vec3_R1__getTranslation,
	          "",
	          "");
	I_Method0(osg::Matrix, getMotionMatrix,
	          Properties::VIRTUAL,
	          __osg_Matrix__getMotionMatrix,
	          "Gets the matrix for transforming the Selection. ",
	          "This matrix is in the command's coordinate systems. ");
	I_SimpleProperty(const osg::LineSegment::vec_type &, LineEnd, 
	                 __C5_osg_LineSegment_vec_type_R1__getLineEnd, 
	                 0);
	I_SimpleProperty(const osg::LineSegment::vec_type &, LineStart, 
	                 __C5_osg_LineSegment_vec_type_R1__getLineStart, 
	                 0);
	I_SimpleProperty(osg::Matrix, MotionMatrix, 
	                 __osg_Matrix__getMotionMatrix, 
	                 0);
	I_SimpleProperty(const osg::Vec3 &, Translation, 
	                 __C5_osg_Vec3_R1__getTranslation, 
	                 __void__setTranslation__C5_osg_Vec3_R1);
END_REFLECTOR

BEGIN_OBJECT_REFLECTOR(osgManipulator::TranslateInPlaneCommand)
	I_DeclaringFile("osgManipulator/Command");
	I_BaseType(osgManipulator::MotionCommand);
	I_Constructor0(____TranslateInPlaneCommand,
	               "",
	               "");
	I_Constructor1(IN, const osg::Plane &, plane,
	               Properties::NON_EXPLICIT,
	               ____TranslateInPlaneCommand__C5_osg_Plane_R1,
	               "",
	               "");
	I_Method0(bool, execute,
	          Properties::VIRTUAL,
	          __bool__execute,
	          "Execute the command. ",
	          "");
	I_Method0(bool, unexecute,
	          Properties::VIRTUAL,
	          __bool__unexecute,
	          "Undo the command. ",
	          "The inverse of this command is executed. ");
	I_Method1(void, applyConstraint, IN, const osgManipulator::Constraint *, x,
	          Properties::VIRTUAL,
	          __void__applyConstraint__C5_Constraint_P1,
	          "Apply a constraint to the command. ",
	          "");
	I_Method1(void, setPlane, IN, const osg::Plane &, plane,
	          Properties::NON_VIRTUAL,
	          __void__setPlane__C5_osg_Plane_R1,
	          "",
	          "");
	I_Method0(const osg::Plane &, getPlane,
	          Properties::NON_VIRTUAL,
	          __C5_osg_Plane_R1__getPlane,
	          "",
	          "");
	I_Method1(void, setTranslation, IN, const osg::Vec3 &, t,
	          Properties::NON_VIRTUAL,
	          __void__setTranslation__C5_osg_Vec3_R1,
	          "",
	          "");
	I_Method0(const osg::Vec3 &, getTranslation,
	          Properties::NON_VIRTUAL,
	          __C5_osg_Vec3_R1__getTranslation,
	          "",
	          "");
	I_Method1(void, setReferencePoint, IN, const osg::Vec3 &, rp,
	          Properties::NON_VIRTUAL,
	          __void__setReferencePoint__C5_osg_Vec3_R1,
	          "ReferencePoint is used only for snapping. ",
	          "");
	I_Method0(const osg::Vec3 &, getReferencePoint,
	          Properties::NON_VIRTUAL,
	          __C5_osg_Vec3_R1__getReferencePoint,
	          "",
	          "");
	I_Method0(osg::Matrix, getMotionMatrix,
	          Properties::VIRTUAL,
	          __osg_Matrix__getMotionMatrix,
	          "Gets the matrix for transforming the Selection. ",
	          "This matrix is in the command's coordinate systems. ");
	I_SimpleProperty(osg::Matrix, MotionMatrix, 
	                 __osg_Matrix__getMotionMatrix, 
	                 0);
	I_SimpleProperty(const osg::Plane &, Plane, 
	                 __C5_osg_Plane_R1__getPlane, 
	                 __void__setPlane__C5_osg_Plane_R1);
	I_SimpleProperty(const osg::Vec3 &, ReferencePoint, 
	                 __C5_osg_Vec3_R1__getReferencePoint, 
	                 __void__setReferencePoint__C5_osg_Vec3_R1);
	I_SimpleProperty(const osg::Vec3 &, Translation, 
	                 __C5_osg_Vec3_R1__getTranslation, 
	                 __void__setTranslation__C5_osg_Vec3_R1);
END_REFLECTOR
