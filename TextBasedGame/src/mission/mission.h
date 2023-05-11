#pragma once

#include "../../Text-Based-Game-Engine/Engine/src/engine.h"
#include "Objective.h"

/**
 * @brief Mission class
 * 
 */
class Mission{
    private:
        string name;
        string description;
        vector<Objective> objectives;
        bool completed = false;

    public:
        Mission(){}
        ~Mission(){}
        
        Mission(string name, string description, bool completed, vector<Objective> objectives){
            this->name = name;
            this->description = description;
            this->completed = completed;
            this->objectives = objectives;
        }

        void setName(string name);
        string getName();

        void setDescription(string description);
        string getDescription();

        void setStatus(bool completed);
        bool isCompleted();
}; 