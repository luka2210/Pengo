#pragma once
#include "Board.h"
#include "LoadTexture.h"

short blockCoords[15][13] = { {0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0},
								  {0, 1, 0, 1, 1, 1, 0, 1, 1, 2, 0, 1, 0},
								  {0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0},
								  {0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0},
								  {0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0},
								  {0, 1, 0, 1, 1, 2, 1, 1, 1, 1, 0, 1, 0},
								  {0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0},
								  {0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1 ,0},
								  {0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0},
								  {0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0},
								  {0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0},
								  {0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0},
								  {0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0},
								  {0, 1, 0, 2, 0, 1, 1, 1, 1, 1, 0, 1, 0},
								  {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0} };
Board board = Board(blockCoords, Pengo(8, 6));
Pengo& pengo = board.pengo;

void myKeyboardFunc( unsigned char key, int x, int y );
void mySpecialKeyFunc( int key, int x, int y );
void drawScene(void);
void initRendering();
void loadTextures();
void resizeWindow(int w, int h);
void turnPengo(int direction);
void movePengo(int direction);