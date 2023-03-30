#pragma once

#include <string>
#include "../inventory/inventory.h"
#include "../movement/movement.h"
#include "../item/item.h"

class Node{
private:
    /* data */
public:
    std::string Description;
    Movement movements;
    Item items[];
    Command commands[];


    Node(std::string description, Movement movements, Item item, Command commands[]){}
    ~Node(){}
};