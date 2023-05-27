#include "menu.h"

#include <unistd.h>
#include <iostream>
#include <stdio.h>

#include "../../Text-Based-Game-Engine/Engine/src/engine.h"

using namespace std;
using namespace Menu;


void handleDemoOptions(int selectedItem){
    switch (selectedItem){
        case 0:
            return;
        case 1:                                                
            Engine::println("Manual selected", 0);
            
            Engine::println("\n\n\nPress any key to go back to menu...", 0);
            cin.get();

            demoMenu();            
            break;
        case 2:
            Engine::println("Achievements selected", 0);

            Engine::println("\n\n\nPress any key to go back to menu...", 0);
            cin.get();

            demoMenu();
            break;
        case 3:
            Engine::println("Quiting game...");
            std::exit(0);
    }
}

void Menu::demoMenu(){
    Engine::menu(4, {"Play Demo", "Manual", "Achievements", "Exit"}, &handleDemoOptions);
}

void handlePauseOptions(int selectedItem){
    switch (selectedItem){
        case 0:
            return;
        case 1:
            Engine::println("Manual selected", 0);

            Engine::println("\n\n\nPress any key to go back to menu...", 0);
            cin.get();

            demoMenu();    
            break;
        case 2:
            Engine::println("Achievements selected", 0);

            Engine::println("\n\n\nPress any key to go back to menu...", 0);
            cin.get();

            demoMenu();    
            break;
        case 3:
            Engine::println("Quiting game...");
            std::exit(0);
    }
}

void Menu::pauseMenu(){
    Engine::menu(4, {"Continue", "Manual", "Achievements", "Exit"}, &handlePauseOptions);
}
