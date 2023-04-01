#include "player.h"
#include "inventory.h"

Player::Player(Inventory inventory, string name, int hunger){
    this -> inventory = inventory;
    this -> name = name;
    this -> hunger = hunger;
}

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

void Player::setHunger(int hunger){
    this -> hunger = hunger;
}

int Player::getHunger(){
    return hunger;
}
