#include "items.h"

bool isNumber(const std::string& s);

void Door::open(Player *player){
    if(!player->currentNode->isAccessible() || this->isLocked){
        println("The door is locked");
    } else {
        isLocked = false;
        println("You opened the door");
    }
}

int Door::getPasscode(){
    return passcode;
}

void Door::setPasscode(int passcode){
    if(passcode > 10000) return;

    this->passcode = passcode;
}

void Door::enterPasscode(Player *player){
    if(this->isLocked){
        if(this->enterPasscode()){
            player->currentNode->unlock();
        }
        return;
    }
    println("The door is already unlocked");
}


bool Door::enterPasscode(){
    string passcode;
    print("Enter passcode: ");
    getline(cin, passcode);

    if(!isNumber(passcode)){
        println("Invalid passcode", 0);
        return false;
    }


    if(stoi(passcode) != this->getPasscode()) {
        println("Wrong password");
        return false;
    } else {
        this->unlock();
        println("Door unlocked");
        return true;
    }
}

void Door::unlock(){
    this->isLocked = false;
}



bool isNumber(const std::string& s){
    return !s.empty() && std::find_if(s.begin(), 
        s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
}