#ifdef _WIN32
    #include <conio.h>
    #include <windows.h>
#else
    #include <termios.h>
    #include <unistd.h>
    #include <ncurses.h>
#endif


#include <iostream>

#include "controls.h"

int Mastermind::handleKeys() {
    #ifdef _WIN32
        switch (_getch()) {
            case 13:
                return ENTER;
            case 64:
                return F4;
            case 72:
                return UP;
            case 80:
                return DOWN;
            case 37:
                return LEFT;
            case 39:
                return RIGHT;
            default:
                return -1;
        }
    #else
        switch (getchar()){
            case '\n': return ENTER;
            case '=': return EQUALS;
            case 65: return UP;
            case 66: return DOWN;
            case 67: return RIGHT;
            case 68: return LEFT;
            default: return -1;
        }
    #endif
}

void Mastermind::enableInputBuffering() {
    #ifdef _WIN32
        SetConsoleMode(hInput, mode);
    #else
        termios term;
        tcgetattr(STDIN_FILENO, &term);
        term.c_lflag |= (ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &term);

    #endif
    std::cout << "\e[?25h";  // Show the cursor
}

void Mastermind::disableInputBuffering() {
    #ifdef _WIN32
        DWORD mode;
        HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
        GetConsoleMode(hInput, &mode);
        SetConsoleMode(hInput, mode & ~ENABLE_ECHO_INPUT & ~ENABLE_LINE_INPUT);
    #else
        termios term;
        tcgetattr(STDIN_FILENO, &term);
        term.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &term);

    #endif
    std::cout << "\e[?25l";  // Hide the cursor
}