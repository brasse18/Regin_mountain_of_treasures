//
// Created by brasse on 2018-12-12.
//

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Image.h"
#include "Object.h"

#ifndef REGIN_MOUNTAIN_OF_TREASURES_GAMEMODONE_H
#define REGIN_MOUNTAIN_OF_TREASURES_GAMEMODONE_H

using namespace std;

class GameModOne {
private:
    Image* images;
    int imagesSize;

    int nrObjects;
    Object objects[10];


public:
    GameModOne(Image* images, int imagesSize, SDL_Rect grid);
    void draw(SDL_Renderer* renderer);
    void drawMap(SDL_Renderer* renderer, SDL_Rect drawAria);
    void input(SDL_Event e);
};


#endif //REGIN_MOUNTAIN_OF_TREASURES_GAMEMODONE_H
