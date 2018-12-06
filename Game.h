//
// Created by brasse on 2018-11-26.
//

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "Object.h"
#include "Button.h"
#include "Image.h"
#include "Audio.h"


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
    SDL_Rect grid;

    int nrObjects;
    Object objects[10];

    int nrButtons;
    Button buttons[2];

    Image images[3];
    string imageFiles[3];
    SDL_Rect imageRect[3];

    string fontFiles[2];
    enum gameMode {
        startMenu, gameRun
    };

    gameMode renderMode;

    Audio effect;


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
    SDL_Rect *InitRect(SDL_Rect *Rect, int XPos, int YPos, int Width, int Height);
    SDL_Color *InitColor(SDL_Color *color, int R, int G, int B, int A);
};


#endif //REGIN_MOUNTAIN_OF_TREASURES_GAME_H
