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

#include <osg/ApplicationUsage>
#include <osg/PolygonMode>
#include <osg/StateSet>
#include <osgGA/GUIActionAdapter>
#include <osgGA/GUIEventAdapter>
#include <osgGA/StateSetManipulator>

// Must undefine IN and OUT macros defined in Windows headers
#ifdef IN
#undef IN
#endif
#ifdef OUT
#undef OUT
#endif

BEGIN_OBJECT_REFLECTOR(osgGA::StateSetManipulator)
	I_DeclaringFile("osgGA/StateSetManipulator");
	I_BaseType(osgGA::GUIEventHandler);
	I_ConstructorWithDefaults1(IN, osg::StateSet *, stateset, 0,
	                           Properties::NON_EXPLICIT,
	                           ____StateSetManipulator__osg_StateSet_P1,
	                           "",
	                           "");
	I_Method0(const char *, className,
	          Properties::VIRTUAL,
	          __C5_char_P1__className,
	          "return the name of the object's class type. ",
	          "Must be defined by derived classes. ");
	I_Method1(void, setStateSet, IN, osg::StateSet *, x,
	          Properties::VIRTUAL,
	          __void__setStateSet__osg_StateSet_P1,
	          "attach a StateSet to the manipulator to be used for specifying view. ",
	          "");
	I_Method0(osg::StateSet *, getStateSet,
	          Properties::VIRTUAL,
	          __osg_StateSet_P1__getStateSet,
	          "get the attached a StateSet. ",
	          "");
	I_Method0(const osg::StateSet *, getStateSet,
	          Properties::VIRTUAL,
	          __C5_osg_StateSet_P1__getStateSet,
	          "get the attached a StateSet. ",
	          "");
	I_Method2(bool, handle, IN, const osgGA::GUIEventAdapter &, ea, IN, osgGA::GUIActionAdapter &, us,
	          Properties::VIRTUAL,
	          __bool__handle__C5_GUIEventAdapter_R1__GUIActionAdapter_R1,
	          "Handle events, return true if handled, false otherwise. ",
	          "");
	I_Method1(void, getUsage, IN, osg::ApplicationUsage &, usage,
	          Properties::VIRTUAL,
	          __void__getUsage__osg_ApplicationUsage_R1,
	          "Get the keyboard and mouse usage of this manipulator. ",
	          "");
	I_Method1(void, setMaximumNumOfTextureUnits, IN, unsigned int, i,
	          Properties::NON_VIRTUAL,
	          __void__setMaximumNumOfTextureUnits__unsigned_int,
	          "",
	          "");
	I_Method0(unsigned int, getMaximumNumOfTextureUnits,
	          Properties::NON_VIRTUAL,
	          __unsigned_int__getMaximumNumOfTextureUnits,
	          "",
	          "");
	I_Method1(void, setBackfaceEnabled, IN, bool, newbackface,
	          Properties::NON_VIRTUAL,
	          __void__setBackfaceEnabled__bool,
	          "",
	          "");
	I_Method0(bool, getBackfaceEnabled,
	          Properties::NON_VIRTUAL,
	          __bool__getBackfaceEnabled,
	          "",
	          "");
	I_Method1(void, setLightingEnabled, IN, bool, newlighting,
	          Properties::NON_VIRTUAL,
	          __void__setLightingEnabled__bool,
	          "",
	          "");
	I_Method0(bool, getLightingEnabled,
	          Properties::NON_VIRTUAL,
	          __bool__getLightingEnabled,
	          "",
	          "");
	I_Method1(void, setTextureEnabled, IN, bool, newtexture,
	          Properties::NON_VIRTUAL,
	          __void__setTextureEnabled__bool,
	          "",
	          "");
	I_Method0(bool, getTextureEnabled,
	          Properties::NON_VIRTUAL,
	          __bool__getTextureEnabled,
	          "",
	          "");
	I_Method1(void, setPolygonMode, IN, osg::PolygonMode::Mode, newpolygonmode,
	          Properties::NON_VIRTUAL,
	          __void__setPolygonMode__osg_PolygonMode_Mode,
	          "",
	          "");
	I_Method0(osg::PolygonMode::Mode, getPolygonMode,
	          Properties::NON_VIRTUAL,
	          __osg_PolygonMode_Mode__getPolygonMode,
	          "",
	          "");
	I_Method0(void, cyclePolygonMode,
	          Properties::NON_VIRTUAL,
	          __void__cyclePolygonMode,
	          "",
	          "");
	I_Method1(void, setKeyEventToggleBackfaceCulling, IN, int, key,
	          Properties::NON_VIRTUAL,
	          __void__setKeyEventToggleBackfaceCulling__int,
	          "",
	          "");
	I_Method0(int, getKeyEventToggleBackfaceCulling,
	          Properties::NON_VIRTUAL,
	          __int__getKeyEventToggleBackfaceCulling,
	          "",
	          "");
	I_Method1(void, setKeyEventToggleLighting, IN, int, key,
	          Properties::NON_VIRTUAL,
	          __void__setKeyEventToggleLighting__int,
	          "",
	          "");
	I_Method0(int, getKeyEventToggleLighting,
	          Properties::NON_VIRTUAL,
	          __int__getKeyEventToggleLighting,
	          "",
	          "");
	I_Method1(void, setKeyEventToggleTexturing, IN, int, key,
	          Properties::NON_VIRTUAL,
	          __void__setKeyEventToggleTexturing__int,
	          "",
	          "");
	I_Method0(int, getKeyEventToggleTexturing,
	          Properties::NON_VIRTUAL,
	          __int__getKeyEventToggleTexturing,
	          "",
	          "");
	I_Method1(void, setKeyEventCyclePolygonMode, IN, int, key,
	          Properties::NON_VIRTUAL,
	          __void__setKeyEventCyclePolygonMode__int,
	          "",
	          "");
	I_Method0(int, getKeyEventCyclePolygonMode,
	          Properties::NON_VIRTUAL,
	          __int__getKeyEventCyclePolygonMode,
	          "",
	          "");
	I_ProtectedMethod0(void, clone,
	                   Properties::NON_VIRTUAL,
	                   Properties::NON_CONST,
	                   __void__clone,
	                   "",
	                   "");
	I_ProtectedMethod0(osg::PolygonMode *, getOrCreatePolygonMode,
	                   Properties::NON_VIRTUAL,
	                   Properties::NON_CONST,
	                   __osg_PolygonMode_P1__getOrCreatePolygonMode,
	                   "",
	                   "");
	I_SimpleProperty(bool, BackfaceEnabled, 
	                 __bool__getBackfaceEnabled, 
	                 __void__setBackfaceEnabled__bool);
	I_SimpleProperty(int, KeyEventCyclePolygonMode, 
	                 __int__getKeyEventCyclePolygonMode, 
	                 __void__setKeyEventCyclePolygonMode__int);
	I_SimpleProperty(int, KeyEventToggleBackfaceCulling, 
	                 __int__getKeyEventToggleBackfaceCulling, 
	                 __void__setKeyEventToggleBackfaceCulling__int);
	I_SimpleProperty(int, KeyEventToggleLighting, 
	                 __int__getKeyEventToggleLighting, 
	                 __void__setKeyEventToggleLighting__int);
	I_SimpleProperty(int, KeyEventToggleTexturing, 
	                 __int__getKeyEventToggleTexturing, 
	                 __void__setKeyEventToggleTexturing__int);
	I_SimpleProperty(bool, LightingEnabled, 
	                 __bool__getLightingEnabled, 
	                 __void__setLightingEnabled__bool);
	I_SimpleProperty(unsigned int, MaximumNumOfTextureUnits, 
	                 __unsigned_int__getMaximumNumOfTextureUnits, 
	                 __void__setMaximumNumOfTextureUnits__unsigned_int);
	I_SimpleProperty(osg::PolygonMode::Mode, PolygonMode, 
	                 __osg_PolygonMode_Mode__getPolygonMode, 
	                 __void__setPolygonMode__osg_PolygonMode_Mode);
	I_SimpleProperty(osg::StateSet *, StateSet, 
	                 __osg_StateSet_P1__getStateSet, 
	                 __void__setStateSet__osg_StateSet_P1);
	I_SimpleProperty(bool, TextureEnabled, 
	                 __bool__getTextureEnabled, 
	                 __void__setTextureEnabled__bool);
END_REFLECTOR

