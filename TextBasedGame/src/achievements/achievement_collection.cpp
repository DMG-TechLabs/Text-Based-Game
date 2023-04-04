#include "achievement.h"
#include<iostream>


void AchievementCollection::initAchievements(){
    achievements.push_back(new Achievement("Beginning", "Lorem ipsum..."));
    achievements.push_back(new Achievement("End", "Lorem ipsum..."));
}

void AchievementCollection::printAchievements(){
    for(int i = 0; i < achievements.size(); i++) {
        cout << i << ". " << achievements.at(i)->getName() << " --> " << achievements.at(i)->getDescription() << endl;
    }
    
}

Achievement* AchievementCollection::nameToObject(string name){
    for(int i = 0; i < achievements.size(); i++) {
        if(achievements.at(i)->getName() == name){
            return achievements.at(i);
        }
    }
    return NULL;
}