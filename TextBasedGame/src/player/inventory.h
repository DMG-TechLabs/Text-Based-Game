#pragma once

#include "../item/item.h"

class Inventory {
    private:
        Item* items[32];
        int itemCount;
        
    public: 
        Inventory();
        //~Inventory();
        
        Inventory(Item* items[]){
            for (int i = 0; i < 32; i++){
                this -> items[i] = items[i];
            }
        };
        
        void addItem(Item item);
        Item* getItem();
        int getItemCount();
};
