#pragma once

#include "../../Text-Based-Game-Engine/Engine/src/engine.h"
#include "../day/day.h"

using namespace Engine;

static const vector<string> items_list = {
    "note",
    "bed",
    "board",
    "terminal",
    "door",
    "file"
    "safe"
};

/* Interfaces */
class SearchableItem {
    public:
        virtual void search(Player *player) = 0;
        virtual void run(Response response, Prompt p, Player *player) = 0;
};

class BundleItem {
    public:
        vector<Item *> bundle_items;
        virtual void printItems() = 0;
};


class CollectableItem {
    public:
        virtual void collect(Player *player) = 0;
        virtual void collect(Player *player, BundleItem *bundle) = 0;
        virtual void collect(Player *player, BundleItem *bundle, int index) = 0;
};

class ReadableItem {
    public:
        string contents;
        virtual void readContents() = 0;
};

class OpenableItem {
    public:
        virtual bool open(Player *player) = 0;
};

class UnlockableItem {
    public:
        int passcode;
        bool isLocked;
        virtual bool enterPasscode() = 0;
        virtual void unlock() = 0;
};

class EnterableItem {
    public:
        virtual void enter(Player *player) = 0;
};

class SaveableItem {
    public:
        virtual void save() = 0;
};



/* Items */
class Note : public Item, public ReadableItem, public CollectableItem{
    public:
        ~Note() {}
        Note() {}
        Note(string id, string description) : Item(id, "note", description) {
        }
        Note(string contents) : Item("note") {
            ReadableItem::contents = contents;
        }
        Note(string id, string description, string contents) : Item(id, "note", description) {
            ReadableItem::contents = contents;
        }

        void saveNote(string note_name);
        void collect(Player *player) override;
        void collect(Player *player, BundleItem *bundle) override;
        void collect(Player *player, BundleItem *bundle, int index) override;
        void readContents() override;
};
class File : public Item, public ReadableItem, public SaveableItem {
    public:
        string title;

        ~File(){}
        File(string id, string title) : Item(id, "file"){
            this->title = title;
        }
        File(string id, string title, string description, string contents) : Item(id, "file", description){
            this->contents = contents;
            this->title = title;
        }
        File(string title, string description, string contents) : Item("file", description){
            this->title = title;
            this->contents = contents;
        }
        

        void readContents() override;
        void save() override;
};

class Terminal : public Item, public EnterableItem, public BundleItem{
    public:
        char prompt_char;
        vector<string> internal_commands;
        string mastermind_key;
        string mastermind_chars;
        string mastermind_reward;

        ~Terminal() {}
        Terminal() : Item("terminal") {}
        Terminal(char prompt_char, string description, vector<string> internal_commands, vector<File *> files) : Item("terminal", description) {
            this->prompt_char = prompt_char;
            this->internal_commands = internal_commands;
            addFiles(files);
        }

        void enter(Player *player) override;
        void printItems() override;
        void setKey(string key);
        void setChars(string chars);
        void setReward(string reward);

        void addFiles(vector<File *> files);
};

class Door : public Item, public OpenableItem, public UnlockableItem {
    public:
        ~Door(){}
        Door() : Item("door"){}
        Door(int passcode) : Item("door"){
            if(passcode > 10000) passcode = -1;

            this->passcode = passcode;
        }
        
        Door(int passcode, string description) : Item("door", description){
            if(passcode > 10000) passcode = -1;

            this->passcode = passcode;
        }
        
        Door(bool isLocked, int passcode, string description) : Item("door", description){
            if(passcode > 10000) passcode = -1;

            this->isLocked = isLocked;
            this->passcode = passcode;
        }

        int getPasscode();
        void setPasscode(int passcode);
        void enterPasscode(Player *player);

        void unlock() override;
        bool enterPasscode() override;
        bool open(Player *player) override;
};

class Bed : public Item {
    public:
        string epilogue;

        ~Bed(){}
        Bed(string epilogue, string description) : Item("bed", description){
            this->epilogue = epilogue;
        }

        void sleep();
};


class Board : public Item, public BundleItem, public SearchableItem {
    public:
        ~Board(){}
        Board(){}
        Board(vector<Item *> boardItems) : Item("board"){
            this->bundle_items = boardItems;
        }
        
        Board(string description, vector<Item *> boardItems) : Item("board", description){
            this->bundle_items = boardItems;
        }

        Board(string description) : Item("board", description){
        }

        void search(Player *player) override;
        void run(Response response, Prompt p, Player *player) override;
        void printItems() override;
};

class Safe : public Item, public BundleItem, public UnlockableItem, public SearchableItem {
    public:
        ~Safe(){}
        Safe(){}
        Safe(int passcode, string description, vector<Item *> safeItems, bool isLocked = true) : Item("safe", description){
            if(passcode > 10000) passcode = -1;

            this->bundle_items = safeItems;
            this->passcode = passcode;
            this->isLocked = isLocked;
        }
        Safe(int passcode, string description) : Item("safe", description){
            if(passcode > 10000) passcode = -1;

            this->passcode = passcode;
        }
        Safe(int passcode, bool isLocked = true) : Item("safe"){
            if(passcode > 10000) passcode = -1;

            this->passcode = passcode;
            this-> isLocked = isLocked;
        }


        void search(Player *player) override;
        void run(Response response, Prompt p, Player *player) override;
        void printItems() override;
        bool enterPasscode() override;   
        void unlock() override;
};