#pragma once

#include <iostream>
#include <string>
#include <array> 
#include <unordered_map>
#include <cstdarg>
#include "../../Text-Based-Game-Engine/Engine/src/item/item.h"
#include "../../Text-Based-Game-Engine/Engine/src/player/player.h"
#include "../../Text-Based-Game-Engine/Engine/src/map/node.h"
#include "../../Text-Based-Game-Engine/Engine/src/utils/prompt.h"
#include "../../Text-Based-Game-Engine/Engine/src/utils/game_utils.h"


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


        void run(string *command);
        void run(string *command, Item *item);
        //void run(string *command, Player *player, int number_of_items, ...);
        void run(string *command, Player *player, Node *room);
        void run(string *command, Player *player, Item *item);

        void getAvailableCommands();

};