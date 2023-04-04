#include "achievement.h"


//Setters getters
void Achievement::setName( string name ){ 
    this->name = name;}

std::string Achievement::getName(){
    return this->name;
}

void Achievement::setDescription( string description ){ 
    this->description = description;}

std::string Achievement::getDescription(){
    return this->description;
}

void Achievement::setUnlocked(bool unlocked){
    this->unlocked = unlocked;
}

bool Achievement::isUnlocked(){
    return this->unlocked;
}

void Achievement::unlock(){
    Achievement::setUnlocked(true);      
}