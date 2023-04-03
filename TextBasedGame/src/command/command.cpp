#include "command.h"

//instanceof<Item>(argument)

//Constructors
Command::Command(){}

Command::~Command(){}

void print(string s){ cout << s << endl;}

template<typename Base, typename T>
inline bool instanceof(const T *ptr) {
   return dynamic_cast<const Base*>(ptr) != nullptr;
}

template<typename T>
void Command::Run(string *command, T **args){
    if ( command == NULL || args == NULL || *command == "") return;

    // Print the description of an item
    if( *command == "inspect") {
        if(instanceof<Item>(*args[0])) cout << *args[0].description << endl;
        else print("This is not an item!");

    /*
        Move the player from one move to onether
    
        Change the possition variable (2) of the player (1) into the new room ang
        set the player into the room (3)
    */
    }else if (*command == "move")
    {
        /*
        1. args[0] : Player
        2. args[1] : Room Number
        3. args[2] : Room
        */
        if((*args[1] >= 0 || *args[1] < MAX_ROOMS) && instanceof<Player>(*args[0]) && instanceof<Node>(*args[2])) {
            *args[0].possition = *args[1];
            *args[2].setPlayer(*args[0]);
        }else print("Wrong command syntax!");

    }else if (*command == "")
    {
        /* code */
    }
    
    
}
