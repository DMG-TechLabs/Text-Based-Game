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
        int hunger;
        vector<Command> commands;

    public:
        //Constructors
        Player(){}
        ~Player(){}
        Player(Inventory inventory, string name, int hunger, vector<Command> commands){
            this -> inventory = inventory;
            this -> name = name;
            this -> hunger = hunger;
        }

        //Setters getters
        void setInventory(Inventory inventory);
        Inventory getInventory();

        void setName(string name);
        string getName();

        void setHunger(int hunger);
        int getHunger();
    };