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


#if 1
typedef uint16_t BitFont_Glyph;
//#define MAKE_GLYPH(hiHalfGlyphIndexArg, loHalfGlyphIndexArg) ((((uintmax_t)(hiHalfGlyphIndexArg)) << 8) | (((uintmax_t)(loHalfGlyphIndexArg)) << 0))
#define MAKE_GLYPH(hiHalfGlyphIndexArg, loHalfGlyphIndexArg) (((BitFont_Glyph)(hiHalfGlyphIndexArg)) << 8) | (loHalfGlyphIndexArg)
#else
typedef struct BitFont_Glyph {
	uint8_t hiHalfGlyphIndex;
	uint8_t loHalfGlyphIndex;
} BitFont_Glyph;

#define MAKE_GLYPH(hiHalfGlyphIndexArg, loHalfGlyphIndexArg) { .hiHalfGlyphIndex = (hiHalfGlyphIndexArg), loHalfGlyphIndex =  (loHalfGlyphIndexArg) }
#endif // 0
#if 0 
enum {
	A = MAKE_GLYPH(g6, g3),  
}
#endif // 0

#include "bit-font-chars.h"

#undef MAKE_GLYPH


