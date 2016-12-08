#ifndef PARKING_LOT_UFO_H
#define PARKING_LOT_UFO_H

#include "fig.h"

class UFO : public Group
{
public:
    UFO(float scale, float x_ = 0.0, float y_ = 0.0);
    void self_spin(float T);//Period(ms)
};

class Tel: public  Group{
public:
    Tel(float x, float y);
    Tel(){}
    void random_color();
};
#endif //PARKING_LOT_UFO_H
