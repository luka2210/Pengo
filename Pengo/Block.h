#pragma once

class Block {
public:
	static unsigned int globalId;
	static double width, height;
	static double offsetX, offsetY;
	static double speed;
	static unsigned int texture, textureDiamond;
	static unsigned int textureDestroyed[];

	int i, j;
	unsigned int id;
	bool diamond;
	bool moving = false;
	int orientation = 0;
	double distance = 0.0;
	bool destroyed = false;
	int destroyedState = 0;

	Block(int i, int j, bool diamond);
	unsigned int getImage();
	double getPosX();
	double getPosY();
	void draw();
};

