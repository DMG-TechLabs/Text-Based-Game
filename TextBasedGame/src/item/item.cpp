#include "item.h"

void Item::setDescription(string description){
    this -> description = description;
}

string Item::getDescription(){
    return description;
}

Item::Item() {}

Item::~Item() {}