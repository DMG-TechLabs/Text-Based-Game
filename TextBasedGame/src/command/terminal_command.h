#pragma once

#include "../../Text-Based-Game-Engine/Engine/src/engine.h"


using namespace Engine;


static const vector<string> command_list = {
    "exit",
    "list"
};

class TerminalCommand {
    public:
        static void run(Response response, Prompt p, Player *player);
};