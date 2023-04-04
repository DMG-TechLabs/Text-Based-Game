#pragma once

#include <string>
#include <vector>
#include "../player/inventory.h"
#include "../player/movement.h"
#include "../player/player.h"
#include "../item/item.h"
//#include "../command/command.h"

using namespace std;

class Node{
    private:

    public:
        //Class variables
        string Description;
        vector<Movement> movements;
        Item *items;
        //vector<Command> commands;
        bool accesible;
        bool inside;

        //This two is for the command to build
        int number;
        void setPlayer(Player *player);

        //Constructors
        Node();
        Node(std::string description, vector<Movement> movements, Item *items, /*vector<Command> commands,*/ bool accesible, bool inside);
        ~Node();

    //Auxiliary functions
};      