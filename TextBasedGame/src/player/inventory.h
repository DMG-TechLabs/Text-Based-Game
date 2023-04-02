#pragma once

#include "../item/item.h"

using namespace std;

class Inventory {
    private:
        Item* items[32];
        int itemCount;
        
    public: 
        Inventory();
        ~Inventory();
        Inventory(Item* items[]);
        
        void addItem(Item* item, int i);
        Item* getItem();
        int getItemCount();
};