#pragma once

#include "../../Text-Based-Game-Engine/Engine/src/engine.h"
#include "../day/day.h"

static const vector<string> items_list = {
    "note",
    "bed",
    "board",
    "terminal",
    "door"
};

/* Interfaces */
class CollectableItem {
    public:
        virtual void collect(Player *player) = 0;
};

class ReadableItem {
    public:
        virtual void readContents() = 0;
};

class OpenableItem {
    public:
        virtual void open(Player *player) = 0;
};

class BundleItem {
    public:
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
        Terminal() : Item("terminal") {}
        Terminal(char prompt_char, string description, vector<string> internal_commands) : Item("terminal", description) {
            this->prompt_char = prompt_char;
            this->internal_commands = internal_commands;

            setCommands(new string[2]{"enter", "exit"});
        }

        Response terminalPrompt(string message);
};

class Door : public Item, public OpenableItem {
    private:
        int password;
    public:
        bool isOpen = false;

        ~Door(){}
        Door() : Item("door"){}
        Door(int password) : Item("door"){
            if(password > 10000) password = -1;

            this->password = password;
        }
        Door(bool isOpen, int password) : Item("door"){
            if(password > 10000) password = -1;

            this->isOpen = isOpen;
            this->password = password;
        }

        int getPassword();
        void setPassword(int password);
        void unlock();
        void enterPassword(int password);

        void open(Player *player) override;
};

class Bed : public Item {
    public:
        ~Bed(){}
        Bed() : Item("bed"){}

        void sleep();
};

class Board : public Item {
    public:

};