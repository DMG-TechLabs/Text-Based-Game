#pragma once

#include "../item/item.h"

using namespace std;

/**
 * @brief Inventory class
 * 
 */
class Inventory {
    private:
        //Class variables
        Item* items[32];
        int itemCount;
        
    public:
        //Constructors 
        Inventory();
        ~Inventory();
        Inventory(Item* items[]);
        
        //Getters
        Item* getItem();
        int getItemCount();

        //Auxilary methods
        void addItem(Item* item, int i);

};