enum {
	d0 = MAKE_GLYPH(g5, g4),  
	d1 = MAKE_GLYPH(g2, g2),  
	d2 = MAKE_GLYPH(g13, g22),  
	d3 = MAKE_GLYPH(g14, g23),  
	d4 = MAKE_GLYPH(g3, g15),  
	d5 = MAKE_GLYPH(g12, g13),  
	d6 = MAKE_GLYPH(g12, g4),  
	d7 = MAKE_GLYPH(g14, g2),  
	d8 = MAKE_GLYPH(g6, g4),  
	d9 = MAKE_GLYPH(g6, g23),  
	space = MAKE_GLYPH(g0, g0),  
	dot = MAKE_GLYPH(g0, g1),  

	comma = MAKE_GLYPH(g0, g2),  
	colon = MAKE_GLYPH(g1, g1),  
	asterick = MAKE_GLYPH(g2, g1),  
	questionMark = MAKE_GLYPH(g14, g1), 
	quote = MAKE_GLYPH(g2, g0),  
	doubleQuote = MAKE_GLYPH(g3, g0),  
	lowTriangle = MAKE_GLYPH(g1, g4),  
	
#ifndef BIT_FONT__NO_ALPHABET
	A = MAKE_GLYPH(g6, g3),  
	B = MAKE_GLYPH(g19, g19),  
	C = MAKE_GLYPH(g21, g4),  
	D = MAKE_GLYPH(g16, g17), 
	E = MAKE_GLYPH(g12, g12),  
	F = MAKE_GLYPH(g12, g20), 
	G = MAKE_GLYPH(g18, g4), 
	H = MAKE_GLYPH(g4, g3),  
	I = MAKE_GLYPH(g2, g2),  
	J = MAKE_GLYPH(g15, g4),  
	K = MAKE_GLYPH(g17, g16),  
	L = MAKE_GLYPH(g20, g22),  
	M = MAKE_GLYPH(g8, g3),  
	N = MAKE_GLYPH(g16, g3),  
	O = MAKE_GLYPH(g5, g4),  
	P = MAKE_GLYPH(g6, g20),  
	Q = MAKE_GLYPH(g5, g11),  
	R = MAKE_GLYPH(g6, g16),  
	S = MAKE_GLYPH(g12, g13),  
	T = MAKE_GLYPH(g7, g2),  
	U = MAKE_GLYPH(g3, g4),  
	V = MAKE_GLYPH(g3, g17),  
	W = MAKE_GLYPH(g3, g9),  
	X = MAKE_GLYPH(g11, g10),  
	Y = MAKE_GLYPH(g4, g2),  
	Z = MAKE_GLYPH(g14, g22),  
	caret = MAKE_GLYPH(g10, g0), //# ^ 
	squareBracketOpen = MAKE_GLYPH(g21, g22),  
	squareBracketClose = MAKE_GLYPH(g15, g23),  
#endif // BIT_FONT__NO_ALPHABET
	// MAKE_GLYPH(, ), //#  
		
};

#if 0
	ruby -e 'puts "" + (0..23).map { |i| "#undef g#{ i }" }.join("\n")' | xclip
#endif // 0

#undef g0
#undef g1
#undef g2
#undef g3
#undef g4
#undef g5
#undef g6
#undef g7
#undef g8
#undef g9
#undef g10
#undef g11
#undef g12
#undef g13
#undef g14
#undef g15
#undef g16
#undef g17
#undef g18
#undef g19
#undef g20
#undef g21
#undef g22
#undef g23

const BitFont_Glyph BitFont_digits[] = { d0, d1, d2, d3, d4, d5, d6, d7, d8, d9 };
const char BitFont_digits_keys[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

#ifndef BIT_FONT__NO_ALPHABET
const BitFont_Glyph BitFont_alphabet[] = { A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z };
const char BitFont_alphabet_keys[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
#endif // BIT_FONT__NO_ALPHABET

const BitFont_Glyph BitFont_all[] = { 
	d0, d1, d2, d3, d4, d5, d6, d7, d8, d9,
	space, 
	dot, 
	comma, 
	colon, 
	asterick, 
	questionMark, 
	quote, 
	doubleQuote, 

#ifndef BIT_FONT__NO_ALPHABET
	A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z, 
	caret, 
	squareBracketOpen, 
	squareBracketClose, 
#endif // BIT_FONT__NO_ALPHABET
};

const char BitFont_all_keys[] = { 
	'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
	' ',  
	'.',  
	',',  
	':',  
	'!',  
	'?', 
	'\'',  
	'"',  

#ifndef BIT_FONT__NO_ALPHABET

	'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 
	'^', 
	'[',  
	']',  
#endif // BIT_FONT__NO_ALPHABET
};
