#pragma once

#include "../../Text-Based-Game-Engine/Engine/src/node/node.h"

class Map{
    public:
        vector<Node*> nodes;

        Map(){}
        Map(int day){
            initMap(day);
        }
        ~Map(){}

        void initMap(int day);

        void addNode(Node *node, vector<int> connectedTo = {});
};   