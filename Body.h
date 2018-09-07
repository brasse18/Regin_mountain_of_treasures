//
// Created by brasse on 2018-09-07.
//

#ifndef REGIN_MOUNTAIN_OF_TREASURES_BODY_H
#define REGIN_MOUNTAIN_OF_TREASURES_BODY_H

#include <iostream>
#include "Point.h"
#include "Vector.h"
#include "BodyType.h"

using namespace std;

class Body {
    Body(Vector vektor, Point point);
    float getSpeedToHere(BodyType bodyType);
    bool isBlocking(BodyType bodyType);
};


#endif //REGIN_MOUNTAIN_OF_TREASURES_BODY_H
