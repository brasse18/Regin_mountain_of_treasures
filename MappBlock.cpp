//
// Created by brasse on 2018-12-22.
//

#include "MappBlock.h"

MappBlock::MappBlock() {

}

void MappBlock::drawTop(SDL_Renderer *renderer, int x, int y) {
    topTex.draw(renderer);
}

void MappBlock::drawSide(SDL_Renderer *renderer, int x, int y) {
    sideTex.draw(renderer);
}
