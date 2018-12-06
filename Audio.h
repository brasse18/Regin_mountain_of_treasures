//
// Created by brasse on 2018-12-06.
//

#include <SDL2/SDL_audio.h>
#include <string>
#include <sys/stat.h>
#include <iostream>

#ifndef REGIN_MOUNTAIN_OF_TREASURES_AUDIO_H
#define REGIN_MOUNTAIN_OF_TREASURES_AUDIO_H

using namespace std;


class Audio {
public:
    Audio();
    ~Audio();
    void loade( const char* fileName);
    void play();
    bool fileExist (const std::string& name);

private:
    SDL_AudioSpec wavSpec;
    Uint32 wavLength;
    Uint8 *wavBuffer;
    SDL_AudioDeviceID deviceID;

};


#endif //REGIN_MOUNTAIN_OF_TREASURES_AUDIO_H
