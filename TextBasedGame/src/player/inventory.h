#pragma once

#include "../item/item.h"

class Inventory {
private:
    Item* items[32];
    int itemCount;
public: 
    Inventory();
    //~Inventory();
    Inventory(Item* item[]);
    void addItem(Item* item);
    Item getItem();
    int getItemCount();
};
