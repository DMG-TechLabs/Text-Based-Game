#include <iostream>
#include <string>

#include "prompt.h"
#include "../command/command.h"
#include "../item/item.h"

/* ============={Utils}============= */

bool contains(string arr[], string str) {
    int size = 0;
    while (!arr[size].empty())
        ++size;

    bool exists = false;
    for (int i = 0; i < size; i++) {
        if(str == arr[i]){
            exists = true;
            break;
        }
    }

    return exists;
}

int itemsLength(Item **items){
    int length_counter = 0;
    while(items[length_counter])
        length_counter++;

    return length_counter;
}

/* ============={End of Utils}============= */


string* prompt(char promptChar, string message, string accepted_commands[]){
    string input, command, argument;
    string* ret = new string[2];
    
    print(message);
    cout << promptChar << " ";

    getline(cin, input);


    //Getting space index
    int break_index = 0, num_spaces = 0;
    for (int i = 0; i < input.length(); i++) {
        if(input[i] == ' ') {
            break_index = i;
            num_spaces++;
        }
    }

    //Check if input is valid
    if(break_index <= 0 || break_index >= input.length()){
        //return NULL; //no space
        ret[0] = input;
        return ret;
    }
    if(num_spaces > 1) return NULL; //more than one space


    command = input.substr(0, break_index);
    argument = input.substr(break_index+1, input.length()-1);
    
    //Check if command is accepted;
    bool exists = contains(accepted_commands, command);
    if(!exists) {
        print("Invalid command");
        return NULL;
    }

    cout << endl << endl;

    

    ret[0] = command;
    ret[1] = argument;

    return ret;
}

void print(string message){
    cout << message << endl << endl;
}

void runCommand(string command, string arg, Item **items){
    //cout << command << endl << arg << endl;

    Command *c = new Command();

    int index_to_use = -1;
    for(int i = 0; i < itemsLength(items); i++){
        //cout << i << ". " << items[i]->getName() << endl;
        if(arg == items[i]->getName()){
            index_to_use = i;
            break;
        }
    }
    
    //cout << index_to_use << endl;
    if(index_to_use < 0) return;


    c->run(&command, items[index_to_use]);
}

