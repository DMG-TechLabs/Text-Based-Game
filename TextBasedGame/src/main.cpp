#include <iostream>

#include "../Text-Based-Game-Engine/Engine/src/engine.h"

void day_one(Player *player){
    Map *map = new Map(1);

    player->currentNode = map->nodes.at(0);
    map->nodes.at(0)->inside = true;

    prompt('>', "You wake up in a room with a terminal open and a note by its side.", new string[4]{
        "move",
        "help",
        "enter",
        "read"
    });


    
}

int main(){
    //Player *p = new Player(Inventory{}, "Mpamphs", new vector<string>{"help", "read", "enter"}, new vector<int>{});
    Player *p = new Player();

    day_one(p); 
    return 0;
}