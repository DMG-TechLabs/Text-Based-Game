#pragma once

#include <string>
#include <vector>  
#include "../command/command.cpp"

using namespace std;

class Item{
    private:
        string description;
        vector<Command> commands;

    public:
        Item();
        ~Item();
        
        Item(string description, vector<Command> commands){
            this -> description = description;
            this -> commands = commands;
        };

        void setDescription(string description);
        string getDescription();
};