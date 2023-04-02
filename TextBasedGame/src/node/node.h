#pragma once

#include <string>
#include <vector>
#include "../player/inventory.h"
#include "../player/movement.h"
#include "../item/item.h"
#include "../command/command.h"

class Node{
private:

public:
    std::string Description;
    vector<Movement> movements;
    vector<Item> items;
    vector<Command> commands;

    Node();
    Node(std::string description, vector<Movement> movements, vector<Item> items, vector<Command> commands);
    ~Node();
};      