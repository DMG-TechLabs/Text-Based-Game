#pragma once

#include <array>
#include <cstdarg>
#include <iostream>
#include <string>
#include <unordered_map>

#include "../../Text-Based-Game-Engine/Engine/src/engine.h"

using namespace std;

static const vector<string> command_list = {
    "help",
    "move",
    "read",
    "collect",
    "inventory"
};