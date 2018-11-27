//
// Created by brasse on 2018-11-26.
//

#include "Object.h"

void Object::setDest(int x, int y, int w, int h) {
    dest.x = x;
    dest.y = y;
    dest.w = w;
    dest.h = h;
}

void Object::setSource(int x, int y, int w, int h) {
    src.x = x;
    src.y = y;
    src.w = w;
    src.h = h;
}

void Object::setImage(string filename, SDL_Renderer *renderer) {
    SDL_Surface* surf = IMG_Load(filename.c_str());
    tex = SDL_CreateTextureFromSurface(renderer, surf);
}

void Object::move(int x, int y) {
    dest.x = dest.x+x;
    dest.y = dest.y+y;
}
