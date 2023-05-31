#include "menu.h"

#include <unistd.h>
#include <iostream>
#include <stdio.h>

#include "../../Text-Based-Game-Engine/Engine/src/engine.h"

using namespace std;
using namespace Menu;
using namespace Engine;


void handleDemoOptions(int selectedItem){
    switch (selectedItem){
        case 0:
            return;
        case 1:                                                
            Engine::println("Manual selected", 0);
            
            Engine::println("\n\n\nPress enter to go back to menu...", 0);
            cin.get();

            demoMenu();            
            break;
        case 2:
            Engine::println("Achievements selected", 0);

            Engine::println("\n\n\nPress enter to go back to menu...", 0);
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

            Engine::println("\n\n\nPress enter to go back to menu...", 0);
            cin.get();

            demoMenu();    
            break;
        case 2:
            Engine::println("Achievements selected", 0);

            Engine::println("\n\n\nPress enter to go back to menu...", 0);
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


void Menu::credits(){
    Text::clearScreen();
    println("==" + Text::red+ "Credits" + Text::normal+ "==\n");

    println("-" + Text::red+ "A demo created by" + Text::normal+ "-\n");


    println("Despoinidis Konstantinos", 1);
    println("Mokas Konstantinos", 1);
    println("Georgalis Athanasios", 1);
    println("Giantselidis Konstantinos", 1);

    println("\n-" + Text::red+ "Storyboard" + Text::normal+ "-\n");

    println("Despoinidis Konstantinos", 1);
    println("Mokas Konstantinos", 1);
    println("Georgalis Athanasios", 1);
    println("Giantselidis Konstantinos", 1);

    println("\n-" + Text::red+ "Game and Engine Programming" + Text::normal+ "-\n");

    println("Despoinidis Konstantinos", 1);
    println("Mokas Konstantinos", 1);
    println("Georgalis Athanasios", 1);
    println("Giantselidis Konstantinos", 1);

    println("\n-" + Text::red+ "Content Writer" + Text::normal+ "-\n");

    println("Spiridonidou Christina-Maria", 1);

    println("");
    println("");
    println("");
    println("");

    println("Thank you for playing!");

    println("Press any key to go back to menu...", 0);
    cin.get();

    Menu::demoMenu();
}