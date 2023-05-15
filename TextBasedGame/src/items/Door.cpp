#include "items.h"

void Door::open(Player *player){
    if(!player->currentNode->isAccessible()){
        println("The door is locked");
    } else {
        isOpen = true;
        println("You opened the door");
    }
}