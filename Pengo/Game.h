#pragma once

void myKeyboardFunc( unsigned char key, int x, int y );
void mySpecialKeyFunc( int key, int x, int y );
void drawScene(void);
void initRendering();
void loadTextures();
void resizeWindow(int w, int h);
void turnPengo(int direction);
void movePengo(int direction);