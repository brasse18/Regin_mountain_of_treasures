//
// Created by brasse on 2018-11-26.
//

#include <sys/stat.h>
#include <unistd.h>
#include <string>
#include <fstream>

#include "Game.h"
#include "Object.h"


Game::Game() {

    SDL_DisplayMode DM;
    SDL_GetCurrentDisplayMode(0, &DM);
    //SCREEN_WIDTH = (DM.w/2);
    //SCREEN_HEIGHT = (DM.h/2);

    SDL_Init(0);
    SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, 0, &window, &renderer);
    SDL_SetWindowTitle(window, gameTitel);
    TTF_Init();
    running = true;

    gube.setDest(50, 50, 100, 100);
    gube.setSource(0, 0, 100, 100);
    gube.setImage("resource/image/star.png", renderer);

    loop();
}

Game::~Game() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    //Destroy Font
    TTF_Quit();
}

void Game::loop() {

    while (running) {

        lastFrame=SDL_GetTicks();
        static int lastTime;
        if(lastFrame >= (lastTime+1000)) {
            lastTime=lastFrame;
            frameCount=0;
        }



        render();
        input();
        update();
    }
}

void Game::update() {

}

void Game::input() {
    SDL_Event e;
    while (SDL_PollEvent(&e))
    {
        if (e.type == SDL_QUIT) {running = false; cout << "Quit Game" << endl;}
        if (e.type == SDL_KEYDOWN) {
            if (e.key.keysym.sym == SDLK_ESCAPE) running=false;
            if (e.key.keysym.sym == SDLK_w) {cout << "Key w down" << endl;}
        }
        if (e.type == SDL_KEYUP) {
            if (e.key.keysym.sym == SDLK_w) {cout << "Key w up" << endl; gube.move(0, -10);}
            if (e.key.keysym.sym == SDLK_s) {cout << "Key s up" << endl; gube.move(0, 10);}

            if (e.key.keysym.sym == SDLK_d) {cout << "Key d up" << endl; gube.move(10, 0);}
            if (e.key.keysym.sym == SDLK_a) {cout << "Key a up" << endl; gube.move(-10, 0);}
        }
        SDL_GetMouseState(&mousex, &mousey);
        if (e.type == SDL_MOUSEBUTTONDOWN)
        {
            if (e.key.keysym.sym == SDL_BUTTON_LEFT) {}
            cout << "X: " << mousex << " Y: " << mousey << endl;
        }
    }

}

void Game::render() {
    SDL_SetRenderDrawColor(renderer, 100, 100, 100, 100);
    SDL_Rect rect;
    rect.x=rect.y=0;
    rect.w=SCREEN_WIDTH;
    rect.h=SCREEN_HEIGHT;
    SDL_RenderFillRect(renderer, &rect);

    draw(gube);
    draw("Test av font", 20, 30, 0, 255, 0, 24, 1);

    frameCount++;
    int timerFPS = SDL_GetTicks()-lastFrame;
    if(timerFPS<(1000/60)) {
        SDL_Delay((1000/60)-timerFPS);
    }

    SDL_RenderPresent(renderer);
}

void Game::draw(Object o) {
    SDL_Rect dest = o.getDest();
    SDL_Rect src = o.getSource();
    SDL_RenderCopyEx(renderer, o.getTex(), &src, &dest, 0, NULL, SDL_FLIP_NONE);
}

void Game::draw(const char* msg, int x, int y, int r, int g, int b, int size, int fontNr) {

    string fontFile = "";
    switch(fontNr) {
        case 1:
            fontFile = "resource/font/Sans.ttf";
                 break;
        case 2:
            fontFile = "resource/font/Runsten.ttf";
            break;
        default:
            fontFile = "resource/font/Sans.ttf";
                 break;
    }


    if (fileExist(fontFile))
    {
        SDL_Surface* surf;
        SDL_Texture* tex;
        TTF_Font *font = TTF_OpenFont(fontFile.c_str(), size);
        SDL_Color color;
        color.r = r;
        color.g = g;
        color.b = b;
        color.a = 255;

        SDL_Rect rect;
        surf = TTF_RenderText_Solid(font, msg, color);
        tex = SDL_CreateTextureFromSurface(renderer, surf);

        rect.x = x;
        rect.y = y;
        rect.h=surf->h;
        rect.w=surf->w;

        SDL_FreeSurface(surf);
        SDL_RenderCopy(renderer, tex, NULL, &rect);
        SDL_DestroyTexture(tex);
        TTF_CloseFont(font);
    } else {
        cout << "can not find the font file" << endl;
    }


}

bool Game::fileExist (const std::string& name) {
    struct stat buffer;
    return (stat (name.c_str(), &buffer) == 0);
}