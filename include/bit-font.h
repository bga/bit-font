/*
	Copyright 2022 Bga <bga.email@gmail.com>

	Licensed under the Apache License, Version 2.0 (the "License");
	you may not use this file except in compliance with the License.
	You may obtain a copy of the License at

		http://www.apache.org/licenses/LICENSE-2.0

	Unless required by applicable law or agreed to in writing, software
	distributed under the License is distributed on an "AS IS" BASIS,
	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
	See the License for the specific language governing permissions and
	limitations under the License.
*/


#pragma once

#include <stdint.h>
#include <stdint.h>

enum {
	BitFont_glyphWidth = 6, 
	BitFont_glyphHalfHeight = 4, 
	BitFont_glyphHeight = 2 * BitFont_glyphHalfHeight - 1, 
};

typedef struct BitFont_GlyphData {
	uint8_t data[3];
} BitFont_GlyphData;

#define MAKE_HALF_GLYPH(b0Arg) { .data = { \
	((uint8_t)((b0Arg) >> 16)), \
	((uint8_t)((b0Arg) >> 8)),  \
	((uint8_t)((b0Arg) >> 0)),  \
} }

// #define a ((((((((((((0
#define a ((((((((((((((((((((((((((((((((((((((((((((((((0UL
#define X << 1) | 1UL) 
#define _ << 1) | 0UL) 

#if 0
BitFont_GlyphData g0Data[] = {
	#define g0 0
	MAKE_HALF_GLYPH(a
		X X X X X X  
		X X _ _ X X  
		X X _ _ X X  
		X X X X X X 
	), 
};
#endif // 0

#include "bit-font-half-raster.h"

#undef _
#undef X
#undef a
#undef MAKE_HALF_GLYPH


#if BIT_FONT_HALF_GLYPHES_SIZE <= 16
typedef uint8_t BitFont_Glyph;
//#define MAKE_GLYPH(hiHalfGlyphIndexArg, loHalfGlyphIndexArg) ((((uintmax_t)(hiHalfGlyphIndexArg)) << 8) | (((uintmax_t)(loHalfGlyphIndexArg)) << 0))
#define MAKE_GLYPH(hiHalfGlyphIndexArg, loHalfGlyphIndexArg) (((BitFont_Glyph)(hiHalfGlyphIndexArg)) << 4) | (loHalfGlyphIndexArg)
#define BIT_FONT__GET_HI_HALF_INDEX(vArg) (((BitFont_Glyph)(vArg)) >> 4)
#define BIT_FONT__GET_LO_HALF_INDEX(vArg) (((BitFont_Glyph)(vArg)) & 0x0F)
#else
#if 1
typedef uint16_t BitFont_Glyph;
//#define MAKE_GLYPH(hiHalfGlyphIndexArg, loHalfGlyphIndexArg) ((((uintmax_t)(hiHalfGlyphIndexArg)) << 8) | (((uintmax_t)(loHalfGlyphIndexArg)) << 0))
#define MAKE_GLYPH(hiHalfGlyphIndexArg, loHalfGlyphIndexArg) (((BitFont_Glyph)(hiHalfGlyphIndexArg)) << 8) | (loHalfGlyphIndexArg)
#define BIT_FONT__GET_HI_HALF_INDEX(vArg) (((BitFont_Glyph)(vArg)) >> 8)
#define BIT_FONT__GET_LO_HALF_INDEX(vArg) (((BitFont_Glyph)(vArg)) & 0xFF)
#else
typedef struct BitFont_Glyph {
	uint8_t hiHalfGlyphIndex;
	uint8_t loHalfGlyphIndex;
} BitFont_Glyph;

#define MAKE_GLYPH(hiHalfGlyphIndexArg, loHalfGlyphIndexArg) { .hiHalfGlyphIndex = (hiHalfGlyphIndexArg), loHalfGlyphIndex =  (loHalfGlyphIndexArg) }
#endif // 0
#endif // 0
#if 0 
enum {
	A = MAKE_GLYPH(g6, g3),  
}
#endif // 0

#include "bit-font-chars.h"

#undef MAKE_GLYPH


