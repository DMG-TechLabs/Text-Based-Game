#include "inventory.h"
#include "../item/item.h"

Inventory::Inventory(Item item[]){
    this -> item = item;
}

void Inventory::setItem(Item item[]){
    for(int i = 0; i < INVENTORY_SIZE; i++){
        this -> item[i] = item[i];
    }
}

Item Inventory::getItem(){
    return item[];
}
