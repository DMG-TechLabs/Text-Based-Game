#include "item.h"

Item::Item(string description){
    this -> description = description;
}

void Item::setDescription(string description){
    this -> description = description;
}

string Item::getDescription(){
    return description;
}
