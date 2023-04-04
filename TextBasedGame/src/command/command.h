#pragma once

#include <iostream>
#include <string>
#include "../item/item.h"
#include "../player/player.h"
#include "../node/node.h"


#define MAX_ROOMS 5

using namespace std;


class Command {
    private:
    public:
        //string availabe_commands["see"];
        //Constructors
        Command(){};
        ~Command(){};


        void Run(string *command, Item *item);
        void Run(string *command){};

        void Run(string *command, Player *player, Node *room);

        

};