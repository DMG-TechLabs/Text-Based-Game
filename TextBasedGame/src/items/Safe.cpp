#include "items.h"

#include "../../Text-Based-Game-Engine/Engine/src/engine.h"

int Safe::getPasscode(){
    return passcode;
}

void Safe::inspect(){
    println("An old locked safe");
}

void Safe::unlock(){
    this->isLocked = false;
}

bool Safe::enterPasscode(){
    return false;
}