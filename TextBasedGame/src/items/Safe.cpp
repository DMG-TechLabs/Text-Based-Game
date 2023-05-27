#include "items.h"

#include "../../Text-Based-Game-Engine/Engine/src/engine.h"

bool isNumber(string s);

int Safe::getPasscode(){
    return passcode;
}

string Safe::getDescription(){
    return description;
}

void Safe::inspect(){
    println("An old locked safe", 0);
}

void Safe::unlock(){
    this->isLocked = false;
}

void Safe::enterPassword(){
    if(this->isLocked){
        if(this->enterPasscode()){
            println("Safe unlocked");
            return;
        }
        return;
    }
    println("Safe is already unlocked");
}

bool Safe::enterPasscode(){
    string passcode;
    print("Enter passcode: ");
    getline(cin, passcode);

    if(!isNumber(passcode)){
        println("Invalid passcode", 0);
        return false;
    }


    if(stoi(passcode) != this->getPasscode()) {
        println("Wrong passcode");
        return false;
    } else {
        this->unlock();
        return true;
    }
}

bool isNumber(string s){
    return !s.empty() && std::find_if(s.begin(), 
        s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
}