#pragma once

class Enemy {
public:
	static unsigned int enemyDown1, enemyDown2, enemyUp1, enemyUp2;
	static unsigned int enemyLeft1, enemyLeft2, enemyRight1, enemyRight2;
	static unsigned int enemySweepDown1, enemySweepDown2, enemySweepUp1, enemySweepUp2;
	static unsigned int enemySweepLeft1, enemySweepLeft2, enemySweepRight1, enemySweepRight2;
	static unsigned int enemyStunned1, enemyStunned2;
	static double width, height;
	static double offsetX, offsetY;
	static double speed;

	int i, j;
	int orientation = 2;
	bool sweeping = false;
	bool dead = false;
	bool stunned = false;
	bool stepPos = true;
	bool moving = false;
	double distance = 0;
	Enemy();
	Enemy(int i, int j);
	unsigned int pickImage();
	void draw();
};