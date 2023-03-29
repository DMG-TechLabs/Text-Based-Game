#include "player.h"
#include "../inventory/inventory.cpp"


class Player{
public:
    Inventory inventory;
    string name;
    int hunger;
    //Command commands[];

    Player(/* args */){}
    ~Player(){}
};
