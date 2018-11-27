

#include <iostream>
//#include <SDL2/SDL.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Game.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

#define IMG_PATH "/home/brasse/Regin-mountain-of-treasures/resource/image/test.png"

int FPS = 50;    // Assign a FPS
int NextTick , interval ;

// Initialize FPS_Fn( )
void FPS_Initial(void) {
    NextTick = 0 ;
    interval = 1 * 1000 / FPS ;
    return;
}

// Frame Per Second Function  , put this in a loop
void FPS_Fn(void) {
    if ( NextTick > SDL_GetTicks( ) ) SDL_Delay( NextTick - SDL_GetTicks( ) );
    NextTick = SDL_GetTicks( ) + interval ;
    return;
}


int oldMain(int argc, char* argv []) {
    SDL_Window* window = NULL;
    SDL_Surface* screenSurface = NULL;

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
    //SDL_Texture *img = NULL;
    SDL_Surface *image;

    SDL_Window* Main_Window;
    SDL_Renderer* Main_Renderer;
    SDL_Surface* Loading_Surf;
    SDL_Texture* Background_Tx;
    SDL_Texture* BlueShapes;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        fprintf(stderr, "could not initialize sdl2: %s\n", SDL_GetError());
        return 1;
    }
    window = SDL_CreateWindow(
            "hello_sdl2",
            SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
            SCREEN_WIDTH, SCREEN_HEIGHT,
            SDL_WINDOW_SHOWN
    );
    if (window == NULL) {
        fprintf(stderr, "could not create window: %s\n", SDL_GetError());
        return 1;
    }

    screenSurface = SDL_GetWindowSurface(window);
    SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
    //SDL_UpdateWindowSurface(window);

        bool running = true;
        const int FPS = 30;

    //SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);

        Uint32 start;
        SDL_Rect rect;
        rect.x = 10;
        rect.y = 100;
        rect.w = 20;
        rect.h = 20;
        Uint32 color = SDL_MapRGB(screenSurface->format, 0x444444,0xff,0xff);
        Uint32 color2 = SDL_MapRGB(screenSurface->format, 0x888888,0,0);

    image = SDL_LoadBMP(IMG_PATH); // loads image

    SDL_BlitSurface(image, NULL, screenSurface, NULL); // blit it to the screen
    SDL_FreeSurface(image);



    while(running) {
            start = SDL_GetTicks();
            SDL_Event event;



            while( SDL_PollEvent( &event ) ){
                switch( event.type ){
                    case SDL_KEYDOWN:
                        switch( event.key.keysym.sym ){
                            case SDLK_UP:
                                rect.y = rect.y - 10;
                                break;
                            case SDLK_DOWN:
                                rect.y = rect.y + 10;
                                break;
                            case SDLK_LEFT:
                                rect.x = rect.x - 10;
                                break;
                            case SDLK_RIGHT:
                                rect.x = rect.x + 10;
                                break;
                            case SDLK_ESCAPE:
                                running = 0 ;
                                break;
                            default:
                                break;
                        } // switch( event.key.keysym.sym ){ END
                        break; // case SDL_KEYDOWN: END
                    case SDL_QUIT:
                        running = 0;
                        break;
                    default:
                        break;
                } // switch( event.type ){ END
            } // while( SDLK_PollEvent( &event ) ){ END


            SDL_FillRect(screenSurface, &screenSurface->clip_rect, color);
            SDL_FillRect(screenSurface, &rect, color2);



            SDL_UpdateWindowSurface(window);




            if(1000/FPS > SDL_GetTicks()-start) {
                SDL_Delay(1000/FPS-(SDL_GetTicks()-start));
            }
        }
        SDL_Quit();


    return 0;
}