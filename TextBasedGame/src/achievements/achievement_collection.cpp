#include "achievement.h"
#include<iostream>


void AchievementCollection::initAchievements(){
    achievements.push_back(new Achievement("Beginning", "Lorem ipsum..."));
    achievements.push_back(new Achievement("End", "Lorem ipsum..."));

    achievements.at(1)->unlock();
}

void AchievementCollection::printAchievements(){
    for(int i = 0; i < achievements.size(); i++) {
        cout << i << ". " << achievements.at(i)->getName() << "\n   " << achievements.at(i)->getDescription() << "\n   " << achievements.at(i)->isUnlocked() << endl;
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

string AchievementCollection::exportAchievements(){
    string s = "";

    for (int i = 0; i < achievements.size(); i++){
        if(i == achievements.size() - 1){
            s += to_string(achievements.at(i)->isUnlocked());
            break;
        }
        
        s += to_string(achievements.at(i)->isUnlocked()) + ",";
    }
    return s;
}

void AchievementCollection::importAchievements(string str){
    string flags[achievements.size()];

    int count = 0, search_from = 0;
    while(count < achievements.size()){
        flags[count++] = str.substr(search_from, str.find(',', search_from));
        search_from = str.find(',', search_from)+1;
    }

    for (int i = 0; i < achievements.size(); i++){
        if(flags[i] == "0")
            achievements.at(i)->setUnlocked(false);
        else
            achievements.at(i)->setUnlocked(true);

    }
    
    
    
}