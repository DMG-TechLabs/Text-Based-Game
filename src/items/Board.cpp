#include "items.h"

#include "engine.h"

namespace BoardUtils{
    string defaultPrint(Item *i, int index);
}


void Board::search(Player *p){
    println("Searching board...");

    println("You notice 4 pieces of papper pinned on the board. You go a little bit closer and you can now see that there are written words and numbers on them. You wonder if the note you found earlier is related to them.");

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
