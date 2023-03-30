#pragma once

#include <string>
#include "../command/command.cpp"

class Item{
private:
    /* data */
public:
    std::string Description;
    Command commands[];
    
    Item(string description, Command command){}
    ~Item(){}

};