#include <iostream>
#include <string>
#include "prompt.h"

void prompt(char promptChar, string message, vector<string> acceptedCommands){
    string inputCommand;
    
    cout << message << endl << endl;
    cout << promptChar << " ";

    cin >> inputCommand;

    cout << endl << endl;
}