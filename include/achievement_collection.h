#pragma once

#include <iostream>

#include "engine.h"

using namespace Engine;

class AchievementCollection{
    public:
        vector<Achievement*> achievements;

        ~AchievementCollection(){}
        AchievementCollection(){
            initAchievements();
        }

        void initAchievements();
        void printAchievements();
        Achievement* nameToObject(string name);
        string exportAchievements();
        void importAchievements(string str);
};
