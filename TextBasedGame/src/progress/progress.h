#pragma once

#include <string>
#include <unordered_map>
#include <ctime>
#include <bits/stdc++.h>

#include "../player/inventory.h"
#include "../achievements/achievement.h"
#include "../map/node.h"
#include "../utils/game_utils.h"

using namespace std;

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

            
 
            std::time_t now = std::time(NULL);
            std::tm * ptm = std::localtime(&now);
            char buffer[32];
            std::strftime(buffer, 32, "%a, %d.%m.%Y %H:%M:%S", ptm);  
            
            string s(buffer);
            string date = s;
            saveToFile("../saves/save_" + date + ".txt", hashToString());
        }
};