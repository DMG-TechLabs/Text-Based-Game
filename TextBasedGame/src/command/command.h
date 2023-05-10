#pragma once

#include <array>
#include <cstdarg>
#include <iostream>
#include <string>
#include <unordered_map>

#include "../../Text-Based-Game-Engine/Engine/src/engine.h"

using namespace std;

#define MAX_ROOMS 5

static const vector<string> command_list = {
    "move",
    "help",
    "read"
};

void runCommand(Response r, vector<Item> items);
void runCommand(string command, vector<string> args, vector<Item> items);
void getAvailableCommands();