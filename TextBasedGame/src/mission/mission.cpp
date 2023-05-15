#include "mission.h"

void Mission::setName(string name){
    this->name = name;
}

string Mission::getName(){
    return name;
}

void Mission::setDescription(string description){
    this->description = description;
}

string Mission::getDescription(){
    return description;
}

void Mission::setStatus(bool completed){
    this->completed = completed;
}

bool Mission::isCompleted(){
    for(int i = 0; i < objectives.size(); i++){
        if(!objectives.at(i).isCompleted()) return false;
    }

    return true;
}