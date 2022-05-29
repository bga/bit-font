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


#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "lodepng.h"

const char* help = (""
	"%s image [font.c || -]\n"
	 "  convert image to font C file file\n"
"");

unsigned App_getPixel(unsigned x, unsigned y, 
	unsigned char* image, unsigned w, unsigned h
) {
	return image[(x + y * w) * 3];
} 

int main(int argc, char *argv[])
{
	if(argc <= 2) {
		printf("Missed OUT_FILE\n");
		return 1;
	}
	else if(strcmp(argv[1], "--help") == 0) {
		printf(help);
		return 0;
	}
	else {
		const char* imageFilePath = argv[1]; 
		const char* outFilePath = (2 < argc) ? argv[2] : "-"; 
		
		unsigned char* pixelData;
		unsigned w, h;
		unsigned ret = lodepng_decode24_file(&pixelData, &w, &h, imageFilePath);
		if(ret) return 2;
		
		FILE* outFile = (strcmp(outFilePath, "-") == 0) ? stdout : fopen(outFilePath, "wt");
		
		if(outFile == NULL) return 3; 
		
		unsigned x0 = 62, y0 = 148; 
		const unsigned xCharStep = 90 - x0, yCharStep = 168 - 148; 
		const unsigned xPixelStep = 4, yPixelStep = 4; 
		const unsigned c0 = 0xC0, c1 = 0x00; 
		const char* indent = "";

		fprintf(outFile, "%sGlyphData BitFont_halfGlyphData[] = {\n", indent);
		unsigned charI = 0;
		for(int yi = 0; yi < 2; yi += 1) {
			for(int xi = 0; xi < 11; xi += 1) {
				fprintf(outFile, "%s\t#define g%u %u\n", indent, charI, charI);
				fprintf(outFile, "%s\tMAKE_HALF_GLYPH(a\n", indent); 
				for(int yPi = 0; yPi < 4; yPi += 1) {
					fprintf(outFile, "%s\t\t", indent);
					for(int xPi = 0; xPi < 6; xPi += 1) {
						fprintf(outFile, "%s%s", (xPi == 0) ? "" : " ", (App_getPixel(x0 + xi * xCharStep + xPixelStep * xPi, y0 + yi * yCharStep + yPixelStep * yPi, pixelData, w, h) == c1 ? "X" : "_"));
					}
					fprintf(outFile, "\n");
				}
				fprintf(outFile, "%s\t),\n", indent); 
				charI += 1;
			}
		}
		 
		fclose(outFile);
		free(pixelData);
			
		return ret;
	}
}
