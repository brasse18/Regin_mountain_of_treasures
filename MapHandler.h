//
// Created by brasse on 2018-12-17.
//

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "Object.h"
#include "Image.h"
#include "Audio.h"

#ifndef REGIN_MOUNTAIN_OF_TREASURES_MAPHANDLER_H
#define REGIN_MOUNTAIN_OF_TREASURES_MAPHANDLER_H

using namespace std;

class MapHandler {
public:
    class Vecktor3D
    {
    public:
        int x = 0;
        int y = 0;
        int z = 0;
        int h = 0;
        int w = 0;
        int d = 0;
        Vecktor3D(int x = 0, int y = 0, int z = 0, int h = 0, int w = 0, int d = 0){
            this->x = x;
            this->y = y;
            this->z = z;
            this->w = w;
            this->h = h;
            this->d = d;
        };
    };
    MapHandler();
    MapHandler(Image images[], int imagesSize);
    void draw(SDL_Renderer* renderer);
    void movePlayer(SDL_Rect grid, Object player, int x, int y);
    void makeMap(SDL_Rect grid, Vecktor3D mapVecktor);
    SDL_Rect *InitRect(SDL_Rect *Rect, int XPos, int YPos, int Width, int Height);
private:
    Vecktor3D mapVecktor;
    Object map[10][10][10];
    Image *images;
    int imagesSize;
    int playerY;



};


#endif //REGIN_MOUNTAIN_OF_TREASURES_MAPHANDLER_H
