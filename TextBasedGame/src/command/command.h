#pragma once

#include <array>
#include <cstdarg>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#include "../../Text-Based-Game-Engine/Engine/src/engine.h"

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
    "unlock"
};

int matchItem(string item, vector<Item *> items);