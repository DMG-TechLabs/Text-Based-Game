#include <iostream>
#include "inventory.h"

using namespace std;

//Getters
Item* Inventory::getItem(){
    return items[32];
}

int Inventory::getItemCount(){
    return this->itemCount;
}

//Auxiliary functions
void Inventory::addItem(Item* item, int i){
    this->items[i] = item;
}

//For progress
string Inventory::exportContents(){
    return "inventory here"; //waiting for Inventory structure to finish
}

void Inventory::importContents(){
    
}