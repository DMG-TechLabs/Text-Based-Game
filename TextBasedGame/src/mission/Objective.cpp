#include "mission.h"

void Objective::setDescription(string description){
    this->description = description;
}

string Objective::getDescription(){
    return description;
}

void Objective::setStatus(bool completed){
    this->completed = completed;
}

bool Objective::isCompleted(){
    return completed;
}