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
        //vector<Movement> movements;
        Item *items;
        vector<string> accesible_nodes;
        bool accesible;
        bool inside;

        //This two is for the command to build
        int number;
        void setPlayer(Player *player);

        //Constructors
        Node(){}
        Node(std::string description, /*vector<Movement> movements,*/ Item *items, vector<string> accesible_nodes, bool accesible, bool inside){
            this-> Description = description;
            //this-> movements = movements;
            this-> items = items;
            this->accesible_nodes = accesible_nodes;
            this->accesible = accesible;
            this->inside = inside;
        }
        ~Node(){}

    //Auxiliary functions
};      