#pragma once

#include "inventory.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Player{
    private:
        Inventory inventory;
        string name;
        int hunger;
        vector<Command> commands;

    public:
        Player();
        ~Player();
        Player(Inventory inventory, string name, int hunger, vector<Command> commands);

        void setInventory(Inventory inventory);
        Inventory getInventory();

        void setName(string name);
        string getName();

        void setHunger(int hunger);
        int getHunger();
    };