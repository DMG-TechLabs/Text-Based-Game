#include "node.h"

/**
 * @brief Will be called when a player tries to enter an inacessible room
 * 
 * @return std::string The description of the room the player tried to enter
 */
std::string Node::inaccessibleRoomDescription(){
            return this->description;
        }