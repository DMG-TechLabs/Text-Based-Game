#pragma once

#include "../item/item.h"

using namespace std;

/**
 * @brief Inventory class
 * 
 */
class Inventory {
    private:
        Item* inventory[32];
        
    public:
        //Constructors 
        Inventory(){};
        ~Inventory(){};
        Inventory(Item* inventory[]){
            for (int i = 0; i < 32; i++){
                this -> inventory[i] = inventory[i];
            }
        };
        
        //Getters
        Item* getInventory();

        //Auxilary methods
        void addItem(Item* inventory[], Item* item);
        Item* getItem(Item* inventory[], Item* item);
        string* getStacks(Item inventory[], string items[]);
        
        //For progress
        string exportContents();
        void importContents();
};