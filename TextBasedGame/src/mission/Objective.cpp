#include "Objective.h"

void Objective::setDescription(string description){
    this->description = description;
}

string Objective::getDescription(){
    return description;
}

int Objective::getCompletedObjectives(){
    return completed_objectives;
}

void Objective::setStatus(bool complete){
    this->completed = completed;
}

bool Objective::isCompleted(){
    return completed;
}