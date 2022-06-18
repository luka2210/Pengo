#pragma once
#include "RgbImage.h"

class Pengo {
private:
	static RgbImage pengoLeft1, pengoLeft2, pengoRight1, pengoRight2;
	static RgbImage pengoUp1, pengoUp2, pengoDown1, pengoDown2;
	static RgbImage pengoPushUp, pengoPushDown, pengoPushLeft, pengoPushRight;
	static double width, height;
	static double offsetX, offsetY;
	RgbImage& pickImage();

public:
	int i, j;
	int orientation = 2;
	bool moving = false, pushing = false;
	double distance = 0;
	double speed = 0.5;
	bool stepPos = true;
	Pengo(int i, int j);
	void draw();
};

