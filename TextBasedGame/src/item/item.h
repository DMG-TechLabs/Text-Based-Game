#pragma once

#include <string>
#include <vector>  

using namespace std;

class Item {
    private:
        string name;
        string item_id;    
        string description;
        string *commands = new string[10];
        
    public:
        //Constructors
        virtual ~Item(){}
        Item(){}

        Item(string name, string description){
            this -> name = name;
            this -> description = description;
        }

        Item(string item_id, string name, string description){
            this ->item_id = item_id;
            this -> name = name;
            this -> description = description;
        }

        Item(string item_id, string name, string description, string *commands){
            this ->item_id = item_id;
            this -> name = name;
            this -> description = description;
            this -> commands = commands;
        }

        //Setters getters
        void setName(string name);
        string getName();

        void setItemId(string item_id);
        string getItemId();

        void setDescription(string description);
        string getDescription();   

        void setCommands(string *commands);
        string* getCommands(); 
};

