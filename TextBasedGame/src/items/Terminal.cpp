#include <string>
#include "../../Text-Based-Game-Engine/Engine/src/engine.h"

#include "./items.h"
#include "../command/terminal_command.h"

using namespace std;

void Terminal::enter(Player *player){
    println("You entered the terminal");
    Response r;
    Prompt p;
    p.prompt_char = this->prompt_char;
    p.accepted_commands = this->internal_commands;

    do{
        r = Engine::prompt(p, command_list, false);
        TerminalCommand::run(r, p, player);
    } while(r.command != "exit");

}
