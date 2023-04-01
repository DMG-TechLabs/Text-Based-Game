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
        Player(Inventory inventory, string name, int hunger/*, Command command[]*/){}
        ~Player(){}

        void setInventory(Inventory inventory);
        Inventory getInventory();

        void setName(string name);
        string getName();

        void setHunger(int hunger);
        int getHunger();
    };