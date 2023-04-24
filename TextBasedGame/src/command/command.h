#pragma once

#include <iostream>
#include <string>
#include <array> 
#include <unordered_map>
#include <cstdarg>
#include "../item/item.h"
#include "../player/player.h"
#include "../map/node.h"
#include "../utils/prompt.h"
#include "../utils/game_utils.h"


#define MAX_ROOMS 5

using namespace std;


class Command {
    private:
        

    public:
        string *command_list = new string[10]{
            "move",
            "inspect",
            "enter",
            "exit",
            "read",
            "save",
            "collect",
            "ls",
            "cd"
        };
        //string availabe_commands["see"];
        //Constructors
        //unordered_map<string, Item> available_items_for_crafting;
        Command(){
            //string valid_commands[1];
        };
        ~Command(){};


        void run(string *command) {};
        void run(string *command, Item *item) {};
        //void run(string *command, Player *player, int number_of_items, ...);
        void run(string *command, Player *player, Node *room) {};
        void run(string *command, Player *player, Item *item) {};

        void getAvailableCommands();

};