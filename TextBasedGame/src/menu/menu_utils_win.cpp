#include "menu.h"

#include "../../Text-Based-Game-Engine/Engine/src/engine.h"

#include "./menu_utils.h"


#include <iostream>
// #include <conio.h>
// #include <windows.h>

using namespace std;

string addSpaces(string word, int length);
void printOption(int selectedItem, int index, int color, string option);
void gotoxy(int x, int y); 
int handleArrowKeys();


// General menu function
void menu(int bgColor, vector<string> options, void (*handleOptionsFunc)(int selectedOption)){
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
        gotoxy(0, 0);

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