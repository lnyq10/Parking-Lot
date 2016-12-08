//g++ -std=c++11 main.cpp Field.cpp UFO.cpp fig.cpp car.cpp rocket.cpp -lopengl32 -lfreeglut

#include <ctime>
#include <GL/freeglut.h>
#include "fig.h"
#include "car.h"
#include "Field.h"
#include "UFO.h"
#include "rocket.h"
#include <iostream>
#include <algorithm>

int choose_1();int choose_2();
static float scale=100;

void TimeStep(int n)
{
    glutTimerFunc(25, TimeStep, 0);
    glutPostRedisplay();
}

void manuel(float length,Car* mycar,int floor=1){
    //std::cout<<"length: "<<length<<std::endl;
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
            if (dis_2 < length) {//
                mycar->move(Vec(0.005, 0));
                dis_2 += 0.005;
            }
            else { go = true; }
        }
        static float dis_3 = 0;
        if (go) { //back into the slot
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
        if (dis < 1.1) {
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

void glDraw_car() {   
    glClear(GL_COLOR_BUFFER_BIT);
    //initial position of the car:-0.85,-0.7
    Field static fd;
    fd.draw();

    choose_1();
    choose_2();

    Car static mycar(-0.85,-0.7);
    mycar.rotate_wheel(0.05)

    mycar.draw();

    glutSwapBuffers();glFlush();
}


int main(int argc, char * argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);    
    glutInitWindowSize(800, 800);
    glutCreateWindow("OpenGL");
    glClearColor (1.0, 1.0, 1.0, 1.0);glLoadIdentity(); 
    glutDisplayFunc(&glDraw_car);
    glClearColor (1.0, 1.0, 1.0, 1.0);
    glutTimerFunc(25, TimeStep, 0);
    glutMainLoop();
    return 0;
}

int choose_1() {
    static vector<Vec> location_1;
    for (int i = 0; i < 6; i++) {
        location_1.push_back(Vec(-0.59 + 0.3 * i, -0.12));//the first floor
    }
    srand(time(NULL));

    //the first floor
    int static type[6];
    int static check = 0;
    for (int i = 0; i < 6; i++) {
        if (check == 0) {
            type[i] = rand() % 4;
        }
    }int static empty;
    if(check==0) {
        int static empty = rand() % 6;
        type[empty] = 0; //There must be an empty slot
    }
    Tel static tel_1[6];
    UFO static ufo_1[6];
    Rocket static rkt_1[6];
    if (check == 0) { //initialize the drawings
        for (int i = 0; i < 6; i++) {
            switch (type[i]) {
                case 0:
                    break;
                case 1: {
                    tel_1[i] = Tel(location_1[i].getX(), location_1[i].getY());
                    tel_1[i].random_color();
                    tel_1[i].draw();
                    break;
                }
                case 2: {
                    ufo_1[i] = UFO(0.3, location_1[i].getX(), location_1[i].getY());
                    (ufo_1 + i)->self_spin(.005);
                    ufo_1[i].draw();
                    break;
                }
                case 3: {
                    rkt_1[i] = Rocket(.2, location_1[i].getX(), location_1[i].getY());
                    rkt_1[i].animate();
                    rkt_1[i].draw();
                    break;
                }
                default:;
            }
        }
    } else {  //only initialize the drawing once
        for (int i = 0; i < 6; i++) {
            switch (type[i]) {
                case 0:
                    break;
                case 1: {
                    tel_1[i].random_color();
                    tel_1[i].draw();
                    break;
                }
                case 2: {
                    (ufo_1 + i)->self_spin(.005);
                    ufo_1[i].draw();
                    break;
                }
                case 3: {
                    rkt_1[i].animate();
                    rkt_1[i].draw();
                    break;
                }
                default:;
            }
        }
    }
    check++;
    return empty;
}
int  choose_2(){  //second floor
    static vector<Vec> location_2;
    location_2.push_back(Vec((float) -0.86, (float) 0.84));// the second floor has an extra slot
    for (int i = 0; i < 6; i++) {
        location_2.push_back(Vec(-0.59 + 0.3 * i, 0.82));//the second floor
    }
    srand(time(NULL));
    Tel static tel_2[7];
    UFO static ufo_2[7];
    Rocket static rkt_2[7];
    int static type_2[7];int static check_2=0;
    for(int i=0;i<7;i++){
        if(check_2==0) {
            type_2[i] = rand() % 4;
        }
    }int static empty;
    if(check_2==0) {
        int static empty = rand() % 6;
        type_2[empty] = 0; //There must be an empty slot
    }
    if(check_2==0) {
        for (int i = 0; i < 7; i++) {
            switch (type_2[i]) {
                case 0:
                    break;
                case 1: {
                    tel_2[i] = Tel(location_2[i].getX(), location_2[i].getY());
                    tel_2[i].random_color();
                    tel_2[i].draw();
                    break;
                }
                case 2: {
                    ufo_2[i] = UFO(0.3, location_2[i].getX(), location_2[i].getY());
                    (ufo_2 + i)->self_spin(.005);
                    ufo_2[i].draw();
                    break;
                }
                case 3: {
                    rkt_2[i] = Rocket(.2, location_2[i].getX(), location_2[i].getY());
                    rkt_2[i].animate();
                    rkt_2[i].draw();
                    break;
                }
                default:;
            }
        }
    }
    else {
        for (int i = 0; i < 7; i++) {
            switch (type_2[i]) {
                case 0:
                    break;
                case 1: {
                    tel_2[i].random_color();
                    tel_2[i].draw();
                    break;
                }
                case 2: {
                    ufo_2[i].self_spin(.005);
                    ufo_2[i].draw();
                    break;
                }
                case 3: {
                    rkt_2[i].animate();
                    rkt_2[i].draw();
                    break;
                }
                default:;
            }
        }
    }check_2++;
    return empty;
}
