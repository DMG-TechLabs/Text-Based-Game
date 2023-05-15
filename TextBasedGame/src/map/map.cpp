#include "map.h"

#include "../items/items.h"

string nodesToString(vector<Node *> nodes);

bool exists(vector<int> vector, int s) {
    for (size_t i = 0; i < vector.size(); i++) {
        if (vector.at(i) == s) return true;
    }

    return false;
}

void Map::initMap() {
    // Init nodes
    Node *node1 = new Node(1, "Room 1", true);
    node1->addItem(new Door());

    Node *node2 = new Node(2, "Room 2", true);
    node2->addItem(new Door());

    Node *node3 = new Node(3, "Room 3", true);
    node3->addItem(new Door());

    Node *node4 = new Node(4, "Room 4", true);
    node4->addItem(new Door());

    Node *node5 = new Node(5, "Room 5", true);
    node5->addItem(new Door());

    Node *node6 = new Node(6, "Room 6", false);
    node6->addItem(new Door());
    node6->addItem(new Terminal());
    node6->addItem(new Note("ds5yA!bTc"));

    Node *node7 = new Node(7, "Room 7", true);
    node7->addItem(new Door());

    Node *node8 = new Node(8, "Room 8", true);
    node8->addItem(new Door());

    // Connect nodes to main hall and add them to map vector
    addNode(node1, vector<int>{0});
    addNode(node2, vector<int>{0});
    addNode(node3, vector<int>{0});
    addNode(node4, vector<int>{0});
    addNode(node5, vector<int>{0});
    addNode(node6, vector<int>{0});
    addNode(node7, vector<int>{0});
    addNode(node8, vector<int>{0});
}

void Map::addNode(Node *node, vector<int> connectedTo) {
    vector<Node *> nodesToConnect;
    for (int i = 0; i < nodes.size(); i++) {
        if (exists(connectedTo, nodes.at(i)->id))
            nodesToConnect.push_back(nodes.at(i));
    }

    for (int i = 0; i < nodesToConnect.size(); i++) {
        node->addRoute(
            nodesToConnect.at(i));  // connect other nodes to new node
        for (int j = 0; j < nodes.size(); j++) {
            if (nodesToConnect.at(i)->id == nodes.at(j)->id)
                nodes.at(j)->addRoute(node);  // connect new node to other nodes
        }
    }

    this->nodes.push_back(node);
}

Node *Map::getNode(int id) {
    for (int i = 0; i < nodes.size(); i++) {
        if (nodes.at(i)->id == id) return nodes.at(i);
    }
    return NULL;
}

void Map::printMap() {
    for (int i = 0; i < nodes.size(); i++) {
        println("ID: " + to_string(nodes.at(i)->id) +
                ", Description: " + nodes.at(i)->description +
                ", Unlocked: " + to_string(nodes.at(i)->isAccessible()) +
                ", Accessible Nodes: " +
                nodesToString(nodes.at(i)->accessible_nodes));
    }
}

string nodesToString(vector<Node *> nodes) {
    string s = "";
    for (int i = 0; i < nodes.size(); i++) {
        s += "ID: " + to_string(nodes.at(i)->id) +
             ", Description: " + nodes.at(i)->description + " \n\t\t\t\t\t";
    }
    return s;
}