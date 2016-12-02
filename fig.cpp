//g++ part2.cpp fig.h fig.cpp -lGL -lGLU -lglut

#include "fig.h"
#include <GL/glut.h>
#include <cmath>
#include <cstdlib>

const float scale=800;

Poly::Poly(Vec a,float radius,bool isHalf)
{
	r=g=b=0;
	anchor=a;
	points.clear();
	int n=50;
	float angle=(isHalf)?(PI):(2*PI);
	for(int i=0;i<n;++i)
	{
		Vec p(radius*cos(angle/n*i),radius*sin(angle/n*i));
		points.push_back(p+anchor);
	}
}

Poly::Poly(vector <Vec> p)
{
	r=g=b=0;
	points=p;
	for(int i=0;i<points.size();++i)
	{
		anchor=anchor+points[i];
	}
	anchor=anchor*(1/points.size());//Center
}

void Poly::draw()
{
	int n=50;
	glColor3f(r,g,b);
	glBegin(GL_POLYGON);//GL_LINE_LOOP
	{
		for(int i=0;i<points.size();++i)
		{
			glVertex2f(points[i].getX(),points[i].getY());
		}
	}
	glEnd();
}

void Poly::move(Vec dir)
{
	anchor=anchor+dir;
}

void Poly::rotate(float A)
{
	for(int i=0;i<points.size();++i)
	{
		points[i]=((points[i]-anchor)<<A)+anchor;
	}
}

void Poly::zoom(float k)
{
	for(int i=0;i<points.size();++i)
	{
		points[i]=(points[i]-anchor)*k+anchor;
	}
}

void Poly::fillColor(float R,float G,float B)
{
	r=R;g=G;b=B;
}

float Poly::getR(){
    return r;
}

float Poly::getG(){
    return g;
}

float Poly::getB(){
    return b;
}

void Poly::fillColor(Poly &tar) {
    r = tar.getR();
    g = tar.getG();
    b = tar.getB();
}


void Poly::randomColor() {
	r = (float)rand() / RAND_MAX;
	g = (float)rand() / RAND_MAX;
	b = (float)rand() / RAND_MAX;
}

void Group::addFig(Poly &newFig)
{
	elem.push_back(newFig);
	elem[elem.size()-1].setAnchor(anchor);
}

void Group::draw()
{
	for(int i=0;i<elem.size();++i)
	{
		elem[i].draw();
	}
}

void Group::move(Vec dir)
{
	for(int i=0;i<elem.size();++i)
	{
		elem[i].move(dir);
	}
}

void Group::rotate(float A)
{
	for(int i=0;i<elem.size();++i)
	{
		elem[i].rotate(A);
	}
}

void Group::zoom(float k)
{
	for(int i=0;i<elem.size();++i)
	{
		elem[i].zoom(k);
	}
}
