//
// Created by brasse on 2018-12-02.
//

#include "Button.h"

Button::Button(string msg, int textX, int textY, SDL_Color color, TTF_Font *font) {
    this->msg = msg;
    this->font = font;
    this->color = color;
    this->textPos.x = textX;
    this->textPos.y = textY;

}

void Button::draw(SDL_Renderer *renderer) {
    cout << "b draw obj" << endl;
    objekt.draw(renderer);
    cout << "a draw obj" << endl;


    SDL_Rect rect;
    surf = TTF_RenderText_Solid(font, msg.c_str(), color);
    tex = SDL_CreateTextureFromSurface(renderer, surf);

    cout << "a font and font to tex" << endl;

    rect.x = objekt.getDest().x + textPos.x;
    rect.y = objekt.getDest().y + textPos.y;
    rect.h=surf->h;
    rect.w=surf->w;

    cout << "a rec pos" << endl;

    SDL_FreeSurface(surf);
    cout << "a free surf" << endl;
    SDL_RenderCopy(renderer, tex, NULL, &rect);
    cout << "a render text" << endl;
    SDL_DestroyTexture(tex);
    TTF_CloseFont(font);
}

Button::Button() {

}
