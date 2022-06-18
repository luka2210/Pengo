#include <math.h>		
#include <stdio.h>
#include <stdlib.h>		
#include "Glut.h"
#include "Game.h"
#include "Border.h"
#include "RgbImage.h"

const double Xmin = 0.0, Xmax = 14.0;
const double Ymin = 0.0, Ymax = 18.0;

void loadTextureFromFile(const char* filename)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
	glEnable(GL_DEPTH_TEST);

	RgbImage theTexMap(filename);

	// Pixel alignment: each row is word aligned (aligned to a 4 byte boundary)
	//    Therefore, no need to call glPixelStore( GL_UNPACK_ALIGNMENT, ... );

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, theTexMap.GetNumCols(), theTexMap.GetNumRows(),
		GL_RGB, GL_UNSIGNED_BYTE, theTexMap.ImageData());

}


void myKeyboardFunc( unsigned char key, int x, int y ) {

}

void mySpecialKeyFunc( int key, int x, int y ) {
	
}

void drawScene(void){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    
	glMatrixMode(GL_MODELVIEW);		
	glLoadIdentity();

	//tekstura
	glEnable(GL_TEXTURE_2D);
	loadTextureFromFile("textures/RedLeavesTexture.bmp");
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(5.0, 5.0, 0.0);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(5.0, 6.0, 0.0);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(6.0, 6.0, 0.0);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(6.0, 5.0, 0.0);
	glEnd();

	glDisable(GL_TEXTURE_2D);


	Border b = Border(0.0, 1.0, Xmax, 16.0, 0.5);
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
