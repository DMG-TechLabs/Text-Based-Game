#include <iostream>
#include <string>
#include "prompt.h"

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

/* ============={End of Utils}============= */


string* prompt(char promptChar, string message, string accepted_commands[]){
    string input;
    string command;
    string argument;
    
    print(message);
    cout << promptChar << " ";

    getline(cin, input);


    //Getting space index
    int break_index = 0;
    int num_spaces = 0;
    for (int i = 0; i < input.length(); i++) {
        if(input[i] == ' ') {
            break_index = i;
            num_spaces++;
        }
    }

    //Check if input is valid
    if(break_index <= 0 || break_index >= input.length()) return NULL; //no space
    if(num_spaces > 1) return NULL; //more than one space


    command = input.substr(0, break_index);
    argument = input.substr(break_index+1, input.length()-1);
    
    cout << "Command: " << command << "\nArgument: " << argument << endl;
    
    //Check if command is accepted;

    bool exists = contains(accepted_commands, command);
    if(!exists) {
        print("Doesn't exist");
        return NULL;
    }

    cout << endl << endl;

    string* ret = new string[2];

    ret[0] = command;
    ret[1] = argument;

    return ret;
}

void print(string message){
    cout << message << endl << endl;
}