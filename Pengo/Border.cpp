#include "Border.h"

unsigned int Border::borderHorizontal = 0, Border::borderVertical = 0;

Border::Border() {}

void Border::draw() {
	glEnable(GL_TEXTURE_2D);
	//glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

	glBindTexture(GL_TEXTURE_2D, borderVertical);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0);
	glVertex2f(0, 0.75);
	glTexCoord2f(1.0, 0.0);
	glVertex2f(0.5, 0.75);
	glTexCoord2f(1.0, 1.0);
	glVertex2f(0.5, 16.75);
	glTexCoord2f(0.0, 1.0);
	glVertex2f(0.0, 16.75);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, borderVertical);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0);
	glVertex2f(13.5, 0.75);
	glTexCoord2f(1.0, 0.0);
	glVertex2f(14.0, 0.75);
	glTexCoord2f(1.0, 1.0);
	glVertex2f(14.0, 16.75);
	glTexCoord2f(0.0, 1.0);
	glVertex2f(13.5, 16.75);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, borderHorizontal);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 1.0);
	glVertex2f(0.5, 16.75);
	glTexCoord2f(0.0, 0.0);
	glVertex2f(0.5, 16.25);
	glTexCoord2f(1.0, 0.0);
	glVertex2f(13.5, 16.25);
	glTexCoord2f(1.0, 1.0);
	glVertex2f(13.5, 16.75);
	glEnd();


	glBindTexture(GL_TEXTURE_2D, borderHorizontal);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0);
	glVertex2f(0.5, 0.75);
	glTexCoord2f(0.0, 1.0);
	glVertex2f(0.5, 1.25);
	glTexCoord2f(1.0, 1.0);
	glVertex2f(13.5, 1.25);
	glTexCoord2f(1.0, 0.0);
	glVertex2f(13.5, 0.75);
	glEnd();

	glDisable(GL_TEXTURE_2D);
}
