//
// Created by brasse on 2019-01-22.
//

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <string>
#include <sys/stat.h>
#include <fstream>

#include "Image.h"

#ifndef REGIN_MOUNTAIN_OF_TREASURES_IMAGE3D_H
#define REGIN_MOUNTAIN_OF_TREASURES_IMAGE3D_H

using namespace std;

class Image3D {
private:
    string imageFile;
    SDL_Rect src;
    SDL_Texture* sidTex;
    SDL_Texture* topTex;

public:
    Image3D(string imageFile, SDL_Rect src, SDL_Renderer *renderer);
    Image3D();
    bool fileExist (const std::string& name);
    SDL_Rect *getSrc();

    Image getSideImage();
    Image getTopImage();
};


#endif //REGIN_MOUNTAIN_OF_TREASURES_IMAGE3D_H
