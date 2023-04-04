#pragma once

#include <iostream>
#include <string>
#include <array> 
#include <unordered_map>
#include <cstdarg>
#include "../item/item.h"
#include "../player/player.h"
#include "../node/node.h"
#include "../terminal/prompt.h"
#include "../utils.h"


#define MAX_ROOMS 5

using namespace std;


class Command {
    private:
    public:
        //string availabe_commands["see"];
        //Constructors
        //unordered_map<string, Item> available_items_for_crafting;
        Command(){
            //string valid_commands[1];
        };
        ~Command(){};


        void run(string *command);
        void run(string *command, Item *item);
        //void run(string *command, Player *player, int number_of_items, ...);
        void run(string *command, Player *player, Node *room);
        void run(string *command, Player *player, Item *item);
        

};