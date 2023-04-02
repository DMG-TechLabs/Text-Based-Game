#include <iostream>
#include "inventory.h"

using namespace std;

//Constructors
Inventory::Inventory(){}

Inventory::~Inventory(){}

Inventory::Inventory(Item* items[]){
            for (int i = 0; i < 32; i++){
                this -> items[i] = items[i];
            }
        }

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