#include <iostream>
#include <vector>
#include <unistd.h>
#include <thread>
#include <atomic>

#ifdef _WIN32
    #include <conio.h>
#else
    #include <termios.h>
    #include <unistd.h>
    #include <fcntl.h>
#endif

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
    
    return 0;
}