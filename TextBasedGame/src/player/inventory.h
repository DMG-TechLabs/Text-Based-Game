#pragma once

#include "../item/item.h"

using namespace std;

/**
 * @brief Inventory class
 * 
 */
class Inventory {
    private:
        //Variables
        Item* items[32];
        int itemCount;
        
    public:
        //Constructors 
        Inventory();
        ~Inventory();
        Inventory(Item* items[]){
            for (int i = 0; i < 32; i++){
                this -> items[i] = items[i];
            }
        };
        
        //Getters
        Item* getItem();
        int getItemCount();

        //Auxilary methods
        void addItem(Item* item, int i);
        
        //For progress
        string exportContents();
        void importContents();

};