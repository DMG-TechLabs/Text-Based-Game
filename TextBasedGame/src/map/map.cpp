#include "map.h"

#include "../items/items.h"

bool exists(vector<int> vector, int s) {
    for (size_t i = 0; i < vector.size(); i++) {
        if (vector.at(i) == s) return true;
    }

    return false;
}

void Map::initMap(int day) {
    /////////Node1//////////
    std::string N1Description;
    vector<string> N1AccesibleNodes;

    /////////Node2//////////
    vector<string> N2AccesibleNodes;

    /////////Node3//////////
    vector<string> N3AccesibleNodes;

    /////////Node4//////////
    vector<string> N4AccesibleNodes;

    /////////Node5//////////
    vector<string> N5AccesibleNodes;

    /////////Node6//////////
    vector<string> N6AccesibleNodes;

    /////////Node7//////////
    vector<string> N7AccesibleNodes;

    /////////Node8//////////
    vector<string> N8AccesibleNodes;

    /////////Node9//////////
    vector<string> N9AccesibleNodes;

    /////////Node10//////////
    vector<string> N10AccesibleNodes;

    /////////Node11//////////
    vector<string> N11AccesibleNodes;

    // nodes.push_back(new Node(
    //     1,
    //     "Starting room",
    //     vector<Item*>{new Terminal('$', "This is a linux terminal", new
    //     string[2]{"ls", "cd"})}, vector<Node*>{new Node()}, true, false
    //     ));
}

void Map::addNode(Node *node, vector<int> connectedTo) {
    vector<Node *> nodesToConnect;
    for (int i = 0; i < nodes.size(); i++) {
        if (exists(connectedTo, nodes.at(i)->id))
            nodesToConnect.push_back(nodes.at(i));
    }

    for (int i = 0; i < nodesToConnect.size(); i++) {
        node->addRoute(nodesToConnect.at(i)); // connect other nodes to new node
        for (int j = 0; j < nodes.size(); j++) {
            if(nodesToConnect.at(i)->id == nodes.at(j)->id) nodes.at(j)->addRoute(node); // connect new node to other nodes
        }
    }
}
