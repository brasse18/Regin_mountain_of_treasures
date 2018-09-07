//
// Created by brasse on 2018-09-07.
//

#ifndef REGIN_MOUNTAIN_OF_TREASURES_POINT_H
#define REGIN_MOUNTAIN_OF_TREASURES_POINT_H


class Point {
private:
    int x;
    int y;
private:
    Point(int x = 0, int y = 0);
    void  setX(int x);
    void setY(int y);
    int getX();
    int getY();

};


#endif //REGIN_MOUNTAIN_OF_TREASURES_POINT_H
