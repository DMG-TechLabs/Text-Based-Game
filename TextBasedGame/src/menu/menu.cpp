#include "menu.h"

#include <unistd.h>
#include <iostream>
#include <stdio.h>

#include "../../Text-Based-Game-Engine/Engine/src/engine.h"
#include "../day/day.h"
#include "./menu_utils.h"

using namespace std;
using namespace Menu;


void handleDemoOptions(int selectedItem){
    switch (selectedItem){
        case 1:
            return;
        case 2:                                                
            Engine::println("Manual selected", 0);
            break;
        case 3:
            Engine::println("Achievements selected", 0);
            break;
        case 4:
            println("Quiting game...");
            std::exit(0);
    }
}

void Menu::demoMenu(){
    menu(4, {"Play Demo", "Manual", "Achievements", "Exit"}, &handleDemoOptions);
}

void handlePauseOptions(int selectedItem){
    switch (selectedItem){
        case 1:
            return;
        case 2:
            Engine::println("Manual selected", 0);
            break;
        case 3:
            Engine::println("Achievements selected", 0);
            break;
        case 4:
            println("Quiting game...");
            std::exit(0);
    }
}

void Menu::pauseMenu(){
    menu(4, {"Continue", "Manual", "Achievements", "Exit"}, &handlePauseOptions);
}
