#include <iostream>
#include <vector>
#include <unistd.h>

#include "../Text-Based-Game-Engine/Engine/src/engine.h"
#include "./command/command.h"
#include "./items/items.h"
#include "./map/map.h"
#include "./day/day.h"
#include "./interactions/interactions.h"
#include "./menu/menu.h"


int main() {
    Prompt p;
    Response r;
    Map map{new Node(0, "Hall", true)};
    Player player{};


    //Day::demo(&player, &map);
    
    disableInputBuffering();
    demoMenu(player, map);
    enableInputBuffering();
    

    return 0;
}