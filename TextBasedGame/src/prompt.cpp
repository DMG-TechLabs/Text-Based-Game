#include <iostream>
#include <string>
#include "prompt.h"

/**
 * @brief UI for the player
 * 
 * @param promptChar Character that will show before the artificial terminal (for example $)
 * @param message Messege that will be displayed to the player
 * @param acceptedCommands Vector of commands that are a acceptable to the player
 */
void prompt(char promptChar, string message, vector<string> acceptedCommands){
    string inputCommand;
    
    cout << message << endl << endl;
    cout << promptChar << " ";

    cin >> inputCommand;

    cout << endl << endl;
}