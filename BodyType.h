//
// Created by brasse on 2018-09-07.
//

#ifndef REGIN_MOUNTAIN_OF_TREASURES_BODYTYPE_H
#define REGIN_MOUNTAIN_OF_TREASURES_BODYTYPE_H

#include <iostream>
#include <libmng_types.h>

class BodyType {
private:
    int density = 0;
    int physicalState = 0;
public:
    BodyType(int density = 1, int physicalState = 1);
    float getSpeedBlock(BodyType type);


};


#endif //REGIN_MOUNTAIN_OF_TREASURES_BODYTYPE_H
