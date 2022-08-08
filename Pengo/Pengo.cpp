#include "Pengo.h"
#include "LoadTexture.h";

double Pengo::height = 1.0;
double Pengo::width = 1.0;
double Pengo::offsetX = 0.5;
double Pengo::offsetY = 1.25;

//ne radi linker ako se ne inicijalizuju staticke vrednosti
GLuint Pengo::pengoLeft1 = 0;
GLuint Pengo::pengoLeft2 = 0; 
GLuint Pengo::pengoRight1 = 0; 
GLuint Pengo::pengoRight2 = 0;
GLuint Pengo::pengoUp1 = 0;
GLuint Pengo::pengoUp2 = 0;
GLuint Pengo::pengoDown1 = 0;
GLuint Pengo::pengoDown2 = 0;
GLuint Pengo::pengoPushUp = 0;
GLuint Pengo::pengoPushDown = 0;
GLuint Pengo::pengoPushLeft = 0;
GLuint Pengo::pengoPushRight = 0;

GLuint Pengo::pickImage() {
	switch (orientation) {
	case 1:
		if (pushing)
			return pengoPushLeft;
		if (stepPos)
			return pengoLeft1;
		return pengoLeft2;
	case 2:
		if (pushing)
			return pengoPushDown;
		if (stepPos)
			return pengoDown1;
		return pengoDown2;
	case 3:
		if (pushing)
			return pengoPushRight;
		if (stepPos)
			return pengoRight1;
		return pengoRight2;
	case 4:
		if (pushing)
			return pengoPushUp;
		if (stepPos)
			return pengoUp1;
		return pengoUp2;
	default:
		return pengoDown1;
	}
}

Pengo::Pengo() {}

Pengo::Pengo(int i, int j) {
	this->i = i;
	this->j = j;
}

void Pengo::draw() {

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


	//draw pengo
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
