//
// Created by brasse on 2018-12-02.
//

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>

#include "Image.h"
#include "Object.h"

#ifndef REGIN_MOUNTAIN_OF_TREASURES_BUTTON_H
#define REGIN_MOUNTAIN_OF_TREASURES_BUTTON_H


class Button {
private:
    Object objekt;
    TTF_Font *font;
    SDL_Color color;
    string msg;
    SDL_Surface* surf;
    SDL_Texture* tex;
    SDL_Point textPos;


public:
    Button(string msg, int textX, int textY, SDL_Color color, TTF_Font *font);
    Button();
    void draw(SDL_Renderer* renderer);




};


#endif //REGIN_MOUNTAIN_OF_TREASURES_BUTTON_H
