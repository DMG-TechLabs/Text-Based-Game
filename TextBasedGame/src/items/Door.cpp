#include "items.h"

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
    if(this->enterPasscode()){
        player->currentNode->unlock();
    }
}


bool Door::enterPasscode(){
    string passcode;
    print("Enter passcode: ");
    getline(cin, passcode);


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