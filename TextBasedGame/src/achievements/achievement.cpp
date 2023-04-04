#include "achievement.h"


//Setters getters
void Achievement::setName( string name ){ 
    this->name = name;}

std::string Achievement::getName(){
    return this->name;
}

void Achievement::setUnlocked(bool unlocked){
    this->unlocked = unlocked;
}

bool Achievement::isUnlocked(){
    return this->unlocked;
}