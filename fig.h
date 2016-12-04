#ifndef _FIG_H
#define _FIG_H

#include <GL/glut.h>
#include <vector>
#include <cmath>
#include <iostream>
using std::vector;

const float PI=3.14159;

class Vec
{
private:
	float x,y;
public:
	Vec(float x_,float y_){x=x_;y=y_;}
	float getX(){return x;}
	float getY(){return y;}

	Vec operator + (Vec &v)
	{
		return Vec(x+v.getX(),y+v.getY());
	}

	Vec operator - (Vec &v)
	{
		return Vec(x-v.getX(),y-v.getY());
	}

	Vec operator * (float k)
	{
		return Vec(x*k,y*k);
	}

	float operator * (Vec &v)
	{
		return x*v.getX()+y*v.getY();
	}

	Vec operator << (float A)
	{
		return Vec(x*cos(A)-y*sin(A),x*sin(A)+y*cos(A));
	}

	Vec operator >> (float A)
	{
		return *this<<(-A);
	}

};

class Figure
{
protected:
	Vec anchor;
public:
	Figure():anchor(0,0){}

	Vec getAnchor() {return anchor;}
	void setAnchor(Vec a) {anchor=a;}
	virtual void draw()=0;
	virtual void move(Vec dir)=0;
	virtual void rotate(float A)=0;
	virtual void zoom(float k)=0;

	virtual ~Figure() {}
};

class Poly: public Figure
{
protected:
	vector <Vec> points;
	float r,g,b;
public:
	Poly(Vec a,float radius,bool isHalf=false);//Circle(or half)
	Poly(vector <Vec> p);//Poly
	Poly() {r=g=b=0;points.clear();}

	void draw();
	void move(Vec dir);
	void rotate(float A);
	void zoom(float k);
	void fillColor(float R,float G,float B);
    void fillColor(Poly &tar);
	void randomColor();
    float getR();
    float getG();
    float getB();

	~Poly() {}
};

class Line: public Poly{
public:
	Line(vector <Vec> p);
	void draw();
};

class Group : public Figure
{
protected:
	vector <Poly> elem;
public:
	Group(vector <Poly> &p) {elem=p;}
	Group() {elem.clear();}

	void addFig(Poly &newFig);
	void draw();
	void move(Vec dir);
	void rotate(float A);
	void zoom(float k);

	~Group() {}
};


#endif
