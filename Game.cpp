//
// Created by brasse on 2018-11-26.
//

#include <sys/stat.h>
#include <unistd.h>
#include <string>
#include <fstream>
#include <SDL2/SDL_video.h>

#include "Game.h"
#include "Object.h"


Game::Game() {

    SDL_Init(0);
    nrObjects = 0;
    nrButtons = 0;
    grid = *InitRect(&grid, 0, 0, 10, 10);

    SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, 0, &window, &renderer);

    SDL_Rect r;
    SDL_GetDisplayBounds(0, &r);

    SCREEN_WIDTH = (r.w/2);
    SCREEN_HEIGHT = (r.h/2);

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, 0, &window, &renderer);


    SDL_SetWindowTitle(window, gameTitel);
    TTF_Init();
    running = true;

    imageFiles[0] = "resource/image/star.png";
    imageRect[0] = *InitRect(&imageRect[0],0, 0, 100, 100);
    images[0] = Image(imageFiles[0], imageRect[0], renderer);

    imageFiles[1] = "resource/image/test.png";
    imageRect[1] = *InitRect(&imageRect[0],0, 0, 500, 600);
    images[1] = Image(imageFiles[1], imageRect[1], renderer);

    imageFiles[2] = "resource/image/exitButton.png";
    imageRect[2] = *InitRect(&imageRect[0],0, 0, 512, 512);
    images[2] = Image(imageFiles[2], imageRect[2], renderer);

    SDL_Rect playerDest;
    playerDest = *InitRect(&playerDest, 5, 5, 10, 10);

    objects[0] = Object(grid, playerDest, images[1]);
    nrObjects++;

    fontFiles[0] = "resource/font/Sans.ttf";
    fontFiles[1] = "resource/font/Runsten.ttf";

    SDL_Rect exitButtonDest;
    exitButtonDest = *InitRect(&exitButtonDest, 20, 20, 10, 10);
    Object exitButtonObject = Object(grid, exitButtonDest, images[2]);

    //objects[1] = exitButtonObject;

    SDL_Color tempColor;
    tempColor = *InitColor(&tempColor,20,20,20,255);
    TTF_Font *tempFont = TTF_OpenFont(fontFiles[0].c_str(), 24);
    buttons[0] = Button("Exit", 125, 220, tempColor, tempFont, exitButtonObject);
    nrButtons++;



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
            if (e.key.keysym.sym == SDLK_w) {cout << "Key w up" << endl; objects[0].move(0, -10);}
            if (e.key.keysym.sym == SDLK_s) {cout << "Key s up" << endl; objects[0].move(0, 10);}

            if (e.key.keysym.sym == SDLK_d) {cout << "Key d up" << endl; objects[0].move(10, 0);}
            if (e.key.keysym.sym == SDLK_a) {cout << "Key a up" << endl; objects[0].move(-10, 0);}
        }
        SDL_GetMouseState(&mousex, &mousey);
        if (e.type == SDL_MOUSEBUTTONDOWN)
        {
            if (e.key.keysym.sym == SDL_BUTTON_LEFT) {}
            cout << "X: " << mousex << " Y: " << mousey << endl;
            SDL_DisplayMode DM;
            SDL_Rect r;
            //SDL_GetCurrentDisplayMode(0, &DM);
            SDL_GetDesktopDisplayMode(0, &DM);

            SDL_GetDisplayBounds(0, &r);

            //SCREEN_WIDTH = (DM.w/2);
            //SCREEN_HEIGHT = (DM.h/2);

            cout << r.w << endl;
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

    for (int i = 0; i < nrButtons; ++i) { buttons[i].draw(renderer); }

    draw("Test av font", 20, 30, 0, 255, 0, 24, 1);

    for (int i = 0; i < nrObjects; ++i) { objects[i].draw(renderer); }



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
            fontFile = fontFiles[0];
                 break;
        case 2:
            fontFile = fontFiles[1];
            break;
        default:
            fontFile = fontFiles[0];
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
        cout << fontFile << endl;
    }


}

bool Game::fileExist (const std::string& name) {
    struct stat buffer;
    return (stat (name.c_str(), &buffer) == 0);
}

SDL_Rect *Game::InitRect(SDL_Rect *Rect, int XPos, int YPos, int Width, int Height) {
    Rect->h = Height;
    Rect->w = Width;
    Rect->x = XPos;
    Rect->y = YPos;
    return Rect;
}

SDL_Color *Game::InitColor(SDL_Color *color, int R, int G, int B, int A) {
    color->a = A;
    color->b = B;
    color->g =G;
    color->r = R;
    return color;
}
