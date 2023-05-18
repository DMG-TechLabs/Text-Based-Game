#include "menu_win.h"

#include "../../Text-Based-Game-Engine/Engine/src/engine.h"

#include <iostream>
// #include <conio.h>
// #include <windows.h>

using namespace std;

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int handleArrowKeys(){
    switch (_getch()){
        case '\n': return 0;
        case 65: return 1;
        case 66: return 2;
        case 67: return 3;
        case 68: return 4;
        default: return -1;
    }
}

void mainMenu() {
    int selectedItem = 1;
    bool menuActive = true;

    string option1 = "Play";
    string option2 = "Manual";
    string option3 = "Settings";
    
    while (menuActive) {
        system("cls"); // Clear the screen

        // Print menu options
        gotoxy(0, 0);
        std::cout << "Menu" << std::endl;
        std::cout << (selectedItem == 1 ? Engine::Text::color("bg", 4) + option1 + Engine::Text::normal : option1) << std::endl;
        std::cout << (selectedItem == 2 ? Engine::Text::color("bg", 4) + option2 + Engine::Text::normal : option2) << std::endl;
        std::cout << (selectedItem == 3 ? Engine::Text::color("bg", 4) + option3 + Engine::Text::normal : option3) << std::endl;
        std::cout << (selectedItem == 4 ? Engine::Text::color("bg", 4) + "Exit" + Engine::Text::normal : "Exit") << std::endl;
        // Handle user input
        int arrowKeyPressed = handleArrowKeys();
        switch (arrowKeyPressed) {
            case 1: // Up arrow key
                selectedItem = (selectedItem == 1) ? 4 : selectedItem - 1;
                break;
            case 2: // Down arrow key
                selectedItem = (selectedItem == 4) ? 1 : selectedItem + 1;
                break;
            case 0:
                menuActive = false;
                switch (selectedItem){
                    case 1:
                        Engine::println("Play selected", 0);
                        break;
                    case 2:
                        Engine::println("Manual selected", 0);
                        break;
                    case 3:
                        Engine::println("Settings selected", 0);
                        break;
                    case 4:
                        Engine::println("Exit selected", 0);
                        break;
                    default:
                        break;
                    }
                break; 
        }
    }
}