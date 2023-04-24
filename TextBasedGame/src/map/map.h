#pragma once

#include "node.h"

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