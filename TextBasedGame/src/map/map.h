#pragma once

#include "node.h"

class Map{
    public:
        vector<Node*> nodes;

        Map(){}
        Map(int day){
            initMap();
        }
        ~Map(){}

        void initMap();

        void printMap();

        Node* nameToObject(string name);
};   