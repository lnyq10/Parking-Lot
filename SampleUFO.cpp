#include <GL/glut.h>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "fig.h"
#define OUTPUT_MODE 1

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

	vector <Vec> p;

	p.clear();
	p.push_back(Vec(-0.15,0));
	p.push_back(Vec(-0.05,0));
	p.push_back(Vec(-0.02,-0.07));
	p.push_back(Vec(-0.18,-0.07));

	Poly Ceil(Vec(0,0),0.2,true);
	Ceil.fillColor(0.0,0.2,0.9);

	Poly Tail_left(p);
	Tail_left.fillColor(0.8,0.4,0.8);

	p.clear();
	p.push_back(Vec(0.15,0));
	p.push_back(Vec(0.05,0));
	p.push_back(Vec(0.02,-0.07));
	p.push_back(Vec(0.18,-0.07));

	Poly Tail_right(p);
	Tail_right.fillColor(0.8,0.4,0.8);

	vector <Poly> tmp;
	tmp.clear();
	tmp.push_back(Ceil);
	tmp.push_back(Tail_left);
	tmp.push_back(Tail_right);

	Group static UFO(tmp);
	//Ceil.setAnchor(UFO.getAnchor());
	//Tail_left.setAnchor(UFO.getAnchor());
	//UFO.addFig(Ceil);
	//UFO.addFig(Tail_left);
	UFO.rotate(0.2);
	UFO.move(Vec(-0.004,0));
	UFO.zoom(1.01);
	UFO.draw();

	glutSwapBuffers();
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(500, 500);
	glutInitWindowSize(800, 800);
	glutCreateWindow("OpenGL");
	init();
	glutDisplayFunc(&display_main);
	glutTimerFunc(25, TimeStep, 0);
	glutMainLoop();
	return 0;
} 
