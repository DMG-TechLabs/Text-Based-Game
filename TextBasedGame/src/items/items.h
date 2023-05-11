#pragma once

// #include "../../Text-Based-Game-Engine/Engine/src/item/item.h"
#include "../../Text-Based-Game-Engine/Engine/src/engine.h"

class Note : public Item {
    public:
        ~Note() { setCommands(new string[2]{"read", "save"}); }
        Note(string id, string description) : Item(id, "note", description) {
            setCommands(new string[2]{"read", "save"});
        }
        Note(string description) : Item("note", description) {
            setCommands(new string[2]{"read", "save"});
        }

    void saveNote(string note_name);
};

class Terminal : public Item {
    public:
        char prompt_char;
        vector<string> internal_commands;

        ~Terminal() {}
        Terminal(char prompt_char, string description, vector<string> internal_commands) : Item("terminal", description) {
            this->prompt_char = prompt_char;
            this->internal_commands = internal_commands;

            setCommands(new string[2]{"enter", "exit"});
        }

        Response terminalPrompt(string message);
};