#include "achievements.h"

class achievements{

public:
    bool unlocked = false;
    string name;

    achievements(/* args */){}
    ~achievements(){}

    void setName( string name ){ this->name = name;}
    string getName( void ){return name;}

};