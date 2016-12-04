#include "fig.h"


class Car: public Group{
private:
    float rotate_angle;
    Poly* pool_1; Poly* pool_2; Poly* pool_3; Poly* pool_4;
public: 
    Car(float x,float y，float angle=0);
    void rotate_wheel(float angle);
    float get_rotate_angle(){ return rotate_angle; }
    ~Car(){};
};
