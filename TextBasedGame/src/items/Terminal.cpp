
#include <iostream>
#include <cstdlib>
#include <string>

#include "../../Text-Based-Game-Engine/Engine/src/engine.h"
#include "../command/terminal_command.h"
#include "./items.h"
#include "../mastermind/game/game.h"


using namespace std;


bool isNumeric(const std::string& str) {
    char* endptr;
    std::strtod(str.c_str(), &endptr);

    // Check if all characters were successfully parsed
    return *endptr == '\0';
}


void Terminal::enter(Player *player) {
    println(Text::b_green + "Terminal >_" + Text::normal);
    Response r;
    Prompt p;
    p.prompt_char = this->prompt_char;
    p.accepted_commands = this->internal_commands;

    do {
        r = Engine::prompt(p, command_list, false);

        if(r.command == "hack"){
            bool solved = Mastermind::start(this->mastermind_key, this->mastermind_chars);
        
            if(solved){
                println(Text::green + "\n" + this->mastermind_reward + Text::normal);
            }
        }
        else
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

    string fileIndexString;
    int fileIndex;
    do {
        print("\n\nEnter file to read: ");
        getline(cin, fileIndexString);

        if(isNumeric(fileIndexString)) {
            fileIndex = stoi(fileIndexString);
        } else {
            println("Enter a number", 0);
            continue;
        }

    } while (fileIndex < 1 || fileIndex > bundle_items.size());

    Text::clearScreen();

    println(dynamic_cast<File *>(bundle_items.at(fileIndex-1))->contents);

    println("Press enter to continue...", 0);
    cin.get();
}

void Terminal::addFiles(vector<File *> files) {
    for (size_t i = 0; i < files.size(); i++) {
        bundle_items.push_back(files.at(i));
    }
}

void Terminal::setKey(string key){
    this->mastermind_key = key;
}
void Terminal::setChars(string chars){
    this->mastermind_chars = chars;
}
void Terminal::setReward(string reward){
    this->mastermind_reward = reward;
}