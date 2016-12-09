#ifndef PARKING_LOT_CAR_H
#define PARKING_LOT_CAR_H

#include "fig.h"


class Car: public Group
{
private:
    float rotate_angle;
    Poly *pool_1, *pool_2, *pool_3, *pool_4;
public: 
    Car(float s,float x,float y);
    void animate();
    ~Car(){}
};

#endif