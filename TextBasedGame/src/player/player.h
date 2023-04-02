#pragma once

#include "inventory.h"
#include <iostream>
#include <string>

using namespace std;

class Player{
    private:
        Inventory inventory;
        string name;
        int hunger;
        //Command commands[];

    public:
        Player();
        //~Player();
        
        Player(Inventory inventory, string name, int hunger/*, Command command[]*/){
            this -> inventory = inventory;
            this -> name = name;
            this -> hunger = hunger;
        };

        void setInventory(Inventory inventory);
        Inventory getInventory();

        void setName(string name);
        string getName();

        void setHunger(int hunger);
        int getHunger();
    };