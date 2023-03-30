#pragma once

#include <string>
#include "../command/command.cpp"

using namespace std;


class Item{
    private:
        /* data */
    public:
        string Description;
        Command commands[];
        
        Item(){}

        Item(string description, Command command){}
        ~Item(){}

};