#ifndef _LOCUS_H
#define _LOCUS_H

#include "fig.h"
#include "UFO.h"
#include "car.h"
#include "rocket.h"

#include <iostream>

template <class T> void go(T &obj,float &dist,int n,Vec &target)
{
	float static angle=0;
	obj.animate();
	if(n<5)
	{
		if(0<=dist && dist<=0.6)
		{
			dist+=obj.move(Vec(0,0.01));
			return;
		}
		if(0.6<dist && dist<=0.81)
		{
			dist+=obj.rotate(-0.1,Vec(-0.75,0));
			return;
		}
		if(0.81<dist && obj.getAnchor().getX()<target.getX()+0.11 && angle==0)
		{
			dist+=obj.move(Vec(0.01,0));
			return;
		}
		if(angle<PI/2)
		{
			obj.rotate(0.1,Vec(0.15,0.11)+target);
			angle+=0.1;
			return;
		}
		if(angle>=PI/2 && obj.getAnchor().getY()>=target.getY())
		{
			obj.move(Vec(0,-0.01));
			return;
		}
	}
	else
	{
		if(0<=dist && dist<=1)
		{
			dist+=obj.move(Vec(0,0.01));
			return;
		}
		if(1<dist && dist<=1.21)
		{
			dist+=obj.rotate(-0.1,Vec(-0.75,0.4));
			return;
		}
		if(1.21<dist && obj.getAnchor().getX()<target.getX()+0.13 && angle==0)
		{
			dist+=obj.move(Vec(0.01,0));
			return;
		}
		if(angle<PI/2)
		{
			obj.rotate(-0.1,Vec(0.18,-0.11)+target);
			angle+=0.1;
			return;
		}
		if(angle>=PI/2 && obj.getAnchor().getY()<=target.getY())
		{
			obj.move(Vec(0,0.01));
			return;
		}
	}

}

#endif