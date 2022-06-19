#pragma once
#include "RgbImage.h"

class Border {
private:
	bool activatedLeft = false, activatedRight = false, activatedTop = false, activatedBottom = false;
public:
	static RgbImage imageVertical;
	static RgbImage imageHorizontal;
	Border();
	void draw();
};

