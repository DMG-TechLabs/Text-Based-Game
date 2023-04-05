#include <iostream>
#include "inventory.h"

using namespace std;

//Getters
Item* Inventory::getInventory(){
    return inventory[32];
}

//Auxiliary functions
void Inventory::addItem(Item* inventory[], Item* item){
    for (int i = 0; i < 32; i++){
        if (inventory[i] == nullptr){
            inventory[i] = item;
            return;
        }
    }
}

Item* Inventory::getItem(Item* inventory[], Item* item){
    for (int i = 0; i < 32; i++){
        if (inventory[i]->getItemId() == item->getItemId()){
            return item;
        }
    }
}

//For progress
string Inventory::exportContents(){
    return "inventory here"; //waiting for Inventory structure to finish
}

void Inventory::importContents(){
    
}