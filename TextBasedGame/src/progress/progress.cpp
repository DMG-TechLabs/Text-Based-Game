#include "progress.h"

unordered_map<std::string, std::string> Save::createHashTable(){
    unordered_map<std::string, std::string> u = {
        {"inventory", this->inventory->exportContents()},
        {"day", to_string(this->day)},
        {"achievements", this->ac->exportAchievements()},
        {"room", to_string(this->room->number)}
    };

    return u;
}

string Save::hashToString(){
    string s = "";
    
    s += "inventory: " + hash["inventory"] + "\n";
    s += "day: " + hash["day"] + "\n";
    s += "achievements: " + hash["achievements"] + "\n";
    s += "room: " + hash["room"];

    return s;
}

