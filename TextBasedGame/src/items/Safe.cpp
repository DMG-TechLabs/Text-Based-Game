#include "../../Text-Based-Game-Engine/Engine/src/engine.h"
#include "items.h"

namespace SafeUtils {
bool exists(vector<Item> vector, Item *item);
bool isNumber(string s);
string defaultPrint(Item *i, int index);
int matchItem(vector<Item *> items, string name, int index = -1);
}  // namespace SafeUtils

void Safe::search(Player *player) {
    if (this->isLocked) {
        println("Safe is locked", 0);
        return;
    }

    println("Searching the safe...");
    printItems();

    Prompt p;
    p.prompt_char = '-';
    p.accepted_commands = {"collect", "exit", "help"};
    Response r;

    while (r.command != "exit") {
        r = prompt(p);
        this->run(r, p, player);
    }
}

void Safe::run(Response response, Prompt p, Player *player) {
    CollectableItem *ci;

    switch (response.args.size()) {
        case 0:
            if (response.command == "exit") {
                return;
            }
            break;
        case 1:
            ci = dynamic_cast<CollectableItem *>(this->bundle_items.at(SafeUtils::matchItem(this->bundle_items, response.args.at(0))));

            if(response.command == "collect" && ci != NULL){
                ci->collect(player, this);

            } else {
                println("The command doesn't match the item", 0);
            }

            break;
        case 2:
            ci = dynamic_cast<CollectableItem *>(this->bundle_items.at(SafeUtils::matchItem(this->bundle_items, response.args.at(0), stoi(response.args.at(1)))));

            if(response.command == "collect" && ci != NULL){
                ci->collect(player, this);
            } else {
                println("The command doesn't match the item", 0);
            }

            break;
        default:
            println("This number of arguments is not yet implemnted", 0);
            break;
    }
}

void Safe::printItems() {
    for (int i = 0; i < bundle_items.size(); i++) {
        cout << SafeUtils::defaultPrint(bundle_items.at(i), i);
        ReadableItem *ri = dynamic_cast<ReadableItem *>(bundle_items.at(i));
        if (ri != NULL) {
            cout << ", Contents: " << ri->contents;
        }
        cout << endl;
    }
}

void Safe::unlock() { this->isLocked = false; }

bool Safe::enterPasscode() {
    string passcode;
    if (!this->isLocked) {
        println("Safe is already unlocked", 0);
        return true;
    }

    print("Enter passcode: ");
    getline(cin, passcode);

    if (!SafeUtils::isNumber(passcode)) {
        println("Invalid passcode", 0);
        return false;
    }

    if (stoi(passcode) != this->passcode) {
        println("Wrong passcode");
        return false;
    } else {
        this->unlock();
        println("Safe unlocked", 0);
        return true;
    }
}

int SafeUtils::matchItem(vector<Item *> items, string name, int index) {
    if (index == -1) {
        for (int i = 0; i < items.size(); i++) {
            if(name == items.at(i)->getName()){
                return i;
            }
        }
        return -1;
    }

    if(index > items.size() || index < 1) return -2;

    if(items.at(index-1)->getName() == name) return index-1;

    println("Item does not match the number given", 0);
    return -1;
}

bool SafeUtils::isNumber(string s) {
    return !s.empty() && std::find_if(s.begin(), s.end(), [](unsigned char c) {
                             return !std::isdigit(c);
                         }) == s.end();
}

string SafeUtils::defaultPrint(Item *i, int index) {
    return to_string(index + 1) + ". Type: " + i->getName() +
           ", Description: " + i->getDescription();
}

// Utils
bool SafeUtils::exists(vector<Item> vector, Item *item) {
    for (size_t i = 0; i < vector.size(); i++) {
        if (vector.at(i).getItemId() == item->getItemId()) return true;
    }

    return false;
}