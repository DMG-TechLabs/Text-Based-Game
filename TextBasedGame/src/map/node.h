#pragma once

#include <string>
#include <vector>
#include "../player/inventory.h"
#include "../item/item.h"
#include "../utils/prompt.h"
//#include "../command/command.h"

using namespace std;

class Node{
    private:

    public:
        //Class variables
        int number;
        string description;
        vector<Item> *items;
        vector<Node> *accesible_nodes;
        bool accesible;
        bool inside;

        //Constructors
        Node(){}

        ~Node(){}

        //Constructor for rooms/hallways
        Node(int number, string description, vector<Item> *items, vector<Node> *accesible_nodes, bool accesible, bool inside){
            this-> number = number;
            this-> description = description; 
            this-> items = items;
            this-> accesible_nodes = accesible_nodes;
            this-> accesible = accesible;
            this-> inside = inside;
        }

        //Constructor for inacessible rooms
        Node(string description){
            this->accesible = false;
            this->description = description;
        }

        //Auxiliary functions

        /**
         * @brief Method that moves player to a new node if it is accessible
         * 
         * @param newNode The node the player tries to move to
         */
        void moveNode(Node *newNode);

        //Need to create function that gets input number and returns the room object
        //Need to create an init function that depending on the day creates the rooms
        //Need to create a function that makes player move to a different room. Done
};   