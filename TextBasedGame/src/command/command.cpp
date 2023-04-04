#include "command.h"
#include "../terminal/prompt.h"



// template<typename Base, typename T>
// inline bool instanceof(const T *ptr) {
//    return dynamic_cast<const Base*>(ptr) != nullptr;
// }


// Print the description of an item
void Command::Run(string *command, Item *item){
    if ( command == NULL || item == NULL || *command == "") return;
    else if( *command == "inspect") {
        cout << item->getDescription() << endl;
    }else print("Something was wrong!");
}
    
/*
    Move the player from one move to onether

    Change the possition variable (2) of the player (1) into the new room ang
    set the player into the room (3)
*/
void Command::Run(string *command, Player *player, Node *room){
    if ( command == NULL || player == NULL || room == NULL || *command == "") return;
    else if (*command == "move")
    {
        if(room->number >= 0 || room->number < MAX_ROOMS) {
            player->position = room->number;
            //room->setPlayer(player);
        }else print("This room doesn't exist!");
    }else print("Something was wrong!");
}
