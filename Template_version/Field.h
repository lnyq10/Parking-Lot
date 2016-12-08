#ifndef PARKING_LOT_FIELD_H
#define PARKING_LOT_FIELD_H

#include "fig.h"

class Field : public Group{
public:
    Field();
    void draw();
    void open();
    void close();
    int getStatus();
private:
    std::vector<Line> lines;
    int status = 0;
    bool IsEmpty[2][7];
    vector <Vec> location_1;
    vector <Vec> location_2;

};

#endif //PARKING_LOT_FIELD_H
