//
// Created by brasse on 2019-01-22.
//

#include "Image3D.h"

Image3D::Image3D(string imageFile, SDL_Rect src, SDL_Renderer *renderer) {
    if(fileExist(imageFile))
    {
        this->imageFile = imageFile;
        this->src = src;
        SDL_Surface* topSurf = IMG_Load(imageFile.c_str());
        topTex = SDL_CreateTextureFromSurface(renderer, topSurf);

        SDL_Surface* sideSurf = IMG_Load(imageFile.c_str());
        sidTex = SDL_CreateTextureFromSurface(renderer, sideSurf);


    } else {
        cout << "Image file not found" << endl;
        cout << imageFile << endl;
    }
}

Image3D::Image3D() {

}

bool Image3D::fileExist (const std::string& name) {
    struct stat buffer;
    return (stat (name.c_str(), &buffer) == 0);
}

Image Image3D::getSideImage() {
    return Image();
}

Image Image3D::getTopImage() {
    return Image();
}
