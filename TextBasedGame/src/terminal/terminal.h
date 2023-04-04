#pragma once

#include <string>

using namespace std;

class Terminal{
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