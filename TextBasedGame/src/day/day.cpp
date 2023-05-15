#include "day.h"

bool Day::isCompleted(){
    for(int i = 0; i < missions.size(); i++){
        if(!missions.at(i).isCompleted()) return false;
    }

    return true;
}