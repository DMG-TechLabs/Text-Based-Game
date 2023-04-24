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
    return NULL;
}

string* Inventory::getStacks(Item inventory[], string items[]){
    int item_count = 1;
    int k = 1;

    for (int i = 0; i < 32; i++){
        for (int j = 0; j < 32; j++){
            if (inventory[i].getItemId() == inventory[k].getItemId()){ 
                item_count++;
                k++;
                continue;
            }
            k++;
        }

        items[i] = to_string(item_count) + " " + inventory[i].getItemId();
        item_count = 1;
        k = i + 2;
    }

    return items;
}

//For progress
string Inventory::exportContents(){
    return "inventory here"; //an doyleuei h synarthsh getStacks() logika aythn tha pairneis
}

void Inventory::importContents(){
    
}