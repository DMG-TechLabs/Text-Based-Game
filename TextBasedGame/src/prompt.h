#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * @brief UI for the player
 * 
 * @param promptChar Character that will show before the artificial terminal (for example $)
 * @param message Messege that will be displayed to the player
 * @param acceptedCommands Vector of commands that are a acceptable to the player
 */
void prompt(char promptChar, string message, vector<string> acceptedCommands);