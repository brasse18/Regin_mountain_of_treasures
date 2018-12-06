//
// Created by brasse on 2018-12-02.
//

#include "Button.h"

Button::Button(const char* msg, int textX, int textY, SDL_Color color, string fontFile, int fontSize, Object object, ButtonType buttonType) {
    this->msg = msg;
    this->color = color;
    this->textPos.x = textX;
    this->textPos.y = textY;
    this->object = object;
    this->fontFile = fontFile;
    this->fontsize = fontSize;
    this->buttonType = buttonType;

}

void Button::draw(SDL_Renderer *renderer) {
    object.draw(renderer);
    drawText(renderer);

}

Button::Button() {

}

void Button::drawText(SDL_Renderer *renderer) {

    SDL_Surface* surf;
    SDL_Texture* tex;
    TTF_Font *font = TTF_OpenFont(fontFile.c_str(), fontsize);

    surf = TTF_RenderText_Solid(font, msg, color);
    tex = SDL_CreateTextureFromSurface(renderer, surf);


    textRect.x = object.getDest().x + textPos.x - surf->w/2;
    textRect.y = object.getDest().y + textPos.y - surf->h/2;
    textRect.h=surf->h;
    textRect.w=surf->w;

    SDL_FreeSurface(surf);
    SDL_RenderCopy(renderer, tex, NULL, &textRect);
    SDL_DestroyTexture(tex);
    TTF_CloseFont(font);
}

Button::~Button() {

}

ButtonType Button::getButtonType() {
    return buttonType;
}

click Button::isClickt(int x, int y) {
    click out = up;
    //cout << object.getDest().x << " " << object.getDest().y << endl;
    //cout << object.getDest().w << " " << object.getDest().h << endl << endl;
    if (object.getDest().y < y && object.getDest().y + object.getDest().h > y &&
        object.getDest().x < x && object.getDest().x + object.getDest().w > x) {
        out = down;
    }

    return out;
}
