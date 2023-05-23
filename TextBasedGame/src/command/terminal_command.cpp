#include "terminal_command.h"


using namespace Engine;

void TerminalCommand::run(Response response, Prompt p, Player *player){
    switch (response.args.size()) {
        case 0:
            if (response.command == "exit"){
                return;
            } else if (response.command == "list"){
               println("list command running...", 0);
            }
            break;
        case 1:

            
            break;
        default:
            println("This number of arguments is not yet implemnted", 0);
            break;
    }
}