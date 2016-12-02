#ifndef PARKING_LOT_ROCKET_H
#define PARKING_LOT_ROCKET_H

#include "fig.h"

class Rocket : public Group{
public:
    Rocket(float scale, float _x = 0.0, float _y = 0.0);
    void animate();
private:
    bool shrink = true;
    float relativeSize = 1.0;
};

#endif //PARKING_LOT_ROCKET_H
