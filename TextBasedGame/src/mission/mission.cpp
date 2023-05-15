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
    int completed_objectives = 0;

    for(int i = 0; i < objectives.size(); i++){
        if(objectives.at(i).isCompleted()){
            completed_objectives++;
            continue;
        }
        break;
    }

    if(completed_objectives == objectives.size() - 1){ 
        Mission::setStatus(true);
        return completed;
    }

    return completed;
}