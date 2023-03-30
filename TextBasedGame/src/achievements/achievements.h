#pragma once
#include <string>

using namespace std;

class Achievements{

    public:
        bool unlocked = false;
        string name;

        Achievements(){}
        ~Achievements(){}

        void setName(string name){}
        string getName(void){}

};
