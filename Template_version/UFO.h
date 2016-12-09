#ifndef PARKING_LOT_UFO_H
#define PARKING_LOT_UFO_H

#include "fig.h"

class UFO : public Group
{
public:
    UFO(float scale, float x_ = 0.0, float y_ = 0.0);
    void animate();//Period(ms)
};

class Tel: public Poly
{
public:
    Tel(float s);
    Tel(){}
    ~Tel(){}
};

#endif //PARKING_LOT_UFO_H
