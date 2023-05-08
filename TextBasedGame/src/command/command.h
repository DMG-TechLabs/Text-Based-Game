#pragma once

#include <array>
#include <cstdarg>
#include <iostream>
#include <string>
#include <unordered_map>

#include "../../Text-Based-Game-Engine/Engine/src/item/item.h"
#include "../../Text-Based-Game-Engine/Engine/src/node/node.h"
#include "../../Text-Based-Game-Engine/Engine/src/player/player.h"
#include "../../Text-Based-Game-Engine/Engine/src/utils/game_utils.h"
#include "../../Text-Based-Game-Engine/Engine/src/utils/prompt.h"

#define MAX_ROOMS 5

using namespace std;

namespace Game {
    struct commands{
        string command_list[2] = {
            "move",
            "help"
        };
    };

    void runCommand(string command, string arg, vector<Item *> items);
    void getAvailableCommands();
}  // namespace Game