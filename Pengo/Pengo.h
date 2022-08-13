#pragma once

class Pengo {
public:
	static unsigned int pengoLeft1, pengoLeft2, pengoRight1, pengoRight2;
	static unsigned pengoUp1, pengoUp2, pengoDown1, pengoDown2;
	static unsigned int pengoPushUp, pengoPushDown, pengoPushLeft, pengoPushRight;
	static unsigned int pengoDead1, pengoDead2;
	static unsigned int pengoIndestructable;
	static double width, height;
	static double offsetX, offsetY;
	static double speed;

	int i, j;
	int orientation = 2;
	bool moving = false, pushing = false;
	double distance = 0;
	bool stepPos = true;
	bool dead = false;
	bool indestructable = false;
	bool stepPosIndestructable = false;
	Pengo();
	Pengo(int i, int j);
	unsigned int pickImage();
	double getPosX();
	double getPosY();
	void draw();
};

