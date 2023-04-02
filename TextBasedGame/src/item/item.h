#pragma once

#include <string>
#include <vector>  
#include "../command/command.h"

using namespace std;

/**
 * @brief Class of items
 * 
 */
class Item{
    private:    

    public:
        //Variables
        string description;
        vector<Command> commands;

        //Constructors
        Item();
        ~Item();
        Item(string description, vector<Command> commands){
            this -> description = description;
            this -> commands = commands;
        };

        //Setters getters
        void setDescription(string description);
        string getDescription();
};