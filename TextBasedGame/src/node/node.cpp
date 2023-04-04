#include "node.h"

//Constructors
Node::Node(){}

Node::~Node(){}

Node::Node(std::string description, vector<Movement> movements, Item *items, /*vector<Command> commands,*/ bool accesible, bool inside){
    this-> Description = description;
    this-> movements = movements;
    this-> items = items;
    /*this-> commands = commands;*/
    this->accesible = accesible;
    this->inside = inside;
}