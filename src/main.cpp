#include <iostream>

#include "engine.h"
#include "command.h"
#include "items.h"
#include "map.h"
#include "day.h"
#include "interactions.h"
#include "menu.h"

int main() {
    Map map{new Node(0, "Hall", true)};
    Player player{};


    GameMenu::demoMenu();

    while(true){
        Day::dayOne(&player, &map);
        Day::dayTwo(&player, &map);
        GameMenu::credits();
    }


    // cout << Engine::loadFromFile("../assets/OPERATION_SENTINEL_SHIELD.txt") << endl;    



    return 0;
}
