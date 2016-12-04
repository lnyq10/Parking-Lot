#ifndef PARKING_LOT_FIELD_H
#define PARKING_LOT_FIELD_H

#include "fig.h"

class Field : public Group{
public:
    Field();
    void switchDoor();
    void draw();
private:
    std::vector<Line> lines;
};

#endif //PARKING_LOT_FIELD_H
