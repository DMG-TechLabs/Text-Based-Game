#pragma once

#include <string>
#include "../player/inventory.h"
#include "../player/movement.h"
#include "../item/item.h"

class Node{
private:
    /* data */
public:
    std::string Description;
    Movement movements;
    //Item items[];
    Command commands[];

    Node();
    //Node(std::string description, Movement movements, Item item, Command commands[]);
    ~Node();
};