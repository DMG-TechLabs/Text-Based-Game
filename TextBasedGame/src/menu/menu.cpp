#include "menu.h"

#include <ncurses.h>
#include <termios.h>
#include <unistd.h>
#include <iostream>
#include <stdio.h>

#include "../../Text-Based-Game-Engine/Engine/src/engine.h"
#include "../day/day.h"

using namespace std;

#include <iostream>
#include <termios.h>
#include <unistd.h>

string addSpaces(string word, int length);


void disableInputBuffering() {
    termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

void enableInputBuffering() {
    termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag |= (ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
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

void demoMenu(Player player, Map map) {
    int bgColor = 4;
    int numOfOptions = 3;
    int selectedItem = 1;
    bool menuActive = true;

    string option1 = addSpaces("Play Demo", sizeof("Settings") / sizeof(char) + 2);
    string option2 = addSpaces("Manual", sizeof("Settings") / sizeof(char) + 2);
    //string option3 = addSpaces("Settings", sizeof("Settings") / sizeof(char) + 2);
    string exit = addSpaces("Exit", sizeof("Settings") / sizeof(char) + 2);

    
    while (menuActive) {
        system("clear"); // Clear the screen

        // Print menu options
        std::cout << (selectedItem == 1 ? Engine::Text::color("bg", bgColor) + option1 + Engine::Text::normal : option1) << std::endl;
        std::cout << (selectedItem == 2 ? Engine::Text::color("bg", bgColor) + option2 + Engine::Text::normal : option2) << std::endl;
        //std::cout << (selectedItem == 3 ? Engine::Text::color("bg", bgColor) + option3 + Engine::Text::normal : option3) << std::endl;
        std::cout << (selectedItem == numOfOptions ? Engine::Text::color("bg", bgColor) + exit + Engine::Text::normal : exit) << std::endl;

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
                switch (selectedItem){
                    case 1:
                        enableInputBuffering();
                        Day::demo(&player, &map);
                        break;
                    case 2:
                        Engine::println("Manual selected", 0);
                        break;
                    // case 3:
                    //     Engine::println("Settings selected", 0);
                    //     break;
                    case 3:
                        println("Quiting game...");
                        std::exit(0);
                        break;
                    }
                break;
        }
    }
}

string addSpaces(string word, int length){
    if(length < word.size()) return "WRONG";

    while(word.size() < length){
        word += " ";
    }
    return word;
}

