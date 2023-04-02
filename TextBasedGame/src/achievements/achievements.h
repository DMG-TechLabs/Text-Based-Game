#pragma once
#include <string>

using namespace std;

/**
 * @brief Achievement class
 * 
 */
class Achievements{

    public:
        //Variables
        bool unlocked = false;
        string name;

        //Constructors
        Achievements();
        ~Achievements();

        //Setters getters
        void setName(string name);
        string getName();

};
