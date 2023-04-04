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
        string description;
        vector<Item> items;
        vector<string> accesible_nodes;
        bool accesible;
        bool inside;

        //This two is for the command to build
        int number;
        void setPlayer(Player *player);

        //Constructors
        Node(){}

        //Constructor for rooms/hallways
        Node(std::string description, vector<Item> items, vector<string> accesible_nodes, bool accesible, bool inside){
            this-> description = description; 
            //this-> movements = movements;
            this-> items = items;
            this->accesible_nodes = accesible_nodes;
            this->accesible = accesible;
            this->inside = inside;
        }

        //Constructor for inacessible rooms
        Node(std::string description){
            this->accesible = false;
            this->description = description;
        }

        ~Node(){}

        //Auxiliary functions
        //Need to create function that gets input number and returns the room object
        //Need to create an init function that depending on the day creates the rooms

        /**
         * @brief Will be called when a player tries to enter an inacessible room
         * 
         * @return std::string The description of the room the player tried to enter
         */
        std::string inaccessibleRoomDescription();
};   