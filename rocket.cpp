#include "rocket.h"

Rocket::Rocket(float scale, float _x, float _y) {
    anchor = Vec(_x, _y);

    Poly head_tri( {Vec(0,1), Vec(0.4, 0.7), Vec(-0.4, 0.7)} );
    head_tri.randomColor();
    elem.push_back(head_tri);

    Poly body( {Vec(0.4, 0.7), Vec(0.4, -0.7), Vec(-0.4, -0.7), Vec(-0.4, 0.7)} );
    body.randomColor();
    elem.push_back(body);

    Poly tail( {Vec(-0.32, -0.7), Vec(-0.38, -0.8), Vec(0.38, -0.8), Vec(0.32, -0.7)} );
    tail.randomColor();
    elem.push_back(tail);

    Poly leftWing( {Vec(-0.4, -0.7), Vec(-0.4, 0), Vec(-0.6, -0.7)} );
    leftWing.randomColor();
    elem.push_back(leftWing);

    Poly rightWing( {Vec(0.4, -0.7), Vec(0.4, 0), Vec(0.6, -0.7)} );
    rightWing.fillColor(leftWing);
    elem.push_back(rightWing);

    Poly leftWindow( {Vec(-0.2, 0.3), Vec(-0.3, 0.3), Vec(-0.3, 0.4), Vec(-0.2, 0.4)} );
    leftWindow.randomColor();
    elem.push_back(leftWindow);

    Poly rightWindow( {Vec(0.2, 0.3), Vec(0.3, 0.3), Vec(0.3, 0.4), Vec(0.2, 0.4)} );
    rightWindow.fillColor(leftWindow);
    elem.push_back(rightWindow);

    Poly door( {Vec(0.1, 0.2), Vec(0.1, -0.2), Vec(-0.1, -0.2), Vec(-0.1, 0.2)} );
    door.randomColor();
    elem.push_back(door);

    zoom(scale);
}

void Rocket::animate() {
    if (relativeSize < 0.6) shrink = false;
    if (relativeSize > 1) shrink = true;
    if (shrink){
        zoom(0.99);
        relativeSize *= 0.99;
    }else{
        zoom(1.01);
        relativeSize *= 1.01;
    }
}