#include "fig.h"


class Car: public Group{
private:
    Poly* pool_1; Poly* pool_2; Poly* pool_3; Poly* pool_4;
public: 
    Car(float x,float y);
    void rotate_wheel(float angle);
    ~Car(){};
};
