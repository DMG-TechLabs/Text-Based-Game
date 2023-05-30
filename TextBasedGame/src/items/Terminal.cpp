
#include <iostream>
#include <string>

#include "../../Text-Based-Game-Engine/Engine/src/engine.h"
#include "../command/terminal_command.h"
#include "./items.h"

using namespace std;

void Terminal::enter(Player *player) {
    println(Text::b_green + "Terminal >_" + Text::normal);
    Response r;
    Prompt p;
    p.prompt_char = this->prompt_char;
    p.accepted_commands = this->internal_commands;

    do {
        r = Engine::prompt(p, command_list, false);
        TerminalCommand::run(r, p, player);
    } while (r.command != "exit");
}

void Terminal::printItems() {
    if (bundle_items.empty()) {
        println("No files found");
        return;
    }

    for (int i = 0; i < bundle_items.size(); i++) {
        println(Text::red + to_string(i + 1) + Text::normal + ". " + dynamic_cast<File *>(bundle_items.at(i))->title, 0);
    }

    int fileIndex;
    do {
        print("\n\nEnter file to read: ");
        cin >> fileIndex;
    } while (fileIndex < 1 || fileIndex > bundle_items.size());

    Text::clearScreen();

    println(dynamic_cast<File *>(bundle_items.at(fileIndex-1))->contents);

    cin.get();
}

void Terminal::addFiles(vector<File *> files) {
    for (size_t i = 0; i < files.size(); i++) {
        bundle_items.push_back(files.at(i));
    }
}