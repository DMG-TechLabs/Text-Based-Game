#include "terminal_command.h"

#include "../items/items.h"

using namespace Engine;

int getTerminal(vector<Item *> items);
void getAvailableCommands(Terminal *t);

void TerminalCommand::run(Response response, Prompt p, Player *player){
    switch (response.args.size()) {
        case 0:
            if (response.command == "exit"){
                return;
            } else if (response.command == "list"){
               dynamic_cast<Terminal *>(player->currentNode->items.at(getTerminal(player->currentNode->items)))->printItems();
            } else if (response.command == "help") {
                getAvailableCommands(dynamic_cast<Terminal *>(player->currentNode->items.at(getTerminal(player->currentNode->items))));
            } else {
                println("Invalid use of command");
            }
            break;
        default:
            println("This number of arguments is not yet implemnted", 0);
            break;
    }
}

int getTerminal(vector<Item *> items){
    for (int i = 0; i < items.size(); i++) {
        if(items.at(i)->getName() == "terminal") return i;
    }
    return -1;
}

void getAvailableCommands(Terminal *t){
    println("-" + Text::b_green + "Available commands" + Text::normal + "-", 0);
    for (int i = 0; i < t->internal_commands.size(); i++) {
        cout << Text::red << i + 1 << ". " << Text::normal << t->internal_commands.at(i)
             << endl;
    }
    
}