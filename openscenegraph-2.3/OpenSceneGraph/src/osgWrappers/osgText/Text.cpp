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
#include <osg/Drawable>
#include <osg/Object>
#include <osg/PrimitiveSet>
#include <osg/RenderInfo>
#include <osg/State>
#include <osg/Vec4>
#include <osgText/Font>
#include <osgText/Text>

// Must undefine IN and OUT macros defined in Windows headers
#ifdef IN
#undef IN
#endif
#ifdef OUT
#undef OUT
#endif

TYPE_NAME_ALIAS(std::map< osg::ref_ptr< osgText::Font::GlyphTexture > COMMA  osgText::Text::GlyphQuads >, osgText::Text::TextureGlyphQuadMap)

BEGIN_ENUM_REFLECTOR(osgText::Text::BackdropType)
	I_DeclaringFile("osgText/Text");
	I_EnumLabel(osgText::Text::DROP_SHADOW_BOTTOM_RIGHT);
	I_EnumLabel(osgText::Text::DROP_SHADOW_CENTER_RIGHT);
	I_EnumLabel(osgText::Text::DROP_SHADOW_TOP_RIGHT);
	I_EnumLabel(osgText::Text::DROP_SHADOW_BOTTOM_CENTER);
	I_EnumLabel(osgText::Text::DROP_SHADOW_TOP_CENTER);
	I_EnumLabel(osgText::Text::DROP_SHADOW_BOTTOM_LEFT);
	I_EnumLabel(osgText::Text::DROP_SHADOW_CENTER_LEFT);
	I_EnumLabel(osgText::Text::DROP_SHADOW_TOP_LEFT);
	I_EnumLabel(osgText::Text::OUTLINE);
	I_EnumLabel(osgText::Text::NONE);
END_REFLECTOR

BEGIN_ENUM_REFLECTOR(osgText::Text::BackdropImplementation)
	I_DeclaringFile("osgText/Text");
	I_EnumLabel(osgText::Text::POLYGON_OFFSET);
	I_EnumLabel(osgText::Text::NO_DEPTH_BUFFER);
	I_EnumLabel(osgText::Text::DEPTH_RANGE);
	I_EnumLabel(osgText::Text::STENCIL_BUFFER);
END_REFLECTOR

BEGIN_ENUM_REFLECTOR(osgText::Text::ColorGradientMode)
	I_DeclaringFile("osgText/Text");
	I_EnumLabel(osgText::Text::SOLID);
	I_EnumLabel(osgText::Text::PER_CHARACTER);
	I_EnumLabel(osgText::Text::OVERALL);
END_REFLECTOR

BEGIN_OBJECT_REFLECTOR(osgText::Text)
	I_DeclaringFile("osgText/Text");
	I_BaseType(osgText::TextBase);
	I_Constructor0(____Text,
	               "",
	               "");
	I_ConstructorWithDefaults2(IN, const osgText::Text &, text, , IN, const osg::CopyOp &, copyop, osg::CopyOp::SHALLOW_COPY,
	                           ____Text__C5_Text_R1__C5_osg_CopyOp_R1,
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
	I_Method0(const char *, className,
	          Properties::VIRTUAL,
	          __C5_char_P1__className,
	          "return the name of the object's class type. ",
	          "Must be defined by derived classes. ");
	I_Method0(const char *, libraryName,
	          Properties::VIRTUAL,
	          __C5_char_P1__libraryName,
	          "return the name of the object's library. ",
	          "Must be defined by derived classes. The OpenSceneGraph convention is that the namespace of a library is the same as the library name. ");
	I_MethodWithDefaults1(void, setFont, IN, osgText::Font *, font, 0,
	                      Properties::NON_VIRTUAL,
	                      __void__setFont__Font_P1,
	                      "Set the Font to use to render the text. ",
	                      "setFont(0) sets the use of the default font. ");
	I_Method1(void, setFont, IN, osg::ref_ptr< osgText::Font >, font,
	          Properties::NON_VIRTUAL,
	          __void__setFont__osg_ref_ptrT1_Font_,
	          "Set the Font to use to render the text. ",
	          "");
	I_Method1(void, setFont, IN, const std::string &, fontfile,
	          Properties::NON_VIRTUAL,
	          __void__setFont__C5_std_string_R1,
	          "Set the font, loaded from the specified front file, to use to render the text, setFont(\"\") sets the use of the default font. ",
	          "See the osgText::readFontFile function for how the font file will be located. ");
	I_Method0(const osgText::Font *, getFont,
	          Properties::NON_VIRTUAL,
	          __C5_Font_P1__getFont,
	          "Get the font. ",
	          "Return 0 if default is being used. ");
	I_Method1(void, setColor, IN, const osg::Vec4 &, color,
	          Properties::NON_VIRTUAL,
	          __void__setColor__C5_osg_Vec4_R1,
	          "",
	          "");
	I_Method0(const osg::Vec4 &, getColor,
	          Properties::NON_VIRTUAL,
	          __C5_osg_Vec4_R1__getColor,
	          "",
	          "");
	I_Method1(void, setBackdropType, IN, osgText::Text::BackdropType, type,
	          Properties::NON_VIRTUAL,
	          __void__setBackdropType__BackdropType,
	          "BackdropType gives you a background shadow text behind your regular text. ",
	          "This helps give text extra contrast which can be useful when placing text against noisy backgrounds. The color of the background shadow text is specified by setBackdropColor(). DROP_SHADOW_BOTTOM_RIGHT will draw backdrop text to the right and down of the normal text. Other DROW_SHADOW_* modes do the same for their repective directions. OUTLINE will draw backdrop text so that it appears the text has an outline or border around the normal text. This mode is particularly useful against really noisy backgrounds that may put text on top of things that have all types of colors which you don't have control over. Some real world examples of this general technique in use that I know of are Google Earth, Sid Meier's Pirates (2004 Remake), and Star Control 2 (PC 1993). The default is NONE. ");
	I_Method0(osgText::Text::BackdropType, getBackdropType,
	          Properties::NON_VIRTUAL,
	          __BackdropType__getBackdropType,
	          "",
	          "");
	I_MethodWithDefaults1(void, setBackdropOffset, IN, float, offset, 0.07f,
	                      Properties::NON_VIRTUAL,
	                      __void__setBackdropOffset__float,
	                      "Sets the amount text is offset to create the backdrop/shadow effect. ",
	                      "Set the value too high and for example, in OUTLINE mode you will get a \"Brady Bunch\" effect where you see duplicates of the text in a 3x3 grid. Set the value too small and you won't see anything. The values represent percentages. 1.0 means 100% so a value of 1.0 in DROW_SHADOW_LEFT_CENTER mode would cause each glyph to be echoed next to it self. So the letter 'e' might look like 'ee'. Good values tend to be in the 0.03 to 0.10 range (but will be subject to your specific font and display characteristics). Note that the text bounding boxes are updated to include backdrop offsets. However, other metric information such as getCharacterHeight() are unaffected by this. This means that individual glyph spacing (kerning?) are unchanged even when this mode is used. The default is 0.07 (7% offset). ");
	I_Method2(void, setBackdropOffset, IN, float, horizontal, IN, float, vertical,
	          Properties::NON_VIRTUAL,
	          __void__setBackdropOffset__float__float,
	          "This overloaded version lets you specify the offset for the horizontal and vertical components separately. ",
	          "");
	I_Method0(float, getBackdropHorizontalOffset,
	          Properties::NON_VIRTUAL,
	          __float__getBackdropHorizontalOffset,
	          "",
	          "");
	I_Method0(float, getBackdropVerticalOffset,
	          Properties::NON_VIRTUAL,
	          __float__getBackdropVerticalOffset,
	          "",
	          "");
	I_Method1(void, setBackdropColor, IN, const osg::Vec4 &, color,
	          Properties::NON_VIRTUAL,
	          __void__setBackdropColor__C5_osg_Vec4_R1,
	          "This specifies the color of the backdrop text. ",
	          "The default is black. ");
	I_Method0(const osg::Vec4 &, getBackdropColor,
	          Properties::NON_VIRTUAL,
	          __C5_osg_Vec4_R1__getBackdropColor,
	          "",
	          "");
	I_Method1(void, setBackdropImplementation, IN, osgText::Text::BackdropImplementation, implementation,
	          Properties::NON_VIRTUAL,
	          __void__setBackdropImplementation__BackdropImplementation,
	          "This specifies the underlying backdrop rendering implementation. ",
	          "Unfortunately, at this time, there is no \"perfect\" rendering solution so this function is provided to let you 'pick your poison'. Each implementation has trade-offs. See BackdropImplementation enum docs for details. ");
	I_Method0(osgText::Text::BackdropImplementation, getBackdropImplementation,
	          Properties::NON_VIRTUAL,
	          __BackdropImplementation__getBackdropImplementation,
	          "",
	          "");
	I_Method1(void, setColorGradientMode, IN, osgText::Text::ColorGradientMode, mode,
	          Properties::NON_VIRTUAL,
	          __void__setColorGradientMode__ColorGradientMode,
	          "This sets different types of text coloring modes. ",
	          "When the coloring mode is not set to SOLID, the colors specified in setColorGradientCorners() determine the colors for the text. When the gradient mode is OVERALL, the coloring scheme attempts to approximate the effect as if the entire text box/region were a single polygon and you had applied colors to each of the four corners with GL_SMOOTH enabled. In this mode, OpenGL interpolates the colors across the polygon, and this is what OVERALL tries to emulate. This can be used to give nice embellishments on things like logos and names. PER_CHARACTER is similar to OVERALL except that it applies the color interpolation to the four corners of each character instead of across the overall text box. The default is SOLID (a.k.a. off). ");
	I_Method0(osgText::Text::ColorGradientMode, getColorGradientMode,
	          Properties::NON_VIRTUAL,
	          __ColorGradientMode__getColorGradientMode,
	          "",
	          "");
	I_Method4(void, setColorGradientCorners, IN, const osg::Vec4 &, topLeft, IN, const osg::Vec4 &, bottomLeft, IN, const osg::Vec4 &, bottomRight, IN, const osg::Vec4 &, topRight,
	          Properties::NON_VIRTUAL,
	          __void__setColorGradientCorners__C5_osg_Vec4_R1__C5_osg_Vec4_R1__C5_osg_Vec4_R1__C5_osg_Vec4_R1,
	          "Used only for gradient mode, let's you specify the colors of the 4 corners. ",
	          "If ColorGradients are off, these values are ignored (and the value from setColor() is the only one that is relevant. ");
	I_Method0(const osg::Vec4 &, getColorGradientTopLeft,
	          Properties::NON_VIRTUAL,
	          __C5_osg_Vec4_R1__getColorGradientTopLeft,
	          "",
	          "");
	I_Method0(const osg::Vec4 &, getColorGradientBottomLeft,
	          Properties::NON_VIRTUAL,
	          __C5_osg_Vec4_R1__getColorGradientBottomLeft,
	          "",
	          "");
	I_Method0(const osg::Vec4 &, getColorGradientBottomRight,
	          Properties::NON_VIRTUAL,
	          __C5_osg_Vec4_R1__getColorGradientBottomRight,
	          "",
	          "");
	I_Method0(const osg::Vec4 &, getColorGradientTopRight,
	          Properties::NON_VIRTUAL,
	          __C5_osg_Vec4_R1__getColorGradientTopRight,
	          "",
	          "");
	I_Method1(void, drawImplementation, IN, osg::RenderInfo &, renderInfo,
	          Properties::VIRTUAL,
	          __void__drawImplementation__osg_RenderInfo_R1,
	          "Draw the text. ",
	          "");
	I_Method1(bool, supports, IN, const osg::Drawable::AttributeFunctor &, x,
	          Properties::VIRTUAL,
	          __bool__supports__C5_osg_Drawable_AttributeFunctor_R1,
	          "return false, osgText::Text does not support accept(AttributeFunctor&). ",
	          "");
	I_Method1(bool, supports, IN, const osg::Drawable::ConstAttributeFunctor &, x,
	          Properties::VIRTUAL,
	          __bool__supports__C5_osg_Drawable_ConstAttributeFunctor_R1,
	          "return true, osgText::Text does support accept(ConstAttributeFunctor&). ",
	          "");
	I_Method1(void, accept, IN, osg::Drawable::ConstAttributeFunctor &, af,
	          Properties::VIRTUAL,
	          __void__accept__osg_Drawable_ConstAttributeFunctor_R1,
	          "accept an ConstAttributeFunctor and call its methods to tell it about the internal attributes that this Drawable has. ",
	          "");
	I_Method1(bool, supports, IN, const osg::PrimitiveFunctor &, x,
	          Properties::VIRTUAL,
	          __bool__supports__C5_osg_PrimitiveFunctor_R1,
	          "return true, osgText::Text does support accept(PrimitiveFunctor&) . ",
	          "");
	I_Method1(void, accept, IN, osg::PrimitiveFunctor &, pf,
	          Properties::VIRTUAL,
	          __void__accept__osg_PrimitiveFunctor_R1,
	          "accept a PrimtiveFunctor and call its methods to tell it about the internal primitives that this Drawable has. ",
	          "");
	I_Method1(void, setThreadSafeRefUnref, IN, bool, threadSafe,
	          Properties::VIRTUAL,
	          __void__setThreadSafeRefUnref__bool,
	          "Set whether to use a mutex to ensure ref() and unref() are thread safe. ",
	          "");
	I_Method1(void, resizeGLObjectBuffers, IN, unsigned int, maxSize,
	          Properties::VIRTUAL,
	          __void__resizeGLObjectBuffers__unsigned_int,
	          "Resize any per context GLObject buffers to specified size. ",
	          "");
	I_MethodWithDefaults1(void, releaseGLObjects, IN, osg::State *, state, 0,
	                      Properties::VIRTUAL,
	                      __void__releaseGLObjects__osg_State_P1,
	                      "If State is non-zero, this function releases OpenGL objects for the specified graphics context. ",
	                      "Otherwise, releases OpenGL objexts for all graphics contexts. ");
	I_Method1(const osgText::Text::GlyphQuads *, getGlyphQuads, IN, osgText::Font::GlyphTexture *, texture,
	          Properties::NON_VIRTUAL,
	          __C5_GlyphQuads_P1__getGlyphQuads__Font_GlyphTexture_P1,
	          "Direct Access to GlyphQuads. ",
	          "");
	I_Method0(const osgText::Text::TextureGlyphQuadMap &, getTextureGlyphQuadMap,
	          Properties::NON_VIRTUAL,
	          __C5_TextureGlyphQuadMap_R1__getTextureGlyphQuadMap,
	          "",
	          "");
	I_ProtectedMethod0(osgText::Font *, getActiveFont,
	                   Properties::NON_VIRTUAL,
	                   Properties::NON_CONST,
	                   __Font_P1__getActiveFont,
	                   "",
	                   "");
	I_ProtectedMethod0(const osgText::Font *, getActiveFont,
	                   Properties::NON_VIRTUAL,
	                   Properties::CONST,
	                   __C5_Font_P1__getActiveFont,
	                   "",
	                   "");
	I_ProtectedMethod3(osgText::String::iterator, computeLastCharacterOnLine, IN, osg::Vec2 &, cursor, IN, osgText::String::iterator, first, IN, osgText::String::iterator, last,
	                   Properties::NON_VIRTUAL,
	                   Properties::NON_CONST,
	                   __String_iterator__computeLastCharacterOnLine__osg_Vec2_R1__String_iterator__String_iterator,
	                   "",
	                   "");
	I_ProtectedMethod0(void, computeGlyphRepresentation,
	                   Properties::VIRTUAL,
	                   Properties::NON_CONST,
	                   __void__computeGlyphRepresentation,
	                   "",
	                   "");
	I_ProtectedMethod2(bool, computeAverageGlyphWidthAndHeight, IN, float &, avg_width, IN, float &, avg_height,
	                   Properties::NON_VIRTUAL,
	                   Properties::CONST,
	                   __bool__computeAverageGlyphWidthAndHeight__float_R1__float_R1,
	                   "",
	                   "");
	I_ProtectedMethod1(void, computePositions, IN, unsigned int, contextID,
	                   Properties::VIRTUAL,
	                   Properties::CONST,
	                   __void__computePositions__unsigned_int,
	                   "",
	                   "");
	I_ProtectedMethod1(void, computeBackdropPositions, IN, unsigned int, contextID,
	                   Properties::NON_VIRTUAL,
	                   Properties::CONST,
	                   __void__computeBackdropPositions__unsigned_int,
	                   "",
	                   "");
	I_ProtectedMethod0(void, computeBackdropBoundingBox,
	                   Properties::NON_VIRTUAL,
	                   Properties::CONST,
	                   __void__computeBackdropBoundingBox,
	                   "",
	                   "");
	I_ProtectedMethod0(void, computeColorGradients,
	                   Properties::NON_VIRTUAL,
	                   Properties::CONST,
	                   __void__computeColorGradients,
	                   "",
	                   "");
	I_ProtectedMethod0(void, computeColorGradientsOverall,
	                   Properties::NON_VIRTUAL,
	                   Properties::CONST,
	                   __void__computeColorGradientsOverall,
	                   "",
	                   "");
	I_ProtectedMethod0(void, computeColorGradientsPerCharacter,
	                   Properties::NON_VIRTUAL,
	                   Properties::CONST,
	                   __void__computeColorGradientsPerCharacter,
	                   "",
	                   "");
	I_ProtectedMethod2(void, drawImplementation, IN, osg::State &, state, IN, const osg::Vec4 &, colorMultiplier,
	                   Properties::NON_VIRTUAL,
	                   Properties::CONST,
	                   __void__drawImplementation__osg_State_R1__C5_osg_Vec4_R1,
	                   "",
	                   "");
	I_ProtectedMethod3(void, drawForegroundText, IN, osg::State &, state, IN, const osgText::Text::GlyphQuads &, glyphquad, IN, const osg::Vec4 &, colorMultiplier,
	                   Properties::NON_VIRTUAL,
	                   Properties::CONST,
	                   __void__drawForegroundText__osg_State_R1__C5_GlyphQuads_R1__C5_osg_Vec4_R1,
	                   "",
	                   "");
	I_ProtectedMethod2(void, renderOnlyForegroundText, IN, osg::State &, state, IN, const osg::Vec4 &, colorMultiplier,
	                   Properties::NON_VIRTUAL,
	                   Properties::CONST,
	                   __void__renderOnlyForegroundText__osg_State_R1__C5_osg_Vec4_R1,
	                   "",
	                   "");
	I_ProtectedMethod2(void, renderWithPolygonOffset, IN, osg::State &, state, IN, const osg::Vec4 &, colorMultiplier,
	                   Properties::NON_VIRTUAL,
	                   Properties::CONST,
	                   __void__renderWithPolygonOffset__osg_State_R1__C5_osg_Vec4_R1,
	                   "",
	                   "");
	I_ProtectedMethod2(void, renderWithNoDepthBuffer, IN, osg::State &, state, IN, const osg::Vec4 &, colorMultiplier,
	                   Properties::NON_VIRTUAL,
	                   Properties::CONST,
	                   __void__renderWithNoDepthBuffer__osg_State_R1__C5_osg_Vec4_R1,
	                   "",
	                   "");
	I_ProtectedMethod2(void, renderWithDepthRange, IN, osg::State &, state, IN, const osg::Vec4 &, colorMultiplier,
	                   Properties::NON_VIRTUAL,
	                   Properties::CONST,
	                   __void__renderWithDepthRange__osg_State_R1__C5_osg_Vec4_R1,
	                   "",
	                   "");
	I_ProtectedMethod2(void, renderWithStencilBuffer, IN, osg::State &, state, IN, const osg::Vec4 &, colorMultiplier,
	                   Properties::NON_VIRTUAL,
	                   Properties::CONST,
	                   __void__renderWithStencilBuffer__osg_State_R1__C5_osg_Vec4_R1,
	                   "",
	                   "");
	I_ProtectedMethod10(float, bilinearInterpolate, IN, float, x1, IN, float, x2, IN, float, y1, IN, float, y2, IN, float, x, IN, float, y, IN, float, q11, IN, float, q12, IN, float, q21, IN, float, q22,
	                    Properties::NON_VIRTUAL,
	                    Properties::CONST,
	                    __float__bilinearInterpolate__float__float__float__float__float__float__float__float__float__float,
	                    "",
	                    "");
	I_ProtectedMethod2(void, convertHsvToRgb, IN, float, hsv, IN, float, rgb,
	                   Properties::NON_VIRTUAL,
	                   Properties::CONST,
	                   __void__convertHsvToRgb__float__float,
	                   "",
	                   "");
	I_ProtectedMethod2(void, convertRgbToHsv, IN, float, rgb, IN, float, hsv,
	                   Properties::NON_VIRTUAL,
	                   Properties::CONST,
	                   __void__convertRgbToHsv__float__float,
	                   "",
	                   "");
	I_SimpleProperty(const osg::Vec4 &, BackdropColor, 
	                 __C5_osg_Vec4_R1__getBackdropColor, 
	                 __void__setBackdropColor__C5_osg_Vec4_R1);
	I_SimpleProperty(float, BackdropHorizontalOffset, 
	                 __float__getBackdropHorizontalOffset, 
	                 0);
	I_SimpleProperty(osgText::Text::BackdropImplementation, BackdropImplementation, 
	                 __BackdropImplementation__getBackdropImplementation, 
	                 __void__setBackdropImplementation__BackdropImplementation);
	I_SimpleProperty(float, BackdropOffset, 
	                 0, 
	                 __void__setBackdropOffset__float);
	I_SimpleProperty(osgText::Text::BackdropType, BackdropType, 
	                 __BackdropType__getBackdropType, 
	                 __void__setBackdropType__BackdropType);
	I_SimpleProperty(float, BackdropVerticalOffset, 
	                 __float__getBackdropVerticalOffset, 
	                 0);
	I_SimpleProperty(const osg::Vec4 &, Color, 
	                 __C5_osg_Vec4_R1__getColor, 
	                 __void__setColor__C5_osg_Vec4_R1);
	I_SimpleProperty(const osg::Vec4 &, ColorGradientBottomLeft, 
	                 __C5_osg_Vec4_R1__getColorGradientBottomLeft, 
	                 0);
	I_SimpleProperty(const osg::Vec4 &, ColorGradientBottomRight, 
	                 __C5_osg_Vec4_R1__getColorGradientBottomRight, 
	                 0);
	I_SimpleProperty(osgText::Text::ColorGradientMode, ColorGradientMode, 
	                 __ColorGradientMode__getColorGradientMode, 
	                 __void__setColorGradientMode__ColorGradientMode);
	I_SimpleProperty(const osg::Vec4 &, ColorGradientTopLeft, 
	                 __C5_osg_Vec4_R1__getColorGradientTopLeft, 
	                 0);
	I_SimpleProperty(const osg::Vec4 &, ColorGradientTopRight, 
	                 __C5_osg_Vec4_R1__getColorGradientTopRight, 
	                 0);
	I_SimpleProperty(osg::ref_ptr< osgText::Font >, Font, 
	                 0, 
	                 __void__setFont__osg_ref_ptrT1_Font_);
	I_SimpleProperty(const osgText::Text::TextureGlyphQuadMap &, TextureGlyphQuadMap, 
	                 __C5_TextureGlyphQuadMap_R1__getTextureGlyphQuadMap, 
	                 0);
	I_SimpleProperty(bool, ThreadSafeRefUnref, 
	                 0, 
	                 __void__setThreadSafeRefUnref__bool);
END_REFLECTOR

TYPE_NAME_ALIAS(std::vector< osgText::Font::Glyph * >, osgText::Text::GlyphQuads::Glyphs)

TYPE_NAME_ALIAS(std::vector< unsigned int >, osgText::Text::GlyphQuads::LineNumbers)

TYPE_NAME_ALIAS(std::vector< osg::Vec2 >, osgText::Text::GlyphQuads::Coords2)

TYPE_NAME_ALIAS(std::vector< osg::Vec3 >, osgText::Text::GlyphQuads::Coords3)

TYPE_NAME_ALIAS(std::vector< osg::Vec2 >, osgText::Text::GlyphQuads::TexCoords)

TYPE_NAME_ALIAS(std::vector< osg::Vec4 >, osgText::Text::GlyphQuads::ColorCoords)

BEGIN_VALUE_REFLECTOR(osgText::Text::GlyphQuads)
	I_DeclaringFile("osgText/Text");
	I_Constructor0(____GlyphQuads,
	               "",
	               "");
	I_Method0(osgText::Text::GlyphQuads::Glyphs, getGlyphs,
	          Properties::NON_VIRTUAL,
	          __Glyphs__getGlyphs,
	          "",
	          "");
	I_Method0(const osgText::Text::GlyphQuads::Glyphs, getGlyphs,
	          Properties::NON_VIRTUAL,
	          __C5_Glyphs__getGlyphs,
	          "",
	          "");
	I_Method0(osgText::Text::GlyphQuads::Coords2 &, getCoords,
	          Properties::NON_VIRTUAL,
	          __Coords2_R1__getCoords,
	          "",
	          "");
	I_Method0(const osgText::Text::GlyphQuads::Coords2 &, getCoords,
	          Properties::NON_VIRTUAL,
	          __C5_Coords2_R1__getCoords,
	          "",
	          "");
	I_Method1(osgText::Text::GlyphQuads::Coords3 &, getTransformedCoords, IN, unsigned int, contexID,
	          Properties::NON_VIRTUAL,
	          __Coords3_R1__getTransformedCoords__unsigned_int,
	          "",
	          "");
	I_Method1(const osgText::Text::GlyphQuads::Coords3 &, getTransformedCoords, IN, unsigned int, contexID,
	          Properties::NON_VIRTUAL,
	          __C5_Coords3_R1__getTransformedCoords__unsigned_int,
	          "",
	          "");
	I_Method0(osgText::Text::GlyphQuads::TexCoords &, getTexCoords,
	          Properties::NON_VIRTUAL,
	          __TexCoords_R1__getTexCoords,
	          "",
	          "");
	I_Method0(const osgText::Text::GlyphQuads::TexCoords &, getTexCoords,
	          Properties::NON_VIRTUAL,
	          __C5_TexCoords_R1__getTexCoords,
	          "",
	          "");
	I_Method0(osgText::Text::GlyphQuads::LineNumbers &, getLineNumbers,
	          Properties::NON_VIRTUAL,
	          __LineNumbers_R1__getLineNumbers,
	          "",
	          "");
	I_Method0(const osgText::Text::GlyphQuads::LineNumbers &, getLineNumbers,
	          Properties::NON_VIRTUAL,
	          __C5_LineNumbers_R1__getLineNumbers,
	          "",
	          "");
	I_SimpleProperty(osgText::Text::GlyphQuads::Coords2 &, Coords, 
	                 __Coords2_R1__getCoords, 
	                 0);
	I_SimpleProperty(osgText::Text::GlyphQuads::Glyphs, Glyphs, 
	                 __Glyphs__getGlyphs, 
	                 0);
	I_SimpleProperty(osgText::Text::GlyphQuads::LineNumbers &, LineNumbers, 
	                 __LineNumbers_R1__getLineNumbers, 
	                 0);
	I_SimpleProperty(osgText::Text::GlyphQuads::TexCoords &, TexCoords, 
	                 __TexCoords_R1__getTexCoords, 
	                 0);
	I_PublicMemberProperty(osgText::Text::GlyphQuads::Glyphs, _glyphs);
	I_PublicMemberProperty(osgText::Text::GlyphQuads::Coords2, _coords);
	I_PublicMemberProperty(osg::buffered_object< osgText::Text::GlyphQuads::Coords3 >, _transformedCoords);
	I_PublicMemberProperty(osgText::Text::GlyphQuads::TexCoords, _texcoords);
	I_PublicMemberProperty(osgText::Text::GlyphQuads::LineNumbers, _lineNumbers);
	I_PublicMemberProperty(osgText::Text::GlyphQuads::ColorCoords, _colorCoords);
END_REFLECTOR

BEGIN_VALUE_REFLECTOR(osg::ref_ptr< osgText::Font >)
	I_DeclaringFile("osg/ref_ptr");
	I_Constructor0(____ref_ptr,
	               "",
	               "");
	I_Constructor1(IN, osgText::Font *, ptr,
	               Properties::NON_EXPLICIT,
	               ____ref_ptr__T_P1,
	               "",
	               "");
	I_Constructor1(IN, const osg::ref_ptr< osgText::Font > &, rp,
	               Properties::NON_EXPLICIT,
	               ____ref_ptr__C5_ref_ptr_R1,
	               "",
	               "");
	I_Method0(osgText::Font *, get,
	          Properties::NON_VIRTUAL,
	          __T_P1__get,
	          "",
	          "");
	I_Method0(bool, valid,
	          Properties::NON_VIRTUAL,
	          __bool__valid,
	          "",
	          "");
	I_Method0(osgText::Font *, release,
	          Properties::NON_VIRTUAL,
	          __T_P1__release,
	          "",
	          "");
	I_Method1(void, swap, IN, osg::ref_ptr< osgText::Font > &, rp,
	          Properties::NON_VIRTUAL,
	          __void__swap__ref_ptr_R1,
	          "",
	          "");
	I_SimpleProperty(osgText::Font *, , 
	                 __T_P1__get, 
	                 0);
END_REFLECTOR

BEGIN_VALUE_REFLECTOR(osg::ref_ptr< osgText::Font::GlyphTexture >)
	I_DeclaringFile("osg/ref_ptr");
	I_Constructor0(____ref_ptr,
	               "",
	               "");
	I_Constructor1(IN, osgText::Font::GlyphTexture *, ptr,
	               Properties::NON_EXPLICIT,
	               ____ref_ptr__T_P1,
	               "",
	               "");
	I_Constructor1(IN, const osg::ref_ptr< osgText::Font::GlyphTexture > &, rp,
	               Properties::NON_EXPLICIT,
	               ____ref_ptr__C5_ref_ptr_R1,
	               "",
	               "");
	I_Method0(osgText::Font::GlyphTexture *, get,
	          Properties::NON_VIRTUAL,
	          __T_P1__get,
	          "",
	          "");
	I_Method0(bool, valid,
	          Properties::NON_VIRTUAL,
	          __bool__valid,
	          "",
	          "");
	I_Method0(osgText::Font::GlyphTexture *, release,
	          Properties::NON_VIRTUAL,
	          __T_P1__release,
	          "",
	          "");
	I_Method1(void, swap, IN, osg::ref_ptr< osgText::Font::GlyphTexture > &, rp,
	          Properties::NON_VIRTUAL,
	          __void__swap__ref_ptr_R1,
	          "",
	          "");
	I_SimpleProperty(osgText::Font::GlyphTexture *, , 
	                 __T_P1__get, 
	                 0);
END_REFLECTOR

STD_MAP_REFLECTOR(std::map< osg::ref_ptr< osgText::Font::GlyphTexture > COMMA  osgText::Text::GlyphQuads >)

STD_VECTOR_REFLECTOR(std::vector< osg::Vec2 >)

STD_VECTOR_REFLECTOR(std::vector< osgText::Font::Glyph * >)

