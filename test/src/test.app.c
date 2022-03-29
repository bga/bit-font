#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#include "../../include/bit-font.h"

#define ARRAY_SIZE(vsArg) (sizeof((vsArg)) / sizeof((vsArg)[0])) 

const char* help = (""
	"%s image font.c\n"
	 "  convert image to font C file file\n"
"");

typedef uint_fast8_t Coord;

typedef uint_fast8_t Color;
enum {
	Color_black = 0,
	Color_white = 0xFF,
};

enum {
	Canvas_width = BitFont_glyphWidth, 
	Canvas_heght = BitFont_glyphHeight, 
};

Color Canvas_pixels[Canvas_width * Canvas_heght];

void Canvas_drawPixel(unsigned x, unsigned y, Color c) {
	Canvas_pixels[x + y * Canvas_width] = c;
} 

const char Canvas_whiteColorSymbol = 'X';
const char Canvas_nonWhiteColorSymbol = ' ';

void Canvas_clear() {
	memset(Canvas_pixels, Color_black, Canvas_width * Canvas_heght);
}
void Canvas_render(FILE* outFile) {
	for(unsigned y = 0; y < Canvas_heght; y += 1) {
		for(unsigned x = 0; x < Canvas_width; x += 1) {
			fputc((Canvas_pixels[x + y * Canvas_width] == Color_white) ? Canvas_whiteColorSymbol : Canvas_nonWhiteColorSymbol, outFile);
		}
		fputc('\n', outFile);
	}
}

void BitFont_drawHalfGlyph(Coord x0, Coord y0, Color c, BitFont_GlyphData const* glyphPtr, Coord ignoreLine) {
	Coord x = 0, y = 0;
//	uint_fast32_t data = *(uint32_t *)glyphPtr->data;
	uint_fast32_t data = (((uint_fast32_t)glyphPtr->data[0]) << 16) | (((uint_fast32_t)glyphPtr->data[1]) << 8) | (((uint_fast32_t)glyphPtr->data[2]) << 0);
	fprintf(stderr, "%x\n", (unsigned)data);
//	return;
	data <<= 8;
	while(data != 0) {
		if(y != ignoreLine && data  & (((uintmax_t)1) << (32 - 1))) {
			Canvas_drawPixel(x0 + x, y0 + y, c);
		};
		data <<= 1;
		x += 1;
		if(x == BitFont_glyphWidth) {
			x = 0;
			y += 1;
		};
	}
}
void BitFont_drawGlyph(Coord x0, Coord y0, Color c, BitFont_Glyph glyph) {
	BitFont_drawHalfGlyph(x0, y0, c, &BitFont_halfGlyphData[(uint8_t)(glyph >> 8)], ((Coord)-1));
	BitFont_drawHalfGlyph(x0, y0 + BitFont_glyphHalfHeight - 1, c, &BitFont_halfGlyphData[(uint8_t)(glyph >> 0)], 0);
}


void displayGlyph(BitFont_Glyph glyph) {
	Canvas_clear();
	BitFont_drawGlyph(0, 0, Color_white, glyph);
	fputs("^^^^^^\n", stdout);
	Canvas_render(stdout);
	fputs("------\n\n", stdout);
}
void displayGlyphs(BitFont_Glyph const* glyphs, size_t glyphsN) {
	for(size_t i = 0; i < glyphsN; i += 1) {
		displayGlyph(glyphs[i]);
	}
}

int main(int argc, char *argv[]) {
	int argi = 0; while(++argi < argc) {
		const char* arg = argv[argi];
		if(0);
		else if(strcasecmp(arg, "all") == 0) {
			displayGlyphs(BitFont_all, ARRAY_SIZE(BitFont_all));
		}
		else if(strcasecmp(arg, "alphabet") == 0) {
			displayGlyphs(BitFont_alphabet, ARRAY_SIZE(BitFont_alphabet));
		}
		else if(strcasecmp(arg, "digits") == 0) {
			displayGlyphs(BitFont_digits, ARRAY_SIZE(BitFont_digits));
		}
		else {
			char const* p = arg; 
			char ch; while((ch = *p++)) {
				size_t index = -1; while(++index < ARRAY_SIZE(BitFont_all)) {
					if(ch == BitFont_all_keys[index]) {
						displayGlyph(BitFont_all[index]);
					};
				}
			}
		}
	}
}
