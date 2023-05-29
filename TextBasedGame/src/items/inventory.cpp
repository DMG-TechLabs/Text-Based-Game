#include "../../Text-Based-Game-Engine/Engine/src/engine.h"
#include "items.h"

using namespace Engine;

namespace InventoryUtils{
    bool exists(vector<Item> vector, Item *item);
    string defaultPrint(Item *i, Inventory *inventory);
}


void Engine::Inventory::printInventory() {
    vector<Item> passed;
    for(int i = 0; i < items.size(); i++) {
        if (!InventoryUtils::exists(passed, items.at(i))) { // Check if same item already exists
            cout << InventoryUtils::defaultPrint(items.at(i), this);
            ReadableItem *ri = dynamic_cast<ReadableItem *>(items.at(i));
            if(ri != NULL){
                cout << ", Contents: " << ri->contents;
            }
            cout << endl;
        }
        passed.push_back(*items.at(i));
    }
}

string InventoryUtils::defaultPrint(Item *i, Inventory *inventory){
    return "Type: " + i->getName() + ", Quantity: " + to_string(inventory->getQuantity(i)) + ", Description: " + i->getDescription();
}

// Utils
bool InventoryUtils::exists(vector<Item> vector, Item *item) {
    for (size_t i = 0; i < vector.size(); i++) {
        if (vector.at(i).getItemId() == item->getItemId()) return true;
    }

    return false;
}