#include "menu.h"

#include <unistd.h>
#include <iostream>
#include <stdio.h>

#include "../../Text-Based-Game-Engine/Engine/src/engine.h"

using namespace std;
using namespace Menu;
using namespace Engine;

void manual();

void handleDemoOptions(int selectedItem){
    switch (selectedItem){
        case 0:
            return;
        case 1:      
            manual();
            
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
    Engine::menu(Text::b_blue + "Orbit of Shadows:\nSecrets in Deep Space" + Text::normal, 4, {"Play Demo", "Manual", "Achievements", "Exit"}, &handleDemoOptions);
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
    Engine::menu(Text::b_blue + "Continue" + Text::normal, 4, {"Continue", "Manual", "Achievements", "Exit"}, &handlePauseOptions);
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

    println("\nPress enter to go back to menu...", 0);
    cin.get();

    Menu::demoMenu();
}

void manual(){
    Engine::println(Text::b_green +"- Manual - \n" +Text::normal, 0);
    Engine::println(Text::b_blue + "Orbit of Shadows:\nSecrets in Deep Space " + Text::normal + "is a text-based game with the goal to survive and eventually free yourself.", 0);
    Engine::println("To interact with the game world you need to type to your terminal all the commands. Interactable items will appear with " +Text::b_red +"colored text" + Text::normal + ".\n", 0);
    Engine::println("The "+ Text::b_green + "help" + Text::normal + " command shows you all available commands at that time. \n",0);          
    Engine::println("Use your mind to discover clues, solve puzzles and connect the story-dots so you can discover what secrets exist in the depths of space...",0);
}
