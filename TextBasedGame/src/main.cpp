#include <iostream>

#include "../Text-Based-Game-Engine/Engine/src/engine.h"
#include "./command/command.h"
#include "./items/items.h"
#include "./map/map.h"
#include "./day/day.h"
#include "./interactions/interactions.h"
#include "./menu/menu.h"

int main() {
    Map map{new Node(0, "Hall", true)};
    Player player{};


    Menu::demoMenu();

    while(true){
        Day::dayOne(&player, &map);
        Day::dayTwo(&player, &map);
        Menu::credits();
    }


    // cout << Engine::loadFromFile("../assets/OPERATION_SENTINEL_SHIELD.txt") << endl;    

    return 0;
}