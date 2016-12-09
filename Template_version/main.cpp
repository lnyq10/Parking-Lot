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

void animate_all(Group *vehicle[6])
{
    for(int i=0;i<6;++i)vehicle[i]->animate();
}

void draw_all(Group *vehicle[6],Tel &colorfig,Field &p_lot,Group *obj)
{
    p_lot.draw();
    colorfig.draw();
    for(int i=0;i<6;++i)vehicle[i]->draw();
    obj->draw();
}

void display_main(void)
{
    vector <Vec> static pos;
    vector <Vec> static slot;
    vector <int> static order;
    int static n=9;
    Group static *vehicle[6];
    Group static *obj;
    float static dist=0;
    Field static p_lot;
    Vec static target(0,0);
    Tel colorfig(1);

    
    if(pos.empty())
    {
        for(int i=0;i<5;i++)pos.push_back(Vec(-0.59+0.3*i,-0.13));
        for(int i=0;i<5;i++)pos.push_back(Vec(-0.59+0.3*i,0.82));
        
        for(int i=0;i<10;++i)order.push_back(i);
        random_shuffle(order.begin(),order.end());

        //3 objects respectively
        for(int i=0;i<2;++i)
        {
            vehicle[i]=new UFO(0.4,pos[order[i]].getX(),pos[order[i]].getY());
            vehicle[i+2]=new Rocket(0.13,pos[order[i+2]].getX(),pos[order[i+2]].getY());
            if (order[i+2] >= 5) vehicle[i+2]->rotate(PI);
            vehicle[i+4]=new Car(0.7,pos[order[i+4]].getX(),pos[order[i+4]].getY());
            if (order[i+4] >= 5) vehicle[i+4]->rotate(PI,vehicle[i+4]->getAnchor());
        }

        int RAND_=rand()%3;
        switch(RAND_)
        {
            case 0:obj=new UFO(0.4,-0.87,-0.66);break;
            case 1:obj=new Car(0.7,-0.87,-0.66);break;
            case 2:obj=new Rocket(0.13,-0.87,-0.66);break;
        }
        
        //obj's position
        target=pos[order[7]];
    }

    colorfig.move(pos[order[6]]);

	glClear(GL_COLOR_BUFFER_BIT);

	animate_all(vehicle);

    if(p_lot.getStatus()<=85)
    {
        p_lot.open();
    }
    else
    {
        go(obj,dist,order[7],target);
    }

    draw_all(vehicle,colorfig,p_lot,obj);

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
