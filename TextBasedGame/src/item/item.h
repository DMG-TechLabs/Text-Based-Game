#pragma once

#include <string>
#include "../command/command.cpp"

using namespace std;


class Item{
    private:
        string description;
        //Command commands[];

    public:
        Item(){}

        ~Item(){}

        Item(string description/*, Command commands[]*/){}

        void setDescription(string description);
        string getDescription();
};