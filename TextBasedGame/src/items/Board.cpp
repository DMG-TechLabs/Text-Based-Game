#include "items.h"

#include "../../Text-Based-Game-Engine/Engine/src/engine.h"

namespace BoardUtils{
    string defaultPrint(Item *i, int index);
}


void Board::search(Player *p){
    println("Searching board...");

    printItems();
}

void Board::printItems() {
    for (int i = 0; i < bundle_items.size(); i++) {
        cout << BoardUtils::defaultPrint(bundle_items.at(i), i);
        ReadableItem *ri = dynamic_cast<ReadableItem *>(bundle_items.at(i));
        if (ri != NULL) {
            cout << ", Contents: " << ri->contents;
        }
        cout << endl;
    }
}

void Board::run(Response response, Prompt p, Player *player){
    cerr << "Is not implemented yet." << endl;
}

string BoardUtils::defaultPrint(Item *i, int index) {
    return to_string(index + 1) + ". Type: " + i->getName();
}