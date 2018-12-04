//
// Created by brasse on 2018-11-26.
//

#include "Object.h"

void Object::setDest(SDL_Rect rec, int x, int y, int w, int h) {
    dest.x = rec.x*x;
    dest.y = rec.y*y;
    dest.h = rec.h*h;
    dest.w = rec.w*w;
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

void Object::setImage(Image image) {
    this->image = image;
}

void Object::move(int x, int y) {
    dest.x = dest.x+x;
    dest.y = dest.y+y;
}

Object::Object(SDL_Rect gridRec, SDL_Rect de, Image image) {
    this->image = image;
    dest.x = gridRec.x + gridRec.w * de.x;
    dest.y = gridRec.y + gridRec.h * de.y;

    dest.w = gridRec.w * de.w;
    dest.h = gridRec.h * de.h;
}

Object::Object() {

}

void Object::draw(SDL_Renderer* renderer) {

    SDL_RenderCopyEx(renderer, image.getTexture(), image.getSrc(), &dest, 0, NULL, SDL_FLIP_NONE);

}

SDL_Rect Object::getDest() {
    return dest;
}
