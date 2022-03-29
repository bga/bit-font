#define g0 0
#define g1 0
#define g2 0
#define g3 0
#define g4 0
#define g5 0
#define g6 0
#define g7 0
#define g8 0
#define g9 0
#define g10 0
#define g11 0
#define g12 0
#define g13 0
#define g14 0
#define g15 0
#define g16 0
#define g17 0
#define g18 0
#define g19 0
#define g20 0
#define g21 0
#define g22 0
#define g23 0

const BitFont_GlyphData BitFont_halfGlyphData[] = {
	#undef g0
	#define g0 0
	MAKE_HALF_GLYPH(a
		_ _ _ _ _ _
		_ _ _ _ _ _
		_ _ _ _ _ _
		_ _ _ _ _ _
	),

#if 1
	#undef g1
	#define g1 1
	MAKE_HALF_GLYPH(a
		_ _ _ _ _ _
		_ _ _ _ _ _
		_ _ X X _ _
		_ _ X X _ _
	),

	#undef g2
	#define g2 2
	MAKE_HALF_GLYPH(a
		_ _ X X _ _
		_ _ X X _ _
		_ _ X X _ _
		_ _ X X _ _
	),

	#undef g3
	#define g3 3
	MAKE_HALF_GLYPH(a
		X X _ _ X X
		X X _ _ X X
		X X _ _ X X
		X X _ _ X X
	),

	#undef g4
	#define g4 4
	MAKE_HALF_GLYPH(a
		X X _ _ X X
		X X _ _ X X
		X X _ _ X X
		X X X X X X
	),

	#undef g5
	#define g5 5
	MAKE_HALF_GLYPH(a
		X X X X X X
		X X _ _ X X
		X X _ _ X X
		X X _ _ X X
	),

	#undef g6
	#define g6 6
	MAKE_HALF_GLYPH(a
		X X X X X X
		X X _ _ X X
		X X _ _ X X
		X X X X X X
	),

	#undef g12
	#define g12 7
	MAKE_HALF_GLYPH(a
		X X X X X X
		X X _ _ _ _
		X X _ _ _ _
		X X X X X X
	),

	#undef g13
	#define g13 8
	MAKE_HALF_GLYPH(a
		X X X X X X
		_ _ _ _ X X
		_ _ _ _ X X
		X X X X X X
	),

	#undef g14
	#define g14 9
	MAKE_HALF_GLYPH(a
		X X X X X X
		_ _ _ _ X X
		_ _ _ _ X X
		_ _ X X X X
	),

	#undef g15
	#define g15 10
	MAKE_HALF_GLYPH(a
		X X X X X X
		_ _ _ _ X X
		_ _ _ _ X X
		_ _ _ _ X X
	),

	#undef g22
	#define g22 11
	MAKE_HALF_GLYPH(a
		X X _ _ _ _
		X X _ _ _ _
		X X _ _ _ _
		X X X X X X
	),

	#undef g23
	#define g23 12
	MAKE_HALF_GLYPH(a
		_ _ _ _ X X
		_ _ _ _ X X
		_ _ _ _ X X
		X X X X X X
	),

#ifndef BIT_FONT__NO_ALPHABET
	#undef g7
	#define g7 13
	MAKE_HALF_GLYPH(a
		X X X X X X
		_ _ X X _ _
		_ _ X X _ _
		_ _ X X _ _
	),

	#undef g8
	#define g8 14
	MAKE_HALF_GLYPH(a
		X _ _ _ _ X
		X X _ _ X X
		X X X X X X
		X X X X X X
	),

	#undef g9
	#define g9 15
	MAKE_HALF_GLYPH(a
		X X X X X X
		X X X X X X
		X X _ _ X X
		X _ _ _ _ X
	),

	#undef g10
	#define g10 16
	MAKE_HALF_GLYPH(a
		_ _ X X _ _
		_ X X X X _
		X X _ _ X X
		X X _ _ X X
	),

	#undef g11
	#define g11 17
	MAKE_HALF_GLYPH(a
		X X _ _ X X
		X X _ _ X X
		X X X X X X
		_ _ X X _ _
	),

	#undef g16
	#define g16 18
	MAKE_HALF_GLYPH(a
		X X X X _ _
		X X _ X X _
		X X _ _ X X
		X X _ _ X X
	),

	#undef g17
	#define g17 19
	MAKE_HALF_GLYPH(a
		X X _ _ X X
		X X _ _ X X
		X X _ X X _
		X X X X _ _
	),

	#undef g18
	#define g18 20
	MAKE_HALF_GLYPH(a
		X X X X X X
		X X _ _ _ _
		X X _ _ _ _
		X X _ X X X
	),

	#undef g19
	#define g19 21
	MAKE_HALF_GLYPH(a
		X X X X X _
		X X _ _ X X
		X X _ _ X X
		X X X X X _
	),

	#undef g20
	#define g20 22
	MAKE_HALF_GLYPH(a
		X X _ _ _ _
		X X _ _ _ _
		X X _ _ _ _
		X X _ _ _ _
	),

	#undef g21
	#define g21 23
	MAKE_HALF_GLYPH(a
		X X X X X X
		X X _ _ X X
		X X _ _ _ _
		X X _ _ _ _
	),
#endif // BIT_FONT__NO_ALPHABET
#endif
};
