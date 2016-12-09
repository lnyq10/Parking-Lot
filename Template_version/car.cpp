#include "car.h"
#include <iostream>

Car::Car(float s, float x, float y)
{
    anchor=Vec(0,0);

    static float scale=250;

    elem.clear();
    vector <Vec> _ceil;
    _ceil.clear();
    _ceil.push_back(Vec(-22/scale,10/scale));
    _ceil.push_back(Vec(-10/scale,27/scale));
    _ceil.push_back(Vec(10/scale,27/scale));
    _ceil.push_back(Vec(22/scale,10/scale));
    Poly ceil(_ceil);
    ceil.randomColor();
    ceil.setAnchor(anchor);
    elem.push_back(ceil);

    vector <Vec> _body;
    _body.clear();
    _body.push_back(Vec(-40/scale, 10/scale));
    _body.push_back(Vec(-40/scale, -10/scale));
    _body.push_back(Vec(40/scale, -10/scale));
    _body.push_back(Vec(40/scale, 10/scale));
    Poly body(_body);
    body.randomColor();
    body.setAnchor(anchor);
    elem.push_back(body);

    Poly wheel_left(Vec(-20/scale,-10/scale),10/scale);
    wheel_left.randomColor();
    wheel_left.setAnchor(Vec(-20/scale,-10/scale));
    elem.push_back(wheel_left);

    Poly wheel_right(Vec(20/scale,-10/scale),10/scale);
    wheel_right.fillColor(wheel_left);
    wheel_right.setAnchor(Vec(20/scale,-10/scale));
    elem.push_back(wheel_right);
    
    vector <Vec> _pool;

    _pool.clear();
    _pool.push_back(Vec( -19.5/scale, 0/scale));
    _pool.push_back(Vec( -20.5/scale, 0/scale));
    _pool.push_back(Vec( -20.5/scale,-20/scale));
    _pool.push_back(Vec( -19.5/scale,-20/scale));
    Poly pool_left_1(_pool);
    pool_left_1.randomColor();
    pool_left_1.setAnchor(wheel_left.getAnchor());
    elem.push_back(pool_left_1);
    pool_1=&elem.back();

    _pool.clear();
    _pool.push_back(Vec(-30/scale, -9.5/scale));
    _pool.push_back(Vec(-30/scale, -10.5/scale));
    _pool.push_back(Vec(-10/scale, -10.5/scale));
    _pool.push_back(Vec(-10/scale, -9.5/scale));
    Poly pool_left_2(_pool);
    pool_left_2.fillColor(pool_left_1);
    pool_left_2.setAnchor(wheel_left.getAnchor());
    elem.push_back(pool_left_2);
    pool_2=&elem.back();

    _pool.clear();
    _pool.push_back(Vec( 19.5/scale, 0/scale));
    _pool.push_back(Vec( 20.5/scale, 0/scale));
    _pool.push_back(Vec( 20.5/scale,-20/scale));
    _pool.push_back(Vec( 19.5/scale,-20/scale));
    Poly pool_right_1(_pool);
    pool_right_1.fillColor(pool_left_1);
    pool_right_1.setAnchor(wheel_right.getAnchor());
    elem.push_back(pool_right_1);
    pool_3=&elem.back();

    _pool.clear();
    _pool.push_back(Vec(30/scale, -9.5/scale));
    _pool.push_back(Vec(30/scale, -10.5/scale));
    _pool.push_back(Vec(10/scale, -10.5/scale));
    _pool.push_back(Vec(10/scale, -9.5/scale));
    Poly pool_right_2(_pool);
    pool_right_2.fillColor(pool_left_1);
    pool_right_2.setAnchor(wheel_right.getAnchor());
    elem.push_back(pool_right_2);
    pool_4=&elem.back();

    zoom(s);
    move(Vec(x,y));
    rotate(PI/2,anchor);
}

void Car::animate()
{
    float A=-0.3;
    pool_1->rotate(A);
    pool_2->rotate(A);
    pool_3->rotate(A);
    pool_4->rotate(A);
}
