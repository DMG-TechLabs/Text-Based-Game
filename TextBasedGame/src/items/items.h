#pragma once

#include "../../Text-Based-Game-Engine/Engine/src/engine.h"
#include "../day/day.h"

using namespace Engine;

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

class EnterableItem {
    public:
        virtual void enter(Player *player) = 0;
};

class SaveableItem{
    public:
        virtual void save() = 0;
};

class BundleItem {
    public:
};


/* Items */
class Note : public Item, public ReadableItem, public CollectableItem{
    public:
        string contents;

        ~Note() {}
        Note() {}
        Note(string id, string description) : Item(id, "note", description) {
        }
        Note(string description) : Item("note", description) {
        }
        Note(string id, string description, string contents) : Item(id, "note", description) {
            this->contents = contents;
        }
        Note(string description, string contents) : Item("note", description) {
            this->contents = contents;
        }

        void saveNote(string note_name);
        void collect(Player *player) override;
        void readContents() override;
};

class Terminal : public Item, public EnterableItem{
    public:
        char prompt_char;
        vector<string> internal_commands;

        ~Terminal() {}
        Terminal() : Item("terminal") {}
        Terminal(char prompt_char, string description, vector<string> internal_commands) : Item("terminal", description) {
            this->prompt_char = prompt_char;
            this->internal_commands = internal_commands;
        }

        Response terminalPrompt(string message);
        void enter(Player *player) override;
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
        string epilogue;

        ~Bed(){}
        Bed(string epilogue) : Item("bed"){
            this->epilogue = epilogue;
        }

        void sleep();
};

class Board : public Item {
    public:

};

class File : public Item, public ReadableItem, public SaveableItem {
    public:
        string title;
        string contents;

        ~File(){}
        File(string id, string title) : Item(id, "file"){
            this->title = title;
        }
        File(string id, string title, string description, string contents) : Item(id, "file", description){
            this->contents = contents;
            this->title = title;
        }

        void readContents() override;
        void save() override;
};