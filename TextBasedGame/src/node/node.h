#pragma once

#include <string>
#include <vector>
#include "../player/inventory.h"
#include "../player/movement.h"
#include "../item/item.h"

class Node{
private:
    /* data */
public:
    std::string Description;
    vector<Movement> movements;
    vector<Item> items;
    vector<Command> commands;

    Node();
    Node(std::string description, vector<Movement> movements, vector<Item> items, vector<Command> commands);
    ~Node();
};  