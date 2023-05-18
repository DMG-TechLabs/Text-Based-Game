#include "./command.h"

#include "../../Text-Based-Game-Engine/Engine/src/engine.h"
#include "../items/items.h"

using namespace Engine;

void getAvailableCommands(Prompt p);
int matchItem(string item, vector<Item> items);
int matchItem(string item, vector<Item *> items);
bool contains(vector<Item *> arr, string item);

void Engine::Command::run(Response response, Prompt p, Player *player) {
    int item_index;
    Item *item_ptr;
    
    ReadableItem *ri;
    CollectableItem *ci;
    OpenableItem *oi;
    EnterableItem *ei;
    SaveableItem *si;
    Bed *bi;

    if(sizeof(response) == 0){
        Engine::Command::run(prompt(p, command_list), p, player);
        delete item_ptr;
        return;
    }

    switch (response.args.size()) {
        case 0:
            if (response.command == "help")
                getAvailableCommands(p);
            else if (response.command == "inventory")
                player->getInventory().printInventory();
            else if (response.command == "sleep" && contains(player->currentNode->items, "bed")){
                dynamic_cast<Bed *>(player->currentNode->items.at(matchItem("bed", player->currentNode->items)))->sleep();
            }

            // Misc commands so prompt again
            // Engine::Command::run(prompt(p, command_list), p, player);
            break;
        case 1:
            item_index = matchItem(response.args.at(0), player->currentNode->items);
            if (item_index < 0) {
                println("This item is not found in the room you are in");
                return;
            }

            item_ptr = player->currentNode->items.at(item_index);

            // Check if the command matches one of items interfaces
            // If the casting gives NULL it means that the object doesn't implement
            // the interface
            ri = dynamic_cast<ReadableItem *>(item_ptr);
            ci = dynamic_cast<CollectableItem *>(item_ptr);
            oi = dynamic_cast<OpenableItem *>(item_ptr);
            ei = dynamic_cast<EnterableItem *>(item_ptr);
            si = dynamic_cast<SaveableItem *>(item_ptr);
            bi = dynamic_cast<Bed *>(item_ptr);
            
            if (response.command == "read" && ri != NULL) {
                ri->readContents();
            } else if (response.command == "collect" && ci != NULL) {
                ci->collect(player);
            } else if((response.command == "open" && oi != NULL) || (response.command == "open" && response.args.at(0) == "noor")){
                oi->open(player);
            } else if(response.command == "enter" && ei != NULL){
                ei->enter(player);
            } else if(response.command == "inspect"){
                println(item_ptr->getDescription(), 0);
            } else if(response.command == "save" && si != NULL){
                si->save();
            } else {
                println("The command doesn't match the item", 0);
            }
            
            break;
        default:
            println("This number of arguments is not yet implemnted", 0);
            break;
    }

    // delete item_ptr;
}

/* Utils */
void getAvailableCommands(Prompt p) {
    println("-" + Text::b_green + "Available commands" + Text::normal + "-", 0);
    for (int i = 0; i < p.accepted_commands.size(); i++) {
        cout << Text::red << i + 1 << ". " << Text::normal << p.accepted_commands.at(i)
             << endl;
    }
}

int matchItem(string item, vector<Item> items) {
    if(item == "noor") item = "door"; // Easter egg

    for (int i = 0; i < items.size(); i++) {
        if (item == items.at(i).getName()) {
            return i;
        }
    }

    return -1;
}

int matchItem(string item, vector<Item *> items) {
    if(item == "noor") item = "door"; // Easter egg
    
    for (int i = 0; i < items.size(); i++) {
        if (item == items.at(i)->getName()) {
            return i;
        }
    }

    return -1;
}

bool contains(vector<Item *> arr, string item) {
    bool exists = false;
    for (int i = 0; i < arr.size(); i++) {
        if (item == arr.at(i)->getName()) {
            exists = true;
            break;
        }
    }

    return exists;
}