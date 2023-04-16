#include "./sound.h"



void Sound::play(float volume, float speed){
    this->handle = soloud.play(sample);         // Play the sound
    soloud.setVolume(handle, volume);           // Set volume; 1.0f is "normal"
    soloud.setRelativePlaySpeed(handle, speed);
}

void Sound::pause(){
    soloud.setPause(handle, 1); 
}

void Sound::unpause(){
    soloud.setPause(handle, 0); 
}

void Sound::terminate(){
    soloud.stop(handle);
    soloud.deinit();
}