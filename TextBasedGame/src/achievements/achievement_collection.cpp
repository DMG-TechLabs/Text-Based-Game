#include "achievement.h"
#include<iostream>


void AchievementCollection::initAchievements(){
    achievements.push_back(new Achievement("Beginning", "Lorem ipsum..."));
}

void AchievementCollection::printAchievements(){
    for(int i = 0; i < achievements.size(); i++) {
        cout << i << ". " << achievements.at(i)->getName() << " --> " << achievements.at(i)->getDescription() << endl;
    }
    
}