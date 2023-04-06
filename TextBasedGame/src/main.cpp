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
    Terminal *t = new Terminal('$', "Room terminal", commands);

    
    string* ret = t->terminalPrompt("Type command");

    if(ret != NULL){
        cout << "Command: " << *ret << "\nArgument: " << *(ret+1) << endl;
        cout << endl << endl;
    }
}

void prototype(){
    string* args = prompt(
        '>',
        "You wake up tired in a room. There is a desk with an open terminal and a note next to it.",
        new string[5]{"enter", "inspect", "help", "exit", "read"}
    );

    if(args == NULL) return;


    Item **room_items = new Item*[2]{
        room_items[0] = new Note("domain.xyz\n\nthe_truth.txt"),
        room_items[1] = new Terminal('$', "Linux terminal", new string[2]{"ls, cd"})
    };
    



    runCommand(args[0], args[1], room_items);
}

int main(int argc, char *argv[]){
   prototype();
}