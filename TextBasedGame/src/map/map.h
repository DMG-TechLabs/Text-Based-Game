#pragma once

#include "../../Text-Based-Game-Engine/Engine/src/map/node.h"

class Map{
    public:
        vector<Node*> nodes;

        Map(){}
        Map(int day){
            initMap(day);
        }
        ~Map(){}

        void initMap(int day);
};   