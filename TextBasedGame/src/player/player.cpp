#include "player.h"
#include "inventory.h"

//Setters getters
void Player::setInventory(Inventory inventory){
    this -> inventory = inventory;
}

Inventory Player::getInventory(){
    return inventory;
}

void Player::setName(string name){
    this -> name = name;
}

string Player::getName(){
    return name;
}

vector<int> Player::getStats(){
    return stats;
}
void Player::setCurrentNode(Node *newNode){
    this->currentNode = newNode;
}
/*
void Node::moveNode(Node *newNode, Node *oldNode){
    
    //If player tries to go to an inaccessible node, it will print the newNode description.
    if (newNode->accesible == false)
    {
        print(newNode -> description);
    }
    
    //If the player tries to enter an accessible node, it marks the current node as not inside and the new node as inside
    //it also prints the new node  
    else{
        this->currentNode = newNode;
        newNode->inside = true;
        print(newNode -> description);
        setCurrentNode(newNode);
    }

} */