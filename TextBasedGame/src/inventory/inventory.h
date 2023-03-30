#pragma once

#include "../item/item.h"

#define INVENTORY_SIZE 32

class Inventory{

    private:
        /* data */

    public:
        Item item[INVENTORY_SIZE];

        ~Inventory(){}

        Inventory(){}
           
};