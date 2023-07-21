#pragma once

#include "engine.h"


using namespace Engine;


static const vector<string> command_list = {
    "exit",
    "list",
    "hack",
    "help"
};

class TerminalCommand {
    public:
        static void run(Response response, Prompt p, Player *player);
};
