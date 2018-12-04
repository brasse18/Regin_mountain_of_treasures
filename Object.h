//
// Created by brasse on 2018-11-26.
//
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Image.h"

#ifndef REGIN_MOUNTAIN_OF_TREASURES_OBJECT_H
#define REGIN_MOUNTAIN_OF_TREASURES_OBJECT_H

using namespace std;

class Object {
private:
    SDL_Rect dest;
    SDL_Rect src;
    SDL_Texture* tex;
    Image image;
public:
    Object(SDL_Rect gridRec, SDL_Rect de, Image image);
    Object();
    SDL_Rect getDest() const { return dest;}
    SDL_Rect getSource() const { return src;}
    SDL_Texture* getTex() const { return tex;}

    void setDest(SDL_Rect rec, int x, int y, int w, int h);
    void setSource(int x, int y, int w, int h);

    void setImage(string filename, SDL_Renderer* renderer);

    void move(int x, int y);

    void setImage(Image image);
    void draw(SDL_Renderer* renderer);

    SDL_Rect getDest();
};


#endif //REGIN_MOUNTAIN_OF_TREASURES_OBJECT_H
