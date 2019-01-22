//
// Created by brasse on 2018-12-17.
//

#include "MapHandler.h"

MapHandler::MapHandler(Image *images, int imagesSize) {
    this->images = images;
    this->imagesSize = imagesSize;

}

void MapHandler::draw(SDL_Renderer *renderer) {
    for (int z = 0; z < 10; ++z) {
        for (int x = 0; x < 10; ++x) {
            for (int y = 0; y < 10; ++y) {
                if (x == 0 || x == 9 || y == 0 || y == 9 && z == 1)
                {
                    map[x][y][z].draw(renderer);
                }
                if (z == 0)
                {
                    map[x][y][z].draw(renderer);
                }
            }
        }
    }

    for (int z = 0; z < 10; ++z) {
        for (int x = 0; x < 10; ++x) {
            map[x][playerY][z].move(500, (9*map[0][0][0].getDest().h-z*map[0][0][0].getDest().h)-playerY*map[0][0][0].getDest().h);
            map[x][playerY][z].draw(renderer);
            map[x][playerY][z].move(-500, -(9*map[0][0][0].getDest().h-z*map[0][0][0].getDest().h)+playerY*map[0][0][0].getDest().h);
        }
    }
}

void MapHandler::movePlayer(SDL_Rect grid, Object player, int x, int y) {
    this->playerY = player.getDest().y/50;
    if (player.getDest().x/50+x < 9 && player.getDest().x+x > 0)
    {
        player.move(x, y);
    }
}

void MapHandler::makeMap(SDL_Rect grid, Vecktor3D mapVecktor) {
    this->mapVecktor = mapVecktor;

    SDL_Rect tempReck;
    for (int z = 0; z < 10; ++z) {
        for (int x = 0; x < 10; ++x) {
            for (int y = 0; y < 10; ++y) {
                tempReck = *InitRect(&tempReck, x*5, y*5, 5, 5);

                if (x == 0 || x == 9 || y == 0 || y == 9 && z == 1)
                {
                    map[x][y][z] = Object(grid, tempReck, images[4]);
                }
                if (z == 0)
                {
                    map[x][y][z] = Object(grid, tempReck, images[5]);
                }
            }
        }
    }
}

SDL_Rect *MapHandler::InitRect(SDL_Rect *Rect, int XPos, int YPos, int Width, int Height) {
    Rect->h = Height;
    Rect->w = Width;
    Rect->x = XPos;
    Rect->y = YPos;
    return Rect;
}

MapHandler::MapHandler() {

}
