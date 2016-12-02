#include <ctime>
#include <GL/freeglut.h>
#include "fig.h"
#include "car.h"

void TimeStep(int n)
{
    glutTimerFunc(25, TimeStep, 0);
    glutPostRedisplay();
}
void glDraw_car() {
    glClear(GL_COLOR_BUFFER_BIT);
    Car static mycar(0.5,0.5);
    mycar.move(Vec((float) -0.005, 0));
    mycar.rotate(1);
    mycar.draw();
    glutSwapBuffers();glFlush();
}


int main(int argc, char * argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowPosition(500, 500);
    glutInitWindowSize(800, 800);
    glutCreateWindow("OpenGL");
    glClearColor (1.0, 1.0, 1.0, 1.0);glLoadIdentity();
    //glutDisplayFunc(&display_main);
    glutDisplayFunc(&glDraw_car);
    glClearColor (1.0, 1.0, 1.0, 1.0);
    glutTimerFunc(25, TimeStep, 0);
    glutMainLoop();
    return 0;
}
