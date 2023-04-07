#pragma once

#include <iostream>
#include <string>

#include "../item/item.h"

using namespace std;


string* prompt(char prompt_char, string *accepted_commands);
string* prompt(char prompt_char, string message, string *accepted_commands);

void print(string message);
void print(int message);
void print(char message);

void runCommand(string command, string arg, Item **item);