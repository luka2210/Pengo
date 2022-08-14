#pragma once
#include <stack>

class WriteText {
public:
	static unsigned int level, score, lives, time, ja;
	static unsigned int gameOver, gameWon, pressEnter, levelCleared;
	static unsigned int numbers[10];

	static void simpleWrite(double posX, double posY, double width, double height, unsigned int texture, int number);
	static void writeEverything(int level, int score, int lives, int time, bool gameOver, bool gameWon, bool levelCleared);
};