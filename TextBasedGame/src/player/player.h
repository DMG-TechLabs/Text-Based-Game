#pragma once

#include "inventory.h"
#include "../map/node.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * @brief Class of the player
 * 
 */
class Player{
    private:
        Inventory inventory;
        string name;
        vector<int> stats;
        vector<string> commands;
        //Node *currentNode = new Node();

    public:
        Node *currentNode = new Node();
        //Constructors
        Player(){}
        ~Player(){}
        Player(Inventory inventory, string name, vector<string> commands, vector<int> stats, Node *currentNode){
            this -> inventory = inventory;
            this -> name = name;
            this -> commands = commands;
            this -> stats = stats;
            this -> currentNode = currentNode;
        }

        //Setters getters
        void setInventory(Inventory inventory);
        Inventory getInventory();

        void setName(string name);
        string getName();

        vector<int> getStats();

        void setCurrentNode(Node *newNode);

        /**
         * @brief Method that moves player to a new node if it is accessible
         * 
         * @param newNode The node the player tries to move to
         */
        void moveNode(Node *newNode, Node *oldNode);
};