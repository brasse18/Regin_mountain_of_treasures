//
// Created by brasse on 2018-12-22.
//
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Object.h"
#include "Image3D.h"
#include "Vecktor3D.h"

#ifndef REGIN_MOUNTAIN_OF_TREASURES_MAPPBLOCK_H
#define REGIN_MOUNTAIN_OF_TREASURES_MAPPBLOCK_H


class MappBlock {
private:
    Image3D sprit;
    Object topTex;
    Object sideTex;
    Vecktor3D dim;
    MappBlock(SDL_Renderer);
    MappBlock();
    void drawTop(SDL_Renderer *renderer, int x, int y);
    void drawSide(SDL_Renderer *renderer, int x, int y);

};


#endif //REGIN_MOUNTAIN_OF_TREASURES_MAPPBLOCK_H
