#pragma once

#include <string>
#include "../inventory/inventory.cpp"
#include "../movement/movement.cpp"

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