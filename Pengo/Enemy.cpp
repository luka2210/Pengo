#include "Enemy.h"
#include "Glut.h"

unsigned int Enemy::globalId = 0;
double Enemy::height = 1.0;
double Enemy::width = 1.0;
double Enemy::offsetX = 0.5;
double Enemy::offsetY = 1.25;

unsigned int Enemy::enemyDown1 = 0, Enemy::enemyDown2 = 0, Enemy::enemyUp1 = 0, Enemy::enemyUp2 = 0;
unsigned int Enemy::enemyLeft1 = 0, Enemy::enemyLeft2 = 0, Enemy::enemyRight1 = 0, Enemy::enemyRight2 = 0;
unsigned int Enemy::enemySweepDown1 = 0, Enemy::enemySweepDown2 = 0, Enemy::enemySweepUp1 = 0, Enemy::enemySweepUp2 = 0;
unsigned int Enemy::enemySweepLeft1 = 0, Enemy::enemySweepLeft2 = 0, Enemy::enemySweepRight1 = 0, Enemy::enemySweepRight2 = 0;
unsigned int Enemy::enemyStunned1 = 0, Enemy::enemyStunned2 = 0;

unsigned int Enemy::pickImage() {
	if (stunned) {
		if (stepPos)
			return enemyStunned1;
		else
			return enemyStunned2;
	}
	if (sweeping) 
		switch (orientation) {
		case 1:
			if (stepPos)
				return enemySweepLeft1;
			else
				return enemySweepLeft2;
		case 2:
			if (stepPos)
				return enemySweepDown1;
			else
				return enemySweepDown2;
		case 3:
			if (stepPos)
				return enemySweepRight1;
			else
				return enemySweepRight2;
		case 4:
			if (stepPos)
				return enemySweepUp1;
			else
				return enemySweepUp2;
		}
	else
		switch (orientation) {
		case 1:
			if (stepPos)
				return enemyLeft1;
			else
				return enemyLeft2;
		case 2:
			if (stepPos)
				return enemyDown1;
			else
				return enemyDown2;
		case 3:
			if (stepPos)
				return enemyRight1;
			else
				return enemyRight2;
		case 4:
			if (stepPos)
				return enemyUp1;
			else
				return enemyUp2;
		}
}

Enemy::Enemy() {}

Enemy::Enemy(int i, int j, bool sweeping) {
	this->i = i;
	this->j = j;
	this->sweeping = sweeping;
	this->speed = 0.1;
	this->id = ++Enemy::globalId;
}

void Enemy::draw() {
	double posX = j + offsetX;
	double posY = i + offsetY;
	
	switch (orientation) {
	case 1:
		posX -= distance;
		break;
	case 2:
		posY -= distance;
		break;
	case 3:
		posX += distance;
		break;
	case 4:
		posY += distance;
		break;
	default:
		posY -= distance;
		break;
	}

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, pickImage());

	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0);
	glVertex2f(posX, posY);
	glTexCoord2f(1.0, 0.0);
	glVertex2f(posX + width, posY);
	glTexCoord2f(1.0, 1.0);
	glVertex2f(posX + width, posY + height);
	glTexCoord2f(0.0, 1.0);
	glVertex2f(posX, posY + height);
	glEnd();

	glDisable(GL_TEXTURE_2D);
}