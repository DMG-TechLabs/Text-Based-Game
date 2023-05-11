#pragma once

#include "../../Text-Based-Game-Engine/Engine/src/engine.h"

class Objective{
    private:
        string description;
        bool completed = false;
    
    public:
        Objective(){}
        ~Objective(){}

        Objective(string description){
            this->description = description;
        }

        void setDescription(string description);
        string getDescription();

        void setStatus(bool completed);
        bool isCompleted();
};