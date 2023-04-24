#pragma once

#include "inventory.h"
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

    public:
        //Constructors
        Player(){}
        ~Player(){}
        Player(Inventory inventory, string name, vector<string> commands, vector<int> stats){
            this -> inventory = inventory;
            this -> name = name;
            this -> commands = commands;
            this -> stats = stats;
        }
        
        //This is to show in which room is the player
        int position;

        //Setters getters
        void setInventory(Inventory inventory);
        Inventory getInventory();

        void setName(string name);
        string getName();
    };