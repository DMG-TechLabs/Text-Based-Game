#include "item.h"

Item::Item(string description, vector<Command> commands) {
    this->description = description;
    this->commands = commands;
}

void Item::setDescription(string description){
    this -> description = description;
}

string Item::getDescription(){
    return description;
}
