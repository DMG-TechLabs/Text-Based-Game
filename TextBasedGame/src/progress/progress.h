#pragma once

#include <string>
#include <unordered_map>

#include "../player/inventory.h"
#include "../achievements/achievement.h"
#include "../map/node.h"
#include "../utils/game_utils.h"

class Save{
    private:
        unordered_map<std::string, std::string> createHashTable();
        string hashToString();
    public:
        Inventory *inventory;
        int day;
        AchievementCollection *ac;
        Node *room;
        unordered_map<std::string, std::string> hash;
        
        ~Save(){}
        Save(Inventory *inventory, int day, AchievementCollection *ac, Node *room){
            this->inventory = inventory;
            this->day = day;
            this->ac = ac;
            this->room = room;

            this->hash = createHashTable();

            saveToFile("save.txt", hashToString());
        }
};