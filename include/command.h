#pragma once

#include <array>
#include <cstdarg>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#include "engine.h"

using namespace std;
using namespace Engine;

static const vector<string> command_list = {
    "help",
    "read",
    "collect",
    "inventory",
    "open",
    "sleep",
    "enter",
    "exit",
    "goto",
    "save",
    "inspect",
    "use",
    "unlock",
    "search",
    "objectives"
};

int matchItemByName(string item, vector<Item *> items);
int matchItemById(string item, vector<Item *> items);
