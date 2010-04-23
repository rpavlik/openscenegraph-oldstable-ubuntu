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

#include <osg/CopyOp>
#include <osg/Object>
#include <osg/RenderInfo>
#include <osgText/FadeText>
#include <osgText/Text>

// Must undefine IN and OUT macros defined in Windows headers
#ifdef IN
#undef IN
#endif
#ifdef OUT
#undef OUT
#endif

BEGIN_OBJECT_REFLECTOR(osgText::FadeText)
	I_DeclaringFile("osgText/FadeText");
	I_BaseType(osgText::Text);
	I_Constructor0(____FadeText,
	               "",
	               "");
	I_ConstructorWithDefaults2(IN, const osgText::Text &, text, , IN, const osg::CopyOp &, copyop, osg::CopyOp::SHALLOW_COPY,
	                           ____FadeText__C5_Text_R1__C5_osg_CopyOp_R1,
	                           "",
	                           "");
	I_Method0(osg::Object *, cloneType,
	          Properties::VIRTUAL,
	          __osg_Object_P1__cloneType,
	          "Clone the type of an object, with Object* return type. ",
	          "Must be defined by derived classes. ");
	I_Method1(osg::Object *, clone, IN, const osg::CopyOp &, copyop,
	          Properties::VIRTUAL,
	          __osg_Object_P1__clone__C5_osg_CopyOp_R1,
	          "Clone an object, with Object* return type. ",
	          "Must be defined by derived classes. ");
	I_Method1(bool, isSameKindAs, IN, const osg::Object *, obj,
	          Properties::VIRTUAL,
	          __bool__isSameKindAs__C5_osg_Object_P1,
	          "",
	          "");
	I_Method0(const char *, libraryName,
	          Properties::VIRTUAL,
	          __C5_char_P1__libraryName,
	          "return the name of the object's library. ",
	          "Must be defined by derived classes. The OpenSceneGraph convention is that the namespace of a library is the same as the library name. ");
	I_Method0(const char *, className,
	          Properties::VIRTUAL,
	          __C5_char_P1__className,
	          "return the name of the object's class type. ",
	          "Must be defined by derived classes. ");
	I_Method1(void, setFadeSpeed, IN, float, fadeSpeed,
	          Properties::NON_VIRTUAL,
	          __void__setFadeSpeed__float,
	          "Set the speed that the alpha value changes as the text is occluded or becomes visible. ",
	          "");
	I_Method0(float, getFadeSpeed,
	          Properties::NON_VIRTUAL,
	          __float__getFadeSpeed,
	          "Get the speed that the alpha value changes. ",
	          "");
	I_Method1(void, drawImplementation, IN, osg::RenderInfo &, renderInfo,
	          Properties::VIRTUAL,
	          __void__drawImplementation__osg_RenderInfo_R1,
	          "Draw the text. ",
	          "");
	I_ProtectedMethod0(void, init,
	                   Properties::NON_VIRTUAL,
	                   Properties::NON_CONST,
	                   __void__init,
	                   "",
	                   "");


	I_SimpleProperty(float, FadeSpeed, 
	                 __float__getFadeSpeed, 
	                 __void__setFadeSpeed__float);
END_REFLECTOR

