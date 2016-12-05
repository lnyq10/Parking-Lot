#include <windows.h>
#include <GL/glut.h>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "fig.h"
#include "UFO.h"

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
	
	UFO static aha(1);

	aha.self_spin(2000);
	aha.draw();

	glutSwapBuffers();
	glFlush();
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
