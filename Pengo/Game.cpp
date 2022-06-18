#include <math.h>		
#include <stdio.h>
#include <stdlib.h>		
#include "Glut.h"
#include "Game.h"
#include "Border.h"
#include "LoadTexture.h"
#include "Block.h"

//#include "LoadTexture.h"

const double Xmin = 0.0, Xmax = 14.0;
const double Ymin = 0.0, Ymax = 18.0;


void myKeyboardFunc( unsigned char key, int x, int y ) {

}

void mySpecialKeyFunc( int key, int x, int y ) {
	
}

void drawScene(void){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    
	glMatrixMode(GL_MODELVIEW);		
	glLoadIdentity();

	Block b1 = Block(0, 0, 0.5, 1.5);
	b1.draw();
		
	Border b = Border();
	b.draw();

    glFlush();
    glutSwapBuffers();
	glutPostRedisplay();
}

void initRendering() {
	glShadeModel(GL_FLAT);
	glEnable(GL_DEPTH);
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

	glutKeyboardFunc(myKeyboardFunc);
	glutSpecialFunc(mySpecialKeyFunc);
	glutReshapeFunc(resizeWindow);
	glutDisplayFunc(drawScene);
	
	glutMainLoop();

    return(0);
}
