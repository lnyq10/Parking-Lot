#include "car.h"

Car::Car(float x, float y) {
    Vec p0(x,y); //inital position
    static float scale=100;elem.clear();
    vector <Vec> _ceil;_ceil.clear();
    _ceil.push_back(Vec(-22/scale,10/scale)+p0);
    _ceil.push_back(Vec(-10/scale,27/scale)+p0);
    _ceil.push_back(Vec(10/scale,27/scale)+p0);
    _ceil.push_back(Vec(22/scale,10/scale)+p0);
    Poly ceil(_ceil);ceil.fillColor(0.5, 0.2, 0.3);
    elem.push_back(ceil);

    vector <Vec> _body;_body.clear();
    _body.push_back(Vec(-40/scale, 10/scale)+p0);
    _body.push_back(Vec(-40/scale, -10/scale)+p0);
    _body.push_back(Vec(40/scale, -10/scale )+p0);
    _body.push_back(Vec(40/scale, 10/scale)+p0);
    Poly body(_body);body.fillColor(0.0, 1.0, 1.0);
    elem.push_back(body);

    Poly wheel_left(Vec(-20/scale,-10/scale)+p0,10/scale,false);wheel_left.fillColor(0.2, 0.1, 0.3);
    Poly wheel_right(Vec(20/scale,-10/scale)+p0,10/scale, false);wheel_right.fillColor(0.2,0.1,0.9);
    elem.push_back(wheel_left);
    elem.push_back(wheel_right);
    
    
    vector <Vec> _pool;_pool.clear();
    _pool.push_back(Vec((float)-19.5/scale,(float)0/scale)+p0);
    _pool.push_back(Vec((float)-20.5/scale,(float)0/scale)+p0);
    _pool.push_back(Vec((float)-20.5/scale,-20/scale)+p0);
    _pool.push_back(Vec((float)-19.5/scale,-20/scale)+p0);
    Poly pool_left_1(_pool);pool_left_1.fillColor(0.0,0.0,0.0);
    elem.push_back(pool_left_1);
    pool_1=&elem.back();

    _pool.clear();
    _pool.push_back(Vec(-30/scale,(float)-9.5/scale)+p0);
    _pool.push_back(Vec(-30/scale,(float)-10.5/scale)+p0);
    _pool.push_back(Vec(-10/scale,(float)-10.5/scale)+p0);
    _pool.push_back(Vec(-10/scale,(float)-9.5/scale)+p0);
    Poly pool_left_2(_pool);pool_left_2.fillColor(0.0,0.0,0.0);
    elem.push_back(pool_left_2);
    pool_2=&elem.back();

    _pool.clear();
    _pool.push_back(Vec((float)19.5/scale,(float)0/scale)+p0);
    _pool.push_back(Vec((float)20.5/scale,(float)0/scale)+p0);
    _pool.push_back(Vec((float)20.5/scale,-20/scale)+p0);
    _pool.push_back(Vec((float)19.5/scale,-20/scale)+p0);
    Poly pool_right_1(_pool);pool_left_1.fillColor(0.0,0.0,0.0);
    elem.push_back(pool_right_1);
    pool_3=&elem.back();

    _pool.clear();
    _pool.push_back(Vec(30/scale,(float)-9.5/scale)+p0);
    _pool.push_back(Vec(30/scale,(float)-10.5/scale)+p0);
    _pool.push_back(Vec(10/scale,(float)-10.5/scale)+p0);
    _pool.push_back(Vec(10/scale,(float)-9.5/scale)+p0);
    Poly pool_right_2(_pool);pool_left_2.fillColor(0.0,0.0,0.0);
    elem.push_back(pool_right_2);
    pool_4=&elem.back();
    
    for(int i=0;i<elem.size();i++){
        elem[i].setAnchor(p0);
    }   
}

void Car::rotate_wheel(float angle){
    static float scale=100;
    float x0=elem[0].getAnchor().getX();float y0=elem[0].getAnchor().getY();
    pool_1->setAnchor(Vec(-20/scale+x0,-10/scale+y0));
    pool_2->setAnchor(Vec(-20/scale+x0,-10/scale+y0));
    pool_3->setAnchor(Vec(20/scale+x0,-10/scale+y0));
    pool_4->setAnchor(Vec(20/scale+x0,-10/scale+y0));
    pool_1->rotate(angle);
    pool_2->rotate(angle);
    pool_3->rotate(angle);
    pool_4->rotate(angle);
    pool_1->setAnchor(Vec(x0,y0));
    pool_2->setAnchor(Vec(x0,y0));
    pool_3->setAnchor(Vec(x0,y0));
    pool_4->setAnchor(Vec(x0,y0));
}

