#include <math.h>		
#include <stdio.h>
#include <stdlib.h>		
#include "Glut.h"
#include "Game.h"
#include "Board.h"
#include "LoadTexture.h"

using namespace std;

const double Xmin = 0.0, Xmax = 14.0;
const double Ymin = 0.0, Ymax = 18.0;

short blockCoords[15][13] = {     {0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0},
								  {0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0},
								  {0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0},
								  {0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0},
								  {0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0},
								  {0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0},
								  {0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0},
								  {0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1 ,0},
								  {0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0},
								  {0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0},
								  {0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0},
								  {0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0},
								  {0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0},
								  {0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0},
								  {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0} };
Board board = Board(blockCoords, Pengo(8, 6));
Pengo& pengo = board.pengo;

void myKeyboardFunc( unsigned char key, int x, int y ) {

}

void mySpecialKeyFunc( int key, int x, int y ) {
	switch (key) {
	case GLUT_KEY_LEFT:
		turnPengo(1);
		break;
	case GLUT_KEY_DOWN:
		turnPengo(2);
		break;
	case GLUT_KEY_RIGHT:
		turnPengo(3);
		break;
	case GLUT_KEY_UP:
		turnPengo(4);
		break;
	}
}

void turnPengo(int direction) {
	if (pengo.moving || pengo.pushing)
		return;
	pengo.orientation = direction;
	pengo.stepPos = !pengo.stepPos;

	switch (direction) {
	case 1:
		if (pengo.j == 0)
			return;
		for (Block& block : board.blocks)
			if (block.i == pengo.i && block.j == pengo.j - 1)
				return;
		break;
	case 2:
		if (pengo.i == 0)
			return;
		for (Block& block : board.blocks)
			if (block.j == pengo.j && block.i == pengo.i - 1)
				return;
		break;
	case 3:
		if (pengo.j == 12)
			return;
		for (Block& block : board.blocks)
			if (block.i == pengo.i && block.j == pengo.j + 1)
				return;
		break;
	case 4: 
		if (pengo.i == 14)
			return;
		for (Block& block : board.blocks)
			if (block.j == pengo.j && block.i == pengo.i + 1)
				return;
		break;
	default:
		return;
	}

	pengo.moving = true;
	movePengo(direction);
}

void movePengo(int direction) {
	pengo.distance += pengo.speed;
	//pengo.stepPos = !pengo.stepPos;
	if (pengo.distance >= 1) {
		switch (direction) {
		case 1:
			pengo.j--;
			break;
		case 2:
			pengo.i--;
			break;
		case 3:
			pengo.j++;
			break;
		case 4:
			pengo.i++;
			break;
		}
		pengo.moving = false;
		pengo.distance = 0;
		return;
	}
	glutTimerFunc(7, movePengo, direction);
}

void drawScene(void){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    
	glMatrixMode(GL_MODELVIEW);		
	glLoadIdentity();

	board.draw();

    glFlush();
    glutSwapBuffers();
	glutPostRedisplay();
}

void initRendering() {
	glShadeModel(GL_FLAT);
	glEnable(GL_DEPTH);
}

void loadTextures() {
	Block::texture = LoadTexture::file("textures/Block.bmp");
	Pengo::pengoDown1 = LoadTexture::file("textures/PengoDown1.bmp");
	Pengo::pengoDown2 = LoadTexture::file("textures/PengoDown2.bmp");
	Pengo::pengoUp1 = LoadTexture::file("textures/PengoUp1.bmp");
	Pengo::pengoUp2 = LoadTexture::file("textures/PengoUp2.bmp");
	Pengo::pengoLeft1 = LoadTexture::file("textures/PengoLeft1.bmp");
	Pengo::pengoLeft2 = LoadTexture::file("textures/PengoLeft2.bmp");
	Pengo::pengoRight1 = LoadTexture::file("textures/PengoRight1.bmp");
	Pengo::pengoRight2 = LoadTexture::file("textures/PengoRight2.bmp");
	Pengo::pengoPushDown = LoadTexture::file("textures/PengoPushDown.bmp");
	Pengo::pengoPushUp = LoadTexture::file("textures/PengoPushUp.bmp");
	Pengo::pengoPushLeft = LoadTexture::file("textures/PengoPushLeft.bmp");
	Pengo::pengoPushRight = LoadTexture::file("textures/PengoPushRight.bmp");
}

void resizeWindow(int w, int h) {
	double scale, center;
	double windowXmin, windowXmax, windowYmin, windowYmax;

	glViewport( 0, 0, w, h );	

	w = (w==0) ? 1 : w;
	h = (h==0) ? 1 : h;
	if ( (Xmax-Xmin)/w < (Ymax-Ymin)/h ) {
		scale = ((Ymax-Ymin)/h)/((Xmax-Xmin)/w);
		center = (Xmax+Xmin)/2;
		windowXmin = center - (center-Xmin)*scale;
		windowXmax = center + (Xmax-center)*scale;
		windowYmin = Ymin;
		windowYmax = Ymax;
	}
	else {
		scale = ((Xmax-Xmin)/w)/((Ymax-Ymin)/h);
		center = (Ymax+Ymin)/2;
		windowYmin = center - (center-Ymin)*scale;
		windowYmax = center + (Ymax-center)*scale;
		windowXmin = Xmin;
		windowXmax = Xmax;
	}
	
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    glOrtho( windowXmin, windowXmax, windowYmin, windowYmax, -1, 1 );
}

int main( int argc, char** argv ) {
	glutInit(&argc,argv);
 
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );

	glutInitWindowPosition(10, 60);
	glutInitWindowSize(560, 720);
	glutCreateWindow("Pengo");

    initRendering();
	loadTextures();

	glutKeyboardFunc(myKeyboardFunc);
	glutSpecialFunc(mySpecialKeyFunc);
	glutReshapeFunc(resizeWindow);
	glutDisplayFunc(drawScene);

	glutMainLoop();

    return(0);
}
