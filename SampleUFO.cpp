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

void manuel(float length,Car* mycar,int floor=1);

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
	
	Car static mycar(-0.85,-0.35);
	mycar.rotate_wheel(0.1);
	manuel(0.9,&mycar,2);

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

void manuel(float length,Car* mycar,int floor=1){
    mycar->rotate_wheel(0.1);
   // mycar->move(Vec(0.1,0.1));
    if(floor==1) {
        static float dis = 0;
        static float dis_2 = 0;
        static bool go = false;
        if (dis < 0.4) {
            dis += 0.008;
            mycar->move(Vec(0, 0.008));
        }
        else if (mycar->get_rotate_angle() > 0 && !go) {
            mycar->rotate(-0.013);
            mycar->move(Vec(0.0015, 0.001));
        }
        else if (mycar->get_rotate_angle() <= 0 && !go) {
            if (dis_2 < length) {
                mycar->move(Vec(0.005, 0));
                dis_2 += 0.005;
            }
            else { go = true; }
        }
        static float dis_3 = 0;
        if (go) {
            if (mycar->get_rotate_angle() < PI / 2) {
                mycar->rotate(0.013);
                mycar->move(Vec(-0.0015, -0.001));
            }
            else {
                if (dis_3 < 0.3) {
                    mycar->move(Vec(-0.00, -0.004));
                    dis_3 += 0.004;
                }
            }
        }
    }
    if(floor==2){
        static float dis = 0;
        static float dis_2 = 0;
        static bool go = false;
        if (dis < 0.8) {
            dis += 0.008;
            mycar->move(Vec(0, 0.008));
        }
        else if (mycar->get_rotate_angle() > 0 && !go) {
            mycar->rotate(-0.013);
            mycar->move(Vec(0.0015, 0.001));
        }
        else if (mycar->get_rotate_angle() <= 0 && !go) {
            if (dis_2 < length) {
                mycar->move(Vec(0.005, 0));
                dis_2 += 0.005;
            }
            else { go = true; }
        }
        static float dis_3 = 0;
        if (go) {
            if (mycar->get_rotate_angle() > -PI / 2) {
                mycar->rotate(-0.013);
                mycar->move(Vec(-0.0015, 0.001));
            }
            else {
                if (dis_3 < 0.15) {
                    mycar->move(Vec(-0.00, 0.004));
                    dis_3 += 0.004;
                }
            }
        }
    }

}
//g++ SampleUFO.cpp UFO.cpp fig.cpp -o UFO -lglu32 -lglut32 -lopengl32
