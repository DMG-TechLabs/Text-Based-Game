#pragma once

#include <string>
#include "../player/inventory.h"
#include "../achievements/achievement.h"

class Save{
    public:
        Inventory *inventory;
        int day;
        AchievementCollection *ac;
        
        ~Save(){}
        Save(){}

};