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

    string *linux_commands = new string[2];
    linux_commands[0] = "ls";
    linux_commands[1] = "cd";


    Item **room_items = new Item*[10];
    room_items[0] = new Note("domain.xyz\n\nthe_truth.txt");
    room_items[1] = new Terminal('$', "Linux terminal", linux_commands);
    



    runCommand(args[0], args[1], room_items);
}

int main(int argc, char *argv[]){
   prototype();
}