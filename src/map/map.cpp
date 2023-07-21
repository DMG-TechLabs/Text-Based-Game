#include "map.h"

#include "items.h"
#include "node_setup.h"

using namespace Engine;

string nodesToString(vector<Node *> nodes);

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
    NodeSetup::node6Setup(node6);

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

void printMap(Map map) {
    for (int i = 0; i < map.nodes.size(); i++) {
        println(
            "ID: " + to_string(map.nodes.at(i)->id) +
                ", Description: " + map.nodes.at(i)->description +
                ", Unlocked: " + to_string(map.nodes.at(i)->isAccessible()) +
                ", Accessible Nodes: " +
                nodesToString(map.nodes.at(i)->accessible_nodes),
            0);
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

