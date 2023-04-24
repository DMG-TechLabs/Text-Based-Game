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

string Save::getCurrentDate(){
    std::time_t now = std::time(NULL);
    std::tm * ptm = std::localtime(&now);
    char buffer[32];
    std::strftime(buffer, 32, "%a, %d.%m.%Y %H:%M:%S", ptm);  
    
    string s(buffer);
    string date = s;

    return date;
}