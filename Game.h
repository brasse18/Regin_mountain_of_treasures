//
// Created by brasse on 2018-11-26.
//

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "Object.h"

#ifndef REGIN_MOUNTAIN_OF_TREASURES_GAME_H
#define REGIN_MOUNTAIN_OF_TREASURES_GAME_H

using namespace std;

class Game {
private:
    int SCREEN_WIDTH = 640;
    int SCREEN_HEIGHT = 480;
    const char* gameTitel = "Regin Mountain of treasures";
    SDL_Renderer* renderer;
    SDL_Window* window;

    bool running;
    int frameCount, timerFPS, lastFrame;

    int mousex, mousey;

    Object gube;

public:
    Game();
    ~Game();
    void loop();
    void update();
    void render();
    void input();
    void draw(Object o);
    void draw(const char *msg, int x, int y, int r, int g, int b, int size, int fontNr);
    inline bool fileExist (const std::string& name);
};


#endif //REGIN_MOUNTAIN_OF_TREASURES_GAME_H
