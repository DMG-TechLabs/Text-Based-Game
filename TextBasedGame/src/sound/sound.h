#pragma once

#include <string>
#include <iostream>
#include <cstring>

#include "soloud.h"
#include "soloud_wav.h"
#include "soloud_thread.h"

using namespace std;

class Sound{
    public:
        string name;
        string dir;
        SoLoud::Soloud soloud; // Engine core
        SoLoud::Wav sample;    // One sample
        int handle;

    ~Sound(){}
    Sound(){}
    Sound(string dir){
        this->dir = dir;

        soloud.init();

        char* char_array = new char[this->dir.length() + 1];
        strcpy(char_array, dir.c_str());
        
        sample.load(char_array);
    }
    Sound(string name, string dir){
        this->name = name;
        this->dir = dir;

        soloud.init();

        char* char_array = new char[this->dir.length() + 1];
        strcpy(char_array, dir.c_str());
        
        sample.load(char_array);
    }

    void play(float volume = 1.0f, float speed = 1.0f);
    void pause();
    void unpause();
    void terminate();
};

