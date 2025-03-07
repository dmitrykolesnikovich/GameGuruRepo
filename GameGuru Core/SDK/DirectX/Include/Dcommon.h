//+--------------------------------------------------------------------------
//
//  Copyright (c) Microsoft Corporation.  All rights reserved.
//
//  Abstract:
//     Public API definitions for DWrite and D2D
//
//----------------------------------------------------------------------------

#ifndef DCOMMON_H_INCLUDED
#define DCOMMON_H_INCLUDED

//
//These macros are defined in the Windows 7 SDK, however to enable development using the technical preview,
//they are included here temporarily.
//
#ifndef DEFINE_ENUM_FLAG_OPERATORS 
#define DEFINE_ENUM_FLAG_OPERATORS(ENUMTYPE) \
extern "C++" { \
inline ENUMTYPE operator | (ENUMTYPE a, ENUMTYPE b) { return ENUMTYPE(((int)a) | ((int)b)); } \
inline ENUMTYPE &operator |= (ENUMTYPE &a, ENUMTYPE b) { return (ENUMTYPE &)(((int &)a) |= ((int)b)); } \
inline ENUMTYPE operator & (ENUMTYPE a, ENUMTYPE b) { return ENUMTYPE(((int)a) & ((int)b)); } \
inline ENUMTYPE &operator &= (ENUMTYPE &a, ENUMTYPE b) { return (ENUMTYPE &)(((int &)a) &= ((int)b)); } \
inline ENUMTYPE operator ~ (ENUMTYPE a) { return ENUMTYPE(~((int)a)); } \
inline ENUMTYPE operator ^ (ENUMTYPE a, ENUMTYPE b) { return ENUMTYPE(((int)a) ^ ((int)b)); } \
inline ENUMTYPE &operator ^= (ENUMTYPE &a, ENUMTYPE b) { return (ENUMTYPE &)(((int &)a) ^= ((int)b)); } \
}
#endif

#ifndef __field_ecount_opt
#define __field_ecount_opt(x)
#endif

#ifndef __range
#define __range(x,y) 
#endif

#ifndef __field_ecount
#define __field_ecount(x)
#endif

/// <summary>
/// The measuring method used for text layout.
/// </summary>
typedef enum DWRITE_MEASURING_MODE
{
    /// <summary>
    /// Text is measured using glyph ideal metrics whose values are independent to the current display resolution.
    /// </summary>
    DWRITE_MEASURING_MODE_NATURAL,

    /// <summary>
    /// Text is measured using glyph display compatible metrics whose values tuned for the current display resolution.
    /// </summary>
    DWRITE_MEASURING_MODE_GDI_CLASSIC,

    /// <summary>
    /// Text is measured using the same glyph display metrics as text measured by GDI using a font
    /// created with CLEARTYPE_NATURAL_QUALITY.
    /// </summary>
    DWRITE_MEASURING_MODE_GDI_NATURAL

} DWRITE_MEASURING_MODE;

//+-----------------------------------------------------------------------------
//
//  Enum:
//      D2D1_ALPHA_MODE
//
//  Synopsis:
//      Qualifies how alpha is to be treated in a bitmap or render target containing
//      alpha.
//
//------------------------------------------------------------------------------
typedef enum D2D1_ALPHA_MODE
{

	//
	// Alpha mode should be determined implicitly. Some target surfaces do not supply
	// or imply this information in which case alpha must be specified.
	//
	D2D1_ALPHA_MODE_UNKNOWN = 0,

	//
	// Treat the alpha as premultipled.
	//
	D2D1_ALPHA_MODE_PREMULTIPLIED = 1,

	//
	// Opacity is in the 'A' component only.
	//
	D2D1_ALPHA_MODE_STRAIGHT = 2,

	//
	// Ignore any alpha channel information.
	//
	D2D1_ALPHA_MODE_IGNORE = 3,

	D2D1_ALPHA_MODE_FORCE_DWORD = 0xffffffff

} D2D1_ALPHA_MODE;

//+-----------------------------------------------------------------------------
//
//  Struct:
//      D2D1_PIXEL_FORMAT
//
//------------------------------------------------------------------------------
typedef struct D2D1_PIXEL_FORMAT
{
	DXGI_FORMAT format;
	D2D1_ALPHA_MODE alphaMode;

} D2D1_PIXEL_FORMAT;

#endif /* DCOMMON_H_INCLUDED */
