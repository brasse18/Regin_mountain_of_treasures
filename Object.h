//
// Created by brasse on 2018-11-26.
//
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#ifndef REGIN_MOUNTAIN_OF_TREASURES_OBJECT_H
#define REGIN_MOUNTAIN_OF_TREASURES_OBJECT_H

using namespace std;

class Object {
private:
    SDL_Rect dest;
    SDL_Rect src;
    SDL_Texture* tex;
public:
    Object() {}
    SDL_Rect getDest() const { return dest;}
    SDL_Rect getSource() const { return src;}
    SDL_Texture* getTex() const { return tex;}

    void setDest(int x, int y, int w, int h);
    void setSource(int x, int y, int w, int h);
    void setImage(string filename, SDL_Renderer* renderer);

    void move(int x, int y);

};


#endif //REGIN_MOUNTAIN_OF_TREASURES_OBJECT_H
