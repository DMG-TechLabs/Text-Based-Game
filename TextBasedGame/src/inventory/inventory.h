#pragma once

#include "../item/item.cpp"

int const inventory_size = 32;

class Inventory{

private:
    /* data */

public:
    Item item;

    Inventory(Item item){}
    ~Inventory(){}
};