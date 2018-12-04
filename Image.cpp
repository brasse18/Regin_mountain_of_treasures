//
// Created by brasse on 2018-11-28.
//
#include <sys/stat.h>
#include <fstream>

#include "Image.h"

Image::Image(string imageFile, SDL_Rect src, SDL_Renderer *renderer) {
    if(fileExist(imageFile))
    {
        this->imageFile = imageFile;
        this->src = src;
        SDL_Surface* surf = IMG_Load(imageFile.c_str());
        tex = SDL_CreateTextureFromSurface(renderer, surf);
    } else {
        cout << "Image file not found" << endl;
        cout << imageFile << endl;
    }

}

SDL_Texture *Image::getTexture() {
    return tex;
}

Image::Image() {

}

SDL_Rect *Image::getSrc() {
    return &src;
}

bool Image::fileExist (const std::string& name) {
    struct stat buffer;
    return (stat (name.c_str(), &buffer) == 0);
}
