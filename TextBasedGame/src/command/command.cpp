#include "../../Text-Based-Game-Engine/Engine/src/command/command.h"

#include "../items/items.h"
#include "../text/text.h"
#include "./command.h"

// template<typename Base, typename T>
// inline bool instanceof(const T *ptr) {
//    return dynamic_cast<const Base*>(ptr) != nullptr;
// }
/*
void Engine::Command::run(string command) {
    if (command == "" || &command == NULL) return;

    if (command == "help") {
        getAvailableCommands();
    }
}

// Print the description of an item
void Engine::Command::run(string command, Item item) {
    if (&command == NULL || &item == NULL || command == "")
        return;
    else if (command == "inspect") {
        print(item.getDescription());
    } else if (command == "read") {
        // File *file = (File) item;
        print(item.getDescription());
    } else if (command == "save") {
        // saveToFile(item->getName(),item->getDescription());
    } else if (command == "enter") {
        print(dynamic_cast<Terminal *>(&item)->getDescription());
        dynamic_cast<Terminal *>(&item)->terminalPrompt("");
    } else
        print("Something was wrong!");
}

// void Command::run(string *command, Player *player, int number_of_items, ...){
//     if ( command == NULL || *command == "" || number_of_items < 2) return;
//     else if( *command == "craft") {
//         //for(int i=0; i< end(item)-begin(item);i++){
//         string items_names = "";
//         va_list valist;
//         int i;
//         va_start(valist, number_of_items); //initialize valist for num number
//         of arguments for (i = 0; i < number_of_items; i++) { //access all the
//         arguments assigned to valist
//             items_names += va_arg(valist, Item->getName());//->getName();
//             //player->removeFromInventory(va_arg(valist, int));
//         }
//         va_end(valist); //clean memory reserved for valist
//         Item crafted_item = available_items_for_crafting[items_names];
//         //player->putItemIntoInventory(&crafted_item);
//     }else print("Something was wrong!");
// }


void Engine::Command::run(string command, Player *player, Node *room) {
    if (&command == NULL || player == NULL || room == NULL || command == "")
        return;
    else if (command == "move") {
        if (room->id >= 0 || room->id < MAX_ROOMS) {
            // player->position = room->number;
            // room->setPlayer(player);
        } else
            print("This room doesn't exist!");
    } else
        print("Something was wrong!");
}

void Engine::Command::run(string command, Player *player, Item item) {
    if (&command == NULL || player == NULL || &item == NULL || command == "")
        return;
    else if (command == "collect") {
        // player->putItemIntoInventory(*item);
    } else
        print("Something was wrong!");
}
*/
/*==================================================*/
void Engine::Command::run(Response response, Player *player) {
    int item_index, args_num;

    args_num = response.args.size();
    if(args_num == 1){
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
            println("Item doesn't implement any of the interfaces");
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
/*======================================================*/
/*
void runCommand(Response r, vector<Item> items) {
    runCommand(r.command, r.args, items);
}

void runCommand(string command, vector<string> args, vector<Item> items) {
    int index_to_use = -1;
    if (args.size() == 1) {
        // checking which item from the list to use based on the argument
        index_to_use = matchItem(args.at(0), items);
    }

    // Different handling for 2 args...

    if (index_to_use < 0) return;

    Engine::Command::run(command, items.at(index_to_use));
}*/