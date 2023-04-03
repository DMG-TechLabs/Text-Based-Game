#pragma once

#include <string>
#include <vector>  
#include "../command/command.h"

using namespace std;

class Item{
    private:
        string name;
        string item_id;    
        string description;
        vector<Command> commands;
        
    public:
        //Constructors
        Item(){}
        ~Item(){}
        Item(string description, vector<Command> commands){
            this -> description = description;
            this -> commands = commands;
        }

        //Setters getters
        void setDescription(string description);
        string getDescription();
};