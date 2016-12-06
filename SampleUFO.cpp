#include <windows.h>
#include <GL/glut.h>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "fig.h"
#include "UFO.h"
#include "rocket.h"
#include "Field.h"
#include <cstdio>

void TimeStep(int n)
{
	glutTimerFunc(25, TimeStep, 0);
	glutPostRedisplay();
}

void init()
{
	glClearColor (1.0, 1.0, 1.0, 1.0);
    glLoadIdentity();
}

void display_main(void)
{	
	srand(time(NULL));
	glClear(GL_COLOR_BUFFER_BIT);
	float static dist=0;

	Field static a;
	Rocket static r(0.25,0.5,0.5);
	UFO static aha(0.4,-0.87,-0.66);
	a.draw();

	r.animate();
	r.draw();

	aha.self_spin(1500);
	dist+=aha.move(Vec(0,0.01));
	aha.draw();

	glutSwapBuffers();
	glFlush();

	if(fabs(dist-0.8)<0.01)getchar();
	if(fabs(dist-1.18)<0.01)getchar();
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(400, 400);
	glutCreateWindow("OpenGL");
	init();
	glutDisplayFunc(&display_main);
	glutTimerFunc(25, TimeStep, 0);
	glutMainLoop();
	return 0;
} 

//g++ SampleUFO.cpp UFO.cpp fig.cpp -o UFO -lglu32 -lglut32 -lopengl32