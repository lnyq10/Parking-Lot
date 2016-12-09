#ifndef PARKING_LOT_FIELD_H
#define PARKING_LOT_FIELD_H

#include "fig.h"

class Field : public Group{
public:
    Field();
    void draw();
    void open();
    void close();
    void animate() {}
    int getStatus();
private:
    std::vector<Line> lines;
    int status = 0;
};

#endif //PARKING_LOT_FIELD_H
