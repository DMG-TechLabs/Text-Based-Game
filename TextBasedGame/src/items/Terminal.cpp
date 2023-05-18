#include <string>
#include "../../Text-Based-Game-Engine/Engine/src/engine.h"

#include "./items.h"

using namespace std;

Response Terminal::terminalPrompt(string message){
    return prompt(prompt_char, message, internal_commands);
}

void Terminal::enter(Player *player){
    println("You entered the terminal");

    Prompt p;
    p.prompt_char = '$';
    p.accepted_commands = {"exit"};
    Response r = Engine::prompt(p, {}, false);

    do{
        Command::run(r, p, player);
    } while(r.command != "exit");

}
