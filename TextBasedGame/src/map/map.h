#pragma once

#include "../../Text-Based-Game-Engine/Engine/src/node/node.h"

class Map{
    public:
        vector<Node*> nodes;

        Map(){
            nodes.push_back(new Node(0, "Hall", true));

            initMap();
        }
        Map(int day){
            nodes.push_back(new Node(0, "Hall", true));

            initMap(day);
        }
        ~Map(){}

        void initMap(int day);
        void initMap();
        Node *getNode(int id);
        void addNode(Node *node, vector<int> connectedTo = {});

        void printMap();
};   