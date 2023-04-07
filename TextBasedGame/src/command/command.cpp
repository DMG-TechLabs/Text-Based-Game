#include "command.h"

// template<typename Base, typename T>
// inline bool instanceof(const T *ptr) {
//    return dynamic_cast<const Base*>(ptr) != nullptr;
// }


void Command::run(string *command){
    if(*command == "" || command == NULL) return;

    if(*command == "help"){
        getAvailableCommands();
    }
}

// Print the description of an item
void Command::run(string *command, Item *item){
    if ( command == NULL || item == NULL || *command == "") return;
    else if( *command == "inspect") {
        print(item->getDescription());
    }else if (*command == "read"){
        //File *file = (File) item;
        print(item->getDescription());
    }else if(*command == "save"){
        //saveToFile(item->getName(),item->getDescription());
    }
    else if(*command == "enter"){
        print(dynamic_cast<Terminal*>(item)->getDescription());
        dynamic_cast<Terminal*>(item)->terminalPrompt("");
    }
    else print("Something was wrong!");
}

// void Command::run(string *command, Player *player, int number_of_items, ...){
//     if ( command == NULL || *command == "" || number_of_items < 2) return;
//     else if( *command == "craft") {
//         //for(int i=0; i< end(item)-begin(item);i++){
//         string items_names = "";
//         va_list valist;
//         int i;
//         va_start(valist, number_of_items); //initialize valist for num number of arguments
//         for (i = 0; i < number_of_items; i++) { //access all the arguments assigned to valist
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
void Command::run(string *command, Player *player, Node *room){
    if ( command == NULL || player == NULL || room == NULL || *command == "") return;
    else if (*command == "move")
    {
        if(room->number >= 0 || room->number < MAX_ROOMS) {
            //player->position = room->number;
            //room->setPlayer(player);
        }else print("This room doesn't exist!");
    }else print("Something was wrong!");
}

void Command::run(string *command, Player *player, Item *item){
    if ( command == NULL || player == NULL || item == NULL || *command == "") return;
    else if (*command == "collect"){
        //player->putItemIntoInventory(*item);
    }else print("Something was wrong!");
}


void Command::getAvailableCommands(){
    print("Available commands");
    for (int i = 0; i < command_list->size(); i++){
        cout << command_list[i] << endl;
    }
}