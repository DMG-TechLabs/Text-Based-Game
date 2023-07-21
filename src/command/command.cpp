#include "command.h"

#include "engine.h"
#include "items.h"

using namespace Engine;
using namespace CliKit;

namespace CommandUtils{
    void getAvailableCommands(Prompt p);
    bool contains(vector<Item *> arr, string item);
    bool contains(vector<string> arr, string item);
}

int matchItemByName(string item, vector<Item> items);

bool Engine::Command::run(Response response, Prompt p, Player *player) {
    int item_index;
    Item *item_ptr;
    
    ReadableItem *ri;
    CollectableItem *ci;
    OpenableItem *oi;
    EnterableItem *ei;
    SaveableItem *si;
    UnlockableItem *ui;
    SearchableItem *sei;
    BundleItem *bi;

    if(sizeof(response) == 0){
        Engine::Command::run(prompt(p, command_list), p, player);
        delete item_ptr;
        return false;
    }

    switch (response.args.size()) {
        case 0:
            if(response.command == "enter") return false;
            if (response.command == "help"){
                CommandUtils::getAvailableCommands(p);
                return true;
            }
            if (response.command == "inventory"){
                player->getInventory().printInventory();
                return true;
            }
            if (response.command == "sleep" && CommandUtils::contains(player->currentNode->items, "bed")){
                if(!player->getMission()->isCompleted()){
                    println("Complete your objectives first", 0);
                    return false;
                }

                dynamic_cast<Bed *>(player->currentNode->items.at(matchItemByName("bed", player->currentNode->items)))->sleep();
                return true;
            } 
            if(response.command == "objectives"){
                Objective::printObjectives(player->getMission()->objectives);
                return true;
            }
            return false;            
        case 1:
            item_index = matchItemByName(response.args.at(0), player->currentNode->items);
            if (item_index < 0 && response.args.at(0) != "passcode") {
                if(CommandUtils::contains(items_list, response.args.at(0))){
                    println("This item is not in the room you are currently in", 0);
                    return false;
                } else {
                    println("Invalid item", 0);
                    return false;
                }

                return false;
            } else if(response.args.at(0) == "passcode") item_index = 0;

            item_ptr = player->currentNode->items.at(item_index);

            // Check if the command matches one of items interfaces
            // If the casting gives NULL it means that the object doesn't implement
            // the interface
            ri = dynamic_cast<ReadableItem *>(item_ptr);
            ci = dynamic_cast<CollectableItem *>(item_ptr);
            oi = dynamic_cast<OpenableItem *>(item_ptr);
            ei = dynamic_cast<EnterableItem *>(item_ptr);
            si = dynamic_cast<SaveableItem *>(item_ptr);
            ui = dynamic_cast<UnlockableItem *>(item_ptr);
            sei = dynamic_cast<SearchableItem *>(item_ptr);
            bi = dynamic_cast<BundleItem *>(item_ptr);
            
            if (response.command == "read" && ri != NULL) {
                ri->readContents();
                return true;
            } 
            if (response.command == "collect" && ci != NULL) {
                ci->collect(player);
                return true;
            } 
            if((response.command == "open" && oi != NULL)){
                return oi->open(player);
            }
            if(response.command == "enter" && ei != NULL){
                ei->enter(player);
                return true;
            }
            if(response.command == "inspect"){
                println(item_ptr->getDescription());
                return true;
            }
            if(response.command == "save" && si != NULL){
                si->save();
                return true;
            }
            if(response.command == "unlock" && ui != NULL && dynamic_cast<Door *>(ui) != NULL){ // Unlocking the door (It needs to unlock the room at the same time)     
                dynamic_cast<Door *>(ui)->enterPasscode(player);
                return true;
            } 
            if(response.command == "unlock" && ui != NULL){
                ui->enterPasscode();
                return true;
            }
            if(response.command == "search" && sei != NULL) {
                sei->search(player);
                return true;
            } 
            
            
            println("The command doesn't match the item", 0);
            return false;
            
            break;
        default:
            println("This number of arguments is not yet implemnted", 0);
            break;
    }

    return false;
}

/* Utils */
void CommandUtils::getAvailableCommands(Prompt p) {
    println("-" + Text::b_green + "Available commands" + Text::normal + "-", 0);
    for (int i = 0; i < p.accepted_commands.size(); i++) {
        cout << Text::red << i + 1 << ". " << Text::normal << p.accepted_commands.at(i)
             << endl;
    }
}

int matchItemByName(string item, vector<Item *> items) {
    if(item == "noor") item = "door"; // Easter egg

    for (int i = 0; i < items.size(); i++) {
        if (item == items.at(i)->getName()) {
            return i;
        }
    }

    return -1;
}

int matchItemById(string item, vector<Item *> items) {
    for (int i = 0; i < items.size(); i++) {
        if (item == items.at(i)->getItemId()) {
            return i;
        }
    }

    return -1;
}

bool CommandUtils::contains(vector<Item *> arr, string item) {
    bool exists = false;
    for (int i = 0; i < arr.size(); i++) {
        if (item == arr.at(i)->getName()) {
            exists = true;
            break;
        }
    }

    return exists;
}

bool CommandUtils::contains(vector<string> arr, string item) {
    bool exists = false;
    for (int i = 0; i < arr.size(); i++) {
        if (item == arr.at(i)) {
            exists = true;
            break;
        }
    }

    return exists;
}
