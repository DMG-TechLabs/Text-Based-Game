#include "player.h"
#include "inventory.h"

//Setters getters
void Player::setInventory(Inventory inventory){
    this -> inventory = inventory;
}

Inventory Player::getInventory(){
    return inventory;
}

void Player::setName(string name){
    this -> name = name;
}

string Player::getName(){
    return name;
}

vector<int> Player::getStats(){
    return stats;
}