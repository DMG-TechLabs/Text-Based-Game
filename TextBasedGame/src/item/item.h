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
        Item(string name, string description, string *commands){
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
};

class Note : public Item {
    public:
        ~Note(){}
        Note(string description){
            string *note_commands = new string[2];
            note_commands[0] = "read";
            note_commands[1] = "save";

            Item("note", description, note_commands);
        }  

        void saveNote(string note_name);
};

class Terminal : public Item{
    public:
        char prompt_char;
        string *commands;

        ~Terminal(){}
        Terminal(char prompt_char, string commands[]){
            this->prompt_char = prompt_char;
            this->commands = commands;
        }

        string* getCommand(string message);

};