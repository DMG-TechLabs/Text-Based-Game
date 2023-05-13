#pragma once

#include "../../Text-Based-Game-Engine/Engine/src/engine.h"

/* Interfaces */
class CollectableItem {
    public:
        virtual void collect(Player *player) = 0;
};

class ReadableItem {
    public:
        virtual void readContents() = 0;
};


/* Items */
class Note : public Item, public ReadableItem, public CollectableItem{
    public:
        ~Note() {}
        Note() { setCommands(new string[2]{"read", "save"}); }
        Note(string id, string description) : Item(id, "note", description) {
            setCommands(new string[2]{"read", "save"});
        }
        Note(string description) : Item("note", description) {
            setCommands(new string[2]{"read", "save"});
        }

        void saveNote(string note_name);
        void collect(Player *player) override;
        void readContents() override;
};

class Terminal : public Item {
    public:
        char prompt_char;
        vector<string> internal_commands;

        ~Terminal() {}
        Terminal() {}
        Terminal(char prompt_char, string description, vector<string> internal_commands) : Item("terminal", description) {
            this->prompt_char = prompt_char;
            this->internal_commands = internal_commands;

            setCommands(new string[2]{"enter", "exit"});
        }

        Response terminalPrompt(string message);
};

