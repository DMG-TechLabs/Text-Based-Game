#include "utils.h"
#include <iostream>
#include <string>

void prompt(char promptChar, string message, string acceptedCommands[]){
    string inputCommand;
    
    cout << message << endl << endl;
    cout << promptChar << " ";

    cin >> inputCommand;

    cout << endl << endl;
}