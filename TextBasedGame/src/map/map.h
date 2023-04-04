#pragma once

#include "node.h"

class Map{
    public:
        vector<Node*> nodes;

        ~Map(){}
        Map(){
            initMap();
        }

        void initMap();
        void printAMap();
        Node* nameToObject(string name);
};   