#include "../../Text-Based-Game-Engine/Engine/src/command/command.h"
#include "./command.h"
#include "../items/items.h"

/* ============={Utils}============= */

using namespace Engine;

bool contains(string *arr, string str) {
    int size = 0;
    while (!arr[size].empty()) ++size;

    bool exists = false;
    for (int i = 0; i < size; i++) {
        if (str == arr[i]) {
            exists = true;
            break;
        }
    }

    return exists;
}

int itemsLength(Item **items) {
    int length_counter = 0;
    while (items[length_counter]) length_counter++;

    return length_counter;
}

/* ============={End of Utils}============= */

// template<typename Base, typename T>
// inline bool instanceof(const T *ptr) {
//    return dynamic_cast<const Base*>(ptr) != nullptr;
// }

void Command::run(string command) {
    if (command == "" || &command == NULL) return;

    if (command == "help") {
        //getAvailableCommands();
    }
}

// Print the description of an item
void Command::run(string command, Item *item) {
    if (&command == NULL || item == NULL || command == "")
        return;
    else if (command == "inspect") {
        print(item->getDescription());
    } else if (command == "read") {
        // File *file = (File) item;
        print(item->getDescription());
    } else if (command == "save") {
        // saveToFile(item->getName(),item->getDescription());
    } else if (command == "enter") {
        print(dynamic_cast<Terminal *>(item)->getDescription());
        dynamic_cast<Terminal *>(item)->terminalPrompt("");
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

/*
    Move the player from one move to onether

    Change the possition variable (2) of the player (1) into the new room ang
    set the player into the room (3)
*/
void Command::run(string command, Player *player, Node *room) {
    if (&command == NULL || player == NULL || room == NULL || command == "")
        return;
    else if (command == "move") {
        if (room->number >= 0 || room->number < MAX_ROOMS) {
            // player->position = room->number;
            // room->setPlayer(player);
        } else
            print("This room doesn't exist!");
    } else
        print("Something was wrong!");
}

void Command::run(string command, Player *player, Item *item) {
    if (&command == NULL || player == NULL || item == NULL || command == "")
        return;
    else if (command == "collect") {
        // player->putItemIntoInventory(*item);
    } else
        print("Something was wrong!");
}

/*
void getAvailableCommands() {
    print("Available commands");
    for (int i = 0; i < ; i++) {
        cout << command_list[i] << endl;
    }
}*/

void Game::runCommand(string command, string arg, vector<Item*> items) {
    // cout << command << endl << arg << endl;

    Command *c = new Command();

    // checking which item from the list to use based from the argument
    int index_to_use = -1;
    for (int i = 0; i < items.size(); i++) {
        // cout << i << ". " << items[i]->getName() << endl;
        if (arg == items.at(i)->getName()) {
            index_to_use = i;
            break;
        }
    }

    // cout << index_to_use << endl;
    if (index_to_use < 0) return;

    //c->run(&command, items.at(index_to_use));
}