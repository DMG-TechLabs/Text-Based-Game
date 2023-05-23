#include <conio.h>
#include <windows.h>

#include <iostream>

#include "../../Text-Based-Game-Engine/Engine/src/engine.h"
#include "./menu_utils.h"
#include "menu.h"

using namespace std;

string addSpaces(string word, int length);
void printOption(int selectedItem, int index, int color, string option);
void gotoxy(int x, int y);
int handleArrowKeys();

// General menu function
void menu(int bgColor, vector<string> options,
          void (*handleOptionsFunc)(int selectedOption)) {
    // Disable console input buffering
    DWORD mode;
    HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
    GetConsoleMode(hInput, &mode);
    SetConsoleMode(hInput, mode & ~ENABLE_ECHO_INPUT & ~ENABLE_LINE_INPUT);
    std::cout << "\e[?25l"; // Hide the cursor

    int numOfOptions = options.size();

    int max = 15;
    int selectedItem = 1;
    bool menuActive = true;

    // Add the necessary spaces
    for (int i = 0; i < options.size(); i++) {
        options.at(i) = addSpaces(options.at(i), max);
    }
    gotoxy(0, 0);
    while (menuActive) {
        system("cls");  // Clear the screen

        // Print the options
        for (int i = 0; i < numOfOptions; i++) {
            printOption(selectedItem, i + 1, bgColor, options.at(i));
        }

        // Handle user input
        int keyPressed = handleArrowKeys();
        switch (keyPressed) {
            case 1:  // Up arrow key
                selectedItem =
                    (selectedItem == 1) ? numOfOptions : selectedItem - 1;
                break;
            case 2:  // Down arrow key
                selectedItem =
                    (selectedItem == numOfOptions) ? 1 : selectedItem + 1;
                break;
            case 0:  // Enter
                menuActive = false;
                system("cls");
                handleOptionsFunc(selectedItem);
                break;
        }
    }
    // Enable console input buffering
    SetConsoleMode(hInput, mode);
    std::cout << "\e[?25h"; // Show the cursor
}

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int handleArrowKeys() {
    switch (_getch()) {
        case 13:  // Enter
            return 0;
        case 72:  // Up
            return 1;
        case 80:  // Down
            return 2;
        default:
            return -1;
    }
}

string addSpaces(string word, int length) {
    if (length < word.size()) return "WRONG";

    while (word.size() < length) {
        word += " ";
    }
    return word;
}

void printOption(int selectedItem, int index, int color, string option) {
    std::cout << (selectedItem == index ? Engine::Text::color("bg", color) +
                                              option + Engine::Text::normal
                                        : option)
              << std::endl;
}