#include "WriteText.h"
#include "Glut.h"

unsigned int WriteText::ja = 0, WriteText::level = 0, WriteText::score = 0, WriteText::lives = 0, WriteText::time = 0;
unsigned int WriteText::gameOver = 0, WriteText::gameWon = 0, WriteText::pressEnter = 0, WriteText::levelCleared = 0;
unsigned int WriteText::numbers[10] = { 0 };

void WriteText::writeEverything(int level, int score, int lives, int time, bool gameOver, bool gameWon, bool levelCleared) {
	simpleWrite(7.0, 0.05, 7.0, 0.65, ja, -1);
	simpleWrite(0.0, 0.05, 2.7, 0.65, WriteText::score, score);
	simpleWrite(0.0, 17.0, 2.7, 0.65, WriteText::lives, lives);
	simpleWrite(4.8, 17.0, 2.2, 0.65, WriteText::time, time);
	simpleWrite(10.5, 17.0, 2.7, 0.65, WriteText::level, level + 1);
	if (gameOver) {
		simpleWrite(4.0, 10.0, 6.0, 2.0, WriteText::gameOver, -1);
		simpleWrite(2.0, 8.5, 10.0, 2.0, WriteText::pressEnter, -1);
	}
	else if (levelCleared) {
		simpleWrite(4.0, 8.0, 6.0, 2.0, WriteText::levelCleared, -1);
	}
	if (gameWon) {
		simpleWrite(3.0, 10.0, 8.0, 2.0, WriteText::gameWon, -1);
		simpleWrite(2.0, 8.5, 10.0, 2.0, WriteText::pressEnter, -1);
	}
}

void WriteText::simpleWrite(double posX, double posY, double width, double height, unsigned int texture, int number) {
	glColor3f(1.0, 1.0, 1.0);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture);
	
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
	
	posX += width + 0.3;
	width = 0.5;
	
	std::stack<int> sd;
	if (number == 0)
		sd.push(0);
	while (number > 0) {
		int digit = number % 10;
		number /= 10;
		sd.push(digit);
	}

	while (!sd.empty())
	{
		int digit = sd.top();
		sd.pop();

		glBindTexture(GL_TEXTURE_2D, numbers[digit]);
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

		posX += width + 0.05;
	}

	glDisable(GL_TEXTURE_2D);
}
