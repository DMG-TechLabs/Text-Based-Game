#include "menu.h"

#include <ncurses.h>
#include <termios.h>
#include <unistd.h>
#include <iostream>
#include <stdio.h>

#include "../../Text-Based-Game-Engine/Engine/src/engine.h"
#include "../day/day.h"

using namespace std;
using namespace Menu;

#include <iostream>
#include <termios.h>
#include <unistd.h>

string addSpaces(string word, int length);
void printOption(int selectedItem, int index, int color, string option);
void menu(int bgColor, vector<string> options, void (*handleOptionsFunc)(int selectedOption));
void disableInputBuffering();
void enableInputBuffering();


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
            break;
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
            break;
    }
}

void Menu::pauseMenu(){
    menu(4, {"Continue", "Manual", "Achievements", "Exit"}, &handlePauseOptions);
}








void disableInputBuffering() {
    termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &term);

    print("\e[?25l"); // Hide the cursor
}

void enableInputBuffering() {
    termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag |= (ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &term);

    print("\e[?25h"); // Show the cursor
}

int handleArrowKeys(){
    switch (getchar()){
        case '\n': return 0;
        case 65: return 1;
        case 66: return 2;
        case 67: return 3;
        case 68: return 4;
        default: return -1;
    }
}


// General menu function
void menu(int bgColor, vector<string> options, void (*handleOptionsFunc)(int selectedOption)){
    disableInputBuffering();

    int numOfOptions = options.size();

    int max = 15;
    int selectedItem = 1;
    bool menuActive = true;

    // Add the necessary spaces
    for(string option : options){
        option = addSpaces(option, max);
    }

    while (menuActive) {
        system("clear"); // Clear the screen

        // Print the options
        for (int i = 0; i < numOfOptions; i++){
            printOption(selectedItem, i+1, bgColor, options.at(i));
        }
        
        // Handle user input
        int keyPressed = handleArrowKeys();
        switch (keyPressed) {
            case 1: // Up arrow key
                selectedItem = (selectedItem == 1) ? numOfOptions : selectedItem - 1;
                break;
            case 2: // Down arrow key
                selectedItem = (selectedItem == numOfOptions) ? 1 : selectedItem + 1;
                break;
            case 0: // Enter
                menuActive = false;
                system("clear");
                handleOptionsFunc(selectedItem);
                break;
        }

    }
    enableInputBuffering();
}

string addSpaces(string word, int length){
    if(length < word.size()) return "WRONG";

    while(word.size() < length){
        word += " ";
    }
    return word;
}

void printOption(int selectedItem, int index, int color, string option){
    std::cout << (selectedItem == index ? Engine::Text::color("bg", color) + option + Engine::Text::normal : option) << std::endl;
}