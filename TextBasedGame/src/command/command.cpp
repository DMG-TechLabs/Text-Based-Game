#include "./command.h"

#include "../../Text-Based-Game-Engine/Engine/src/engine.h"
#include "../items/items.h"

void getAvailableCommands();
int matchItem(string item, vector<Item> items);
int matchItem(string item, vector<Item *> items);

void Engine::Command::run(Response response, Prompt p, Player *player) {
    int item_index;
    Item *item_ptr;
    ReadableItem *ri;
    CollectableItem *ci;

    switch (response.args.size()) {
        case 0:
            if (response.command == "help")
                getAvailableCommands();
            else if (response.command == "inventory")
                player->getInventory().printInventory();

            // Misc commands so prompt again
            Engine::Command::run(prompt(p, command_list), p, player);
            break;
        case 1:
            item_index = matchItem(response.args.at(0), player->currentNode->items);
            if (item_index < 0) return;

            item_ptr = player->currentNode->items.at(item_index);

            // Check if the command matches one of items interfaces
            // If the casting gives NULL it means that the object doesn't implement
            // the interface
            ri = dynamic_cast<ReadableItem *>(item_ptr);
            ci = dynamic_cast<CollectableItem *>(item_ptr);
            if (response.command == "read" && ri != NULL) {
                ri->readContents();
            } else if (response.command == "collect" && ci != NULL) {
                ci->collect(player);
            } else {
                println("The command doesn't match the item");
            }
            
            break;
        default:
            println("This number of arguments is not yet implemnted");
            break;
    }

    delete item_ptr;
}

/* Utils */
void getAvailableCommands() {
    println("-" + Text::b_green + "Available commands" + Text::normal + "-");
    for (int i = 0; i < command_list.size(); i++) {
        cout << Text::red << i + 1 << ". " << Text::normal << command_list.at(i)
             << endl;
    }
}

int matchItem(string item, vector<Item> items) {
    for (int i = 0; i < items.size(); i++) {
        if (item == items.at(i).getName()) {
            return i;
        }
    }

    return -1;
}

int matchItem(string item, vector<Item *> items) {
    for (int i = 0; i < items.size(); i++) {
        if (item == items.at(i)->getName()) {
            return i;
        }
    }

    return -1;
}
