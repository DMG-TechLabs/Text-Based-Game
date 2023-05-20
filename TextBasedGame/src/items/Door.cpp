#include "items.h"

void Door::open(Player *player){
    if(!player->currentNode->isAccessible()){
        println("The door is locked");
    } else {
        isOpen = true;
        println("You opened the door");
    }
}

int Door::getPassword(){
    return password;
}

void Door::setPassword(int password){
    if(password > 10000) return;

    this->password = password;
}

void Door::enterPassword(int password){
    if(password != this->getPassword()) {
        println("Wrong password");
        return;
    } else {
        this->unlock();
        println("Door unlocked");
    }
}

void Door::unlock(){
    this->isOpen = true;
}