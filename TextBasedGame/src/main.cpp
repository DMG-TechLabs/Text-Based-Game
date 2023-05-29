#include <iostream>
#include <vector>
#include <unistd.h>
#include <thread>
#include <atomic>

#ifdef _WIN32
    #include <conio.h>
#else
    #include <termios.h>
    #include <unistd.h>
    #include <fcntl.h>
#endif

#include "../Text-Based-Game-Engine/Engine/src/engine.h"
#include "./command/command.h"
#include "./items/items.h"
#include "./map/map.h"
#include "./day/day.h"
#include "./interactions/interactions.h"
#include "./menu/menu.h"


std::atomic<bool> gamePaused(false);


void checkEscapeKey() {
    #ifdef _WIN32
        HANDLE inputHandle = GetStdHandle(STD_INPUT_HANDLE);
        DWORD originalMode;
        GetConsoleMode(inputHandle, &originalMode);
        DWORD mode = originalMode & ~(ENABLE_LINE_INPUT | ENABLE_ECHO_INPUT);
        SetConsoleMode(inputHandle, mode);
    #else
        struct termios initialSettings, newSettings;
        int terminalDescriptor = STDIN_FILENO;

        // Save the current terminal settings
        tcgetattr(terminalDescriptor, &initialSettings);
        newSettings = initialSettings;

        // Disable canonical mode and input echo
        newSettings.c_lflag &= ~(ICANON | ECHO);

        // Apply the new settings
        tcsetattr(terminalDescriptor, TCSANOW, &newSettings);

        // Set the terminal file descriptor to non-blocking mode
        int flags = fcntl(terminalDescriptor, F_GETFL, 0);
        fcntl(terminalDescriptor, F_SETFL, flags | O_NONBLOCK);
    #endif

    while (true) {
        bool escapeKeyPressed = false;

        #ifdef _WIN32
            if (_kbhit() && _getch() == 27) {
                escapeKeyPressed = true;
            }
        #else
            char keyPressed;
            ssize_t bytesRead = read(terminalDescriptor, &keyPressed, 1);

            if (bytesRead >= 0 && keyPressed == 27) {
                escapeKeyPressed = true;
            }
        #endif

        if (escapeKeyPressed) {
            gamePaused = !gamePaused;

            if (gamePaused) {
                std::cout << "Game Paused\n";
            } else {
                std::cout << "Game Resumed\n";
            }
        }
    }

    #ifdef _WIN32
        SetConsoleMode(inputHandle, originalMode);
    #else
        // Restore the initial terminal settings
        tcsetattr(terminalDescriptor, TCSANOW, &initialSettings);
    #endif
}

int main() {
    Map map{new Node(0, "Hall", true)};
    Player player{};


    Menu::demoMenu();



    // std::thread escapeKeyThread(checkEscapeKey);

    Day::dayOne(&player, &map);
    Day::dayTwo(&player, &map);
    

    // escapeKeyThread.join();  // Wait for the input thread to finish 

    return 0;
}