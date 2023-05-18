#include <string>
#include "../../Text-Based-Game-Engine/Engine/src/engine.h"

#include "./items.h"
#include "../command/command.h"

using namespace std;

Response Terminal::terminalPrompt(string message){
    return prompt(prompt_char, message, internal_commands);
}

void Terminal::enter(Player *player){
    println("You entered the terminal");
    Response r;
    Prompt p;
    p.prompt_char = '$';
    p.accepted_commands = {"exit"};

    do{
        r = Engine::prompt(p, command_list, false);
        Command::run(r, p, player);
    } while(r.command != "exit");

}
