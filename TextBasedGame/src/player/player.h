#pragma once

#include "../inventory/inventory.cpp"
#include <iostream>
#include <string>

using namespace std;

class Player{
public:
    Inventory inventory;
    string name;
    int hunger;
    //Command commands[];

    Player(Inventory inventory){}
    ~Player(){}
};