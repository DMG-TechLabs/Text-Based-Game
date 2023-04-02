#include "item.h"

//Constructors
Item::Item() {}

Item::~Item() {}

//Setters getters
void Item::setDescription(string description){
    this -> description = description;
}

string Item::getDescription(){
    return description;
}