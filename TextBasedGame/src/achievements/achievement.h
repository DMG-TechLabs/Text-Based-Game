#pragma once
#include <string>
#include <vector>

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
        Achievement(){};
        Achievement(string name, string description){
            this->name = name;
            this->description = description;
        };

        //Setters getters
        void setName(string name);
        string getName();
        void setDescription(string name);
        string getDescription();
        void setUnlocked(bool unlocked);
        bool isUnlocked();

        //Methods
        void unlock();



};

