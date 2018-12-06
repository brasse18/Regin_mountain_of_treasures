//
// Created by brasse on 2018-12-06.
//

#include "Audio.h"

Audio::~Audio() {
    SDL_CloseAudioDevice(deviceID);
    SDL_FreeWAV(wavBuffer);
}

Audio::Audio() {

}

void Audio::loade(const char *fileName) {
    if (!fileExist(fileName))
    {
        cout << "audio file not found" << endl << fileName << endl;
    }
    SDL_LoadWAV(fileName, &wavSpec, &wavBuffer, &wavLength);
    deviceID = SDL_OpenAudioDevice(NULL, 0, &wavSpec, NULL, 0);
}

void Audio::play() {
    SDL_QueueAudio(deviceID, wavBuffer, wavLength);
    SDL_PauseAudioDevice(deviceID, 0);
}

bool Audio::fileExist (const std::string& name) {
    struct stat buffer;
    return (stat (name.c_str(), &buffer) == 0);
}
