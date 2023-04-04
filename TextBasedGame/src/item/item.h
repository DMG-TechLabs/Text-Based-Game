#pragma once

#include <string>
#include <vector>  

using namespace std;

class Item{
    private:
        string name;
        string item_id;    
        string description;
        string *commands = new string[10];
        
    public:
        //Constructors
        ~Item(){}
        Item(){}
        Item(string description, string *commands){
            this -> description = description;
            this -> commands = commands;
        }

        //Setters getters
        void setDescription(string description);
        string getDescription();
};