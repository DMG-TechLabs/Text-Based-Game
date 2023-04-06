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

        void setCommands(string *commands);
        string* getCommands(); 
};

class Note : public Item {
    public:
        ~Note(){}
        Note(string description) : Item("note", description){
            string *note_commands = new string[2];
            note_commands[0] = "read";
            note_commands[1] = "save";

            setCommands(note_commands);
        }  

        void saveNote(string note_name);
};

class Terminal : public Item {
    public:
        char prompt_char;
        string *internal_commands;

        ~Terminal(){}
        Terminal(char prompt_char, string description, string *internal_commands) : Item("terminal", description){
            this->prompt_char = prompt_char;
            this->internal_commands = internal_commands;


            string *terminal_commands = new string[2];
            terminal_commands[0] = "enter";
            terminal_commands[1] = "exit";

            setCommands(terminal_commands);
        }

        string* terminalPrompt(string message);

};