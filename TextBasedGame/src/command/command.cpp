#include "command.h"


void Command::getAvailableCommands(){
    print("Available commands");
    for (int i = 0; i < command_list->size(); i++){
        cout << command_list[i] << endl;
    }
}