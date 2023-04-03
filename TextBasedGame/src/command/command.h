#pragma once

#include <iostream>
#include <string>
#include <map>
#include "../item/item.h"
#include "../player/player.h"
#include "../node/node.h"


#define MAX_ROOMS 5

using namespace std;

/**
 * @brief Command class
 * 
 */
class Command {
    private:
    public:
        //string availabe_commands["see"];
        //Constructors
        Command();
        ~Command();


        template<typename T>
        void Run(string *command,  T **arg);

        

};