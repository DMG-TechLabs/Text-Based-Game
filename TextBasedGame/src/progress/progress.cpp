#include "progress.h"

unordered_map<std::string, std::string> Save::createHashTable(){
    unordered_map<std::string, std::string> u = {
        {"inventory", this->inventory->exportContents()},
        {"day", to_string(this->day)},
        {"achievemets", " "},
        {"room", to_string(this->room.number)}
    };
}