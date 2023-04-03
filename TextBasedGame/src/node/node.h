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
    std::string Description;
    vector<Movement> movements;
    vector<Item> items;
    vector<Command> commands;
    bool accesible;
    bool inside;

    //Constructors
    Node();
    Node(std::string description, vector<Movement> movements, vector<Item> items, vector<Command> commands, bool accesible, bool inside);
    ~Node();

    //Auxiliary functions
};      