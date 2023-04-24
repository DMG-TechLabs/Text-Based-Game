#include "node.h"

/**
 * @brief Method that moves player to a new node if it is accessible
 * 
 * @param newNode The node the player tries to move to
 */
void Node::moveNode(Node *newNode){
    
    /**
     * @brief If player tries to go to an inaccessible node, it will print the newNode description.
     * 
     */
    if (newNode->accesible == false)
    {
        print(newNode -> description);
    }

    /**
     * @brief If the player tries to enter an accessible node, it marks the current node as not inside and the new node as inside
     *        it also prints the new node  
     * 
     */
    else{
        this->inside = false;
        newNode->inside = true;
        print(newNode -> description);
        //setCurrentNode(newNode);
    }

}