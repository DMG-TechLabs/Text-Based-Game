#include "menu.h"

#include <unistd.h>
#include <iostream>
#include <stdio.h>

#include "Cli-Kit/include/text.h"
#include "engine.h"
#include "include/prompt.h"

using namespace std;
using namespace Engine;
using namespace CliKit;
using namespace GameMenu;

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
            Engine::println("Quiting game...");
            std::exit(0);
    }
}

void GameMenu::demoMenu(){
    CliKit::Menu::menu(Text::b_blue + "Orbit of Shadows:\nSecrets in Deep Space" + Text::normal, 4, {"Play Demo", "Manual", "Exit"}, &handleDemoOptions);
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

void GameMenu::pauseMenu(){
    CliKit::Menu::menu(Text::b_blue + "Continue" + Text::normal, 4, {"Continue", "Manual", "Achievements", "Exit"}, &handlePauseOptions);
}


void GameMenu::credits(){
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

	return;
}

void manual(){
    Engine::println(Text::b_green +"- Manual - \n" +Text::normal, 0);
    
	Engine::println(Text::b_blue + "Orbit of Shadows: Secrets in Deep Space \n" + Text::normal + "is a text-based game with the goal to survive and eventually free yourself.\n", 0);
    
	
	Engine::println("Text commands in the form of: " + Text::b_red +  "<command>" + Text::b_blue +" <argument>" + Text::normal + " or just " + Text::b_red + "<command>" + Text::normal + " are your way of controling your player and interacting with your surroundings", 0);
	Engine::println("Interactable items will appear with " +Text::blue +"blue" + Text::normal + " colored text.\n", 0);
    Engine::println("The "+ Text::b_green + "help" + Text::normal + " command shows you all available commands at that time. \n",0);
    
	Engine::println(Text::red + "Red" + Text::normal + " prompt symbols indicate the player's involvement with the game\n", 0);
	Engine::println(Text::red + "\n- Meaning of prompt symbols -\n" + Text::normal, 0);
	Engine::println("(" + Text::red + ">" + Text::normal + "): The main prompt symbol. You are controling your character in real life", 0);
	Engine::println("(" + Text::red + "$" + Text::normal + "): The terminal prompt symbol. You have entered the terminal and have now the ability to write commands in it", 0);
	Engine::println("(" + Text::red + "#" + Text::normal + "): The safe prompt symbol. This symbol appears when you are searching an unlocked safe. You can collect and/or save items", 0);
	
	Engine::println("Use your mind to discover clues, solve puzzles and connect the story-dots so you can discover what secrets exist in the depths of space...",0);
}
