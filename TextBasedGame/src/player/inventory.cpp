#include <iostream>
#include "inventory.h"

using namespace std;

//Getters
Item* Inventory::getItems(){
    return items[32];
}

//Auxiliary functions
void Inventory::addItem(Item* items[], Item* item){
    for (int i = 0; i < 32; i++){
        if (items[i] == nullptr){
            items[i] = item;
            return;
        }
    }
}

Item* Inventory::getItem(Item* items[], Item* item){
    for (int i = 0; i < 32; i++){
        if (items[i]->getItemId() == item->getItemId()){
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