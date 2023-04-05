#pragma once

#include "../item/item.h"

using namespace std;

/**
 * @brief Inventory class
 * 
 */
class Inventory {
    private:
        Item* items[32];
        
    public:
        //Constructors 
        Inventory(){};
        ~Inventory(){};
        Inventory(Item* items[]){
            for (int i = 0; i < 32; i++){
                this -> items[i] = items[i];
            }
        };
        
        //Getters
        Item* getItems();

        //Auxilary methods
        void addItem(Item* items[], Item* item);
        Item* getItem(Item* items[], Item* item);
        
        //For progress
        string exportContents();
        void importContents();
};