#pragma once
#include "RgbImage.h"

class LoadTexture {
public:
	static void file(const char* filename);
	static void image(RgbImage &theTexMap);
};