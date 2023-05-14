#include "../../Text-Based-Game-Engine/Engine/src/engine.h"

#include "../items/items.h"
#include "./command.h"

void Engine::Command::run(Response response, Player *player) {
    int item_index, args_num;

    args_num = response.args.size();
    if(args_num == 0){
        if(response.command == "help")
            getAvailableCommands();
        else if(response.command == "inventory")
            player->getInventory().printInventory();

    } else if(args_num == 1){
        int item_index = matchItem(response.args.at(0), player->currentNode->items);
        if(item_index < 0) return;

        // Check if the command matches one of items interfaces
        // If the casting gives NULL it means that the object doesn't implement the interface
        ReadableItem *ri = dynamic_cast<ReadableItem *>(player->currentNode->items.at(item_index));
        CollectableItem *ci = dynamic_cast<CollectableItem *>(player->currentNode->items.at(item_index));
        if(response.command == "read" && ri != NULL){
            ri->readContents();
        } else if(response.command == "collect" && ci != NULL){
            ci->collect(player);
        } else {
            println("The command doesn't match the item");
        }
    }
}

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

int matchItem(string item, vector<Item*> items) {
    for (int i = 0; i < items.size(); i++) {
        if (item == items.at(i)->getName()) {
            return i;
        }
    }

    return -1;
}
