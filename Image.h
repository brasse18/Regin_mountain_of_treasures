//
// Created by brasse on 2018-11-28.
//

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <string>

#ifndef REGIN_MOUNTAIN_OF_TREASURES_IMAGE_H
#define REGIN_MOUNTAIN_OF_TREASURES_IMAGE_H

using namespace std;

class Image {
private:
    string imageFile;
    SDL_Rect src;
    SDL_Texture* tex;

public:
    Image(string imageFile, SDL_Rect src, SDL_Renderer *renderer);
    Image();
    bool fileExist (const std::string& name);
    SDL_Texture *getTexture();
    SDL_Rect *getSrc();


};


#endif //REGIN_MOUNTAIN_OF_TREASURES_IMAGE_H
