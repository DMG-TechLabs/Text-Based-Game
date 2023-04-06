#pragma once

#include <iostream>
#include <string>

#include "../item/item.h"

using namespace std;


string* prompt(char promptChar, string message, string accepted_commands[]);

void print(string message);

void runCommand(string command, string arg, Item **item);