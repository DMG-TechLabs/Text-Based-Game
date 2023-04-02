#pragma once

#include <string>
#include <vector>  
#include "../command/command.h"

using namespace std;

class Item{
    private:    

    public:
        string description;
        vector<Command> commands;
        Item();
        ~Item();
        
        Item(string description, vector<Command> commands){
            this -> description = description;
            this -> commands = commands;
        };

        void setDescription(string description);
        string getDescription();
};