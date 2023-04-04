#pragma once
#include <string>

using namespace std;


/**
 * @brief Achievement class
 * 
 */
class Achievement{
    private:
        bool unlocked = false;
        string name;
        string description;
    public:

        ~Achievement(){};
        Achievement(string name, string description){
            this->name = name;
            this->description = description;
        };

        //Setters getters
        void setName(string name);
        string getName();
        void setUnlocked(bool unlocked);
        bool isUnlocked();



};

class AchievementCollection{
    public:
        int SIZE = 20;
        Achievement *achievements;

        ~AchievementCollection(){}
        AchievementCollection(){
            initAchievements();
        }

        void initAchievements();
};