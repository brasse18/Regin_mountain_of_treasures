//
// Created by brasse on 2018-12-02.
//

#include "Button.h"

Button::Button(const char* msg, int textX, int textY, SDL_Color color, TTF_Font *font, Object object) {
    this->msg = msg;
    this->font = font;
    this->color = color;
    this->textPos.x = textX;
    this->textPos.y = textY;
    this->object = object;






}

void Button::draw(SDL_Renderer *renderer) {
    object.draw(renderer);
    //drawText(renderer);

}

Button::Button() {

}

void Button::drawText(SDL_Renderer *renderer) {

    surf = TTF_RenderText_Solid(font, msg, color);
    tex = SDL_CreateTextureFromSurface(renderer, surf);

    textRect.x = object.getDest().x + textPos.x;
    textRect.y = object.getDest().y + textPos.y;
    textRect.h=surf->h;
    textRect.w=surf->w;

    SDL_FreeSurface(surf);
    SDL_RenderCopy(renderer, tex, NULL, &textRect);
}

Button::~Button() {
    SDL_DestroyTexture(tex);
    TTF_CloseFont(font);
}
