#include <windows.h>
#include <GL/glut.h>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "fig.h"
#include "UFO.h"
#include "car.h"
#include "rocket.h"
#include "Field.h"
#include "locus.h"
#include <algorithm>

using namespace std;

void TimeStep(int n)
{
	glutTimerFunc(25, TimeStep, 0);
	glutPostRedisplay();
}

void animate_all(UFO *ufo[2],Rocket *rocket[2],Car *car[2])
{
    for(int i=0;i<2;++i)
    {
        ufo[i]->animate();
        rocket[i]->animate();
        car[i]->animate();
    }
}

template <class T> void draw_all(UFO *ufo[2],Rocket *rocket[2],Car *car[2],Tel &colorfig,Field &p_lot,T &obj)
{
    p_lot.draw();
    colorfig.draw();
    for(int i=0;i<2;++i)
    {
        ufo[i]->draw();
        rocket[i]->draw();
        car[i]->draw();
    }
    obj.draw();
}

void display_main(void)
{
    vector <Vec> static pos;
    vector <Vec> static slot;
    vector <int> static order;
    int static n=9;
    UFO static *ufo[2];
    Rocket static *rocket[2];
    Car static *car[2];
    float static dist=0;
    Field static p_lot;
    Vec static target(0,0);
    Tel colorfig(1,rand()%10+3);

    //UFO static obj(0.4,-0.87,-0.66);
    //Car static obj(0.7,-0.87,-0.66);
    Rocket static obj(0.13,-0.87,-0.66);

    if(pos.empty())
    {
        for(int i=0;i<5;i++)pos.push_back(Vec(-0.59+0.3*i,-0.13));
        for(int i=0;i<5;i++)pos.push_back(Vec(-0.59+0.3*i,0.82));
        
        for(int i=0;i<10;++i)order.push_back(i);
        random_shuffle(order.begin(),order.end());

        //3 objects respectively
        for(int i=0;i<2;++i)
        {
            ufo[i]=new UFO(0.4,pos[order[i]].getX(),pos[order[i]].getY());
            rocket[i]=new Rocket(0.13,pos[order[i+2]].getX(),pos[order[i+2]].getY());
            if (order[i+2] >= 5) rocket[i]->rotate(PI);
            car[i]=new Car(0.7,pos[order[i+4]].getX(),pos[order[i+4]].getY());
        }


        //obj's position
        target=pos[order[7]];
    }

    colorfig.move(pos[order[6]]);

	glClear(GL_COLOR_BUFFER_BIT);

	animate_all(ufo,rocket,car);

    if(p_lot.getStatus()<=85)
    {
        p_lot.open();
    }
    else
    {
        go(obj,dist,order[7],target);
    }

    draw_all(ufo,rocket,car,colorfig,p_lot,obj);

	glutSwapBuffers();
	glFlush();
}

int main(int argc, char *argv[])
{
    srand(time(NULL));
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(550, 550);
	glutCreateWindow("OpenGL");
	glClearColor (1.0, 1.0, 1.0, 1.0);
    glLoadIdentity();
	glutDisplayFunc(&display_main);
	glutTimerFunc(25, TimeStep, 0);
	glutMainLoop();
	return 0;
} 

//g++ SampleUFO.cpp UFO.cpp fig.cpp -o UFO -lglu32 -lglut32 -lopengl32
