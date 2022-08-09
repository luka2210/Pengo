#pragma once

//extern short blockCoords[15][13];
//extern Board board;
//extern Pengo& pengo;

void myKeyboardFunc( unsigned char key, int x, int y );
void mySpecialKeyFunc( int key, int x, int y );
void drawScene(void);
void initRendering();
void resizeWindow(int w, int h);
//void turnPengo(int direction);
//void movePengo(int direction);