#include "item.h"

//Setters getters
void Item::setName(string name){
    this -> name = name;
}

string Item::getName(){
    return name;
}

void Item::setItemId(string item_id){
    this -> item_id = item_id;
}

string Item::getItemId(){
    return item_id;
}

void Item::setDescription(string description){
    this -> description = description;
}

string Item::getDescription(){
    return description;
}

void Item::setCommands(string *commands){
    this->commands = commands;
}

string* Item::getCommands(){
    return this->commands;
}