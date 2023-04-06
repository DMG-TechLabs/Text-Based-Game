#include <iostream>
#include <string>
#include "achievements/achievement.h"
#include "utils/prompt.h"
#include "player/inventory.h"
#include "map/node.h"
#include "progress/progress.h"
#include "item/item.h"

using namespace std;

void testTerminal(){
    string commands[] = {"move", "inspect"};
    Terminal *t = new Terminal('$', commands);

    
    string* ret = t->getCommand("Type command");

    if(ret != NULL){
        cout << "Command: " << *ret << "\nArgument: " << *(ret+1) << endl;
        cout << endl << endl;
    }
}

void prototype(){
    string prompt_commands[] = {"enter", "inspect", "help", "exit", "read"};
    string* args = prompt('>', "You wake up tired in a room. There is a desk with an open terminal and a note next to it.", prompt_commands);

    if(args == NULL) return;

    

    Item *note = new Note("domain.xyz\n\nthe_truth.txt");
    Item *terminal = new Terminal('$', {});

    runCommand(*args, note);
}

int main(int argc, char *argv[]){
    prototype();
}