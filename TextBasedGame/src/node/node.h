#pragma once

#include <string>
#include <vector>
#include "../player/inventory.h"
#include "../player/movement.h"
#include "../item/item.h"
#include "../command/command.h"

/**
 * @brief Node class. Each node is a spot on the map where the player can go. 
 * 
 */
class Node{
private:

public:
    //Class variables
    bool accesible;
    std::string Description;
    vector<Movement> movements;
    vector<Item> items;
    vector<Command> commands;

    //Constructors
    Node();
    Node(std::string description, vector<Movement> movements, vector<Item> items, vector<Command> commands, bool accesible);
    ~Node();
};      