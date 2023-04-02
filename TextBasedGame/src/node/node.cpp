#include "node.h"

//Constructors
Node::Node(){}

Node::~Node(){}

Node::Node(std::string description, vector<Movement> movements, vector<Item> items, vector<Command> commands){
    this-> Description = description;
    this-> movements = movements;
    this-> items = items;
    this-> commands = commands;
}