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
    
    for(int i=0;i<elem.size();i++){
        elem[i].setAnchor(p0);
    }
}
