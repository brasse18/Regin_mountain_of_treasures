//
// Created by brasse on 2018-12-02.
//

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>

#include "Image.h"
#include "Object.h"
#include "enum.h"

#ifndef REGIN_MOUNTAIN_OF_TREASURES_BUTTON_H
#define REGIN_MOUNTAIN_OF_TREASURES_BUTTON_H

using namespace menu;

class Button {
private:
    Object object;
    SDL_Color color;
    const char* msg;
    SDL_Point textPos;
    SDL_Rect textRect;

    string fontFile;
    int fontsize;

    ButtonType buttonType;


public:
    Button(const char* msg, int textX, int textY, SDL_Color color, string fontFile, int fontSize, Object objekt, ButtonType buttonType);
    Button();
    ~Button();
    void draw(SDL_Renderer* renderer);
    void drawText(SDL_Renderer* renderer);
    click isClickt(int x, int y);
    ButtonType getButtonType();




};


#endif //REGIN_MOUNTAIN_OF_TREASURES_BUTTON_H
