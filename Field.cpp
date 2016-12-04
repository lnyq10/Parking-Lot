#include "Field.h"

Field::Field() {
    Line door({Vec(-0.95, -0.99), Vec(-0.75, -0.99)});
    door.fillColor(1,0,0);
    lines.push_back(door);

    Line wall({Vec(-0.75, -0.99), Vec(-0.75, -0.8), Vec(0.99, -0.8), Vec(0.99, 0.99), Vec(-0.99, 0.99), Vec(-0.99, -0.99)});
    wall.fillColor(0, 0, 0);
    lines.push_back(wall);

    for (int i = 0; i < 6; ++i){
        Line down( {Vec(-0.75+i*0.3, -0.8), Vec(-0.75+i*0.3, -0.5)} );
        down.fillColor(0,0,0);
        lines.push_back(down);

        Line up( {Vec(-0.75+i*0.3, 0.7), Vec(-0.75+i*0.3, 0.99)} );
        up.fillColor(0,0,0);
        lines.push_back(up);
    }

    Poly barrier({Vec(-0.7,-0.1), Vec(0.6,-0.1), Vec(0.6,0.1), Vec(-0.7,0.1),});
    barrier.randomColor();
    elem.push_back(barrier);


}

void Field::draw() {
    for (int i = 0; i < lines.size(); ++i){
        lines[i].draw();
    }
    for (int i = 0; i < elem.size(); ++i){
        elem[i].draw();
    }
}