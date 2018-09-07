//
// Created by brasse on 2018-09-07.
//

#ifndef REGIN_MOUNTAIN_OF_TREASURES_VECTOR_H
#define REGIN_MOUNTAIN_OF_TREASURES_VECTOR_H

#include <iostream>

using namespace std;

class Vector {
private:
    int x;
    int y;
public:
    Vector(int x = 0, int y = 0);
    void  setX(int x);
    void setY(int y);
    int getX();
    int getY();
};


#endif //REGIN_MOUNTAIN_OF_TREASURES_VECTOR_H
