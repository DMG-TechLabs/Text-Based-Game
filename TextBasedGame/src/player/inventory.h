#pragma once

#include "../item/item.h"

#define INVENTORY_SIZE 32

class Inventory{

    private:
        Item item[INVENTORY_SIZE];

    public:
        Inventory(){}

        ~Inventory(){}

        Inventory(Item item[]){}

        void setItem(Item item[]);

        Item getItem();       
};