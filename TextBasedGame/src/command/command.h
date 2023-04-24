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


class CommandAbstract {
    public:
        string name;
        
        CommandAbstract(){}
        virtual ~CommandAbstract(){}

        virtual void run(){}
        virtual void run(Item *item){}
        virtual void run(Player *player, Node *room){}
        virtual void run(Player *player, Item *item){}
};

class Command : public CommandAbstract {
    public:
        ~Command(){}
        Command(string name){
            this->name = name;
        }

        void run() override;
        void run(Item *item) override;
        void run(Player *player, Node *room) override;
        void run(Player *player, Item *item) override;
};