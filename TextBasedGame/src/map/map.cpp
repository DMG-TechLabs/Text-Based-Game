#include "../items/items.h"
#include "map.h"

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
    node6->description = "You look around you. You decide to examine the corner where the "+ Text::blue +"terminal"+ Text::normal + " is."  
        "\nThere is a table there and a chair. You decide to take a closer look."
        "\nThe chair looks rusty and the table looks old and dusty. It feels like everything is going to collapse anytime soon. "
        "\nYou decide to take a step back. You notice the "+ Text::blue + "board"+ Text::normal + ". It has a few pins laying around. All in all, nothing special. "
        "\nThen you decide to rest on the bed. It makes a screeching sound when you sit. "
        "\nAll of a sudden, you get a glimpse of something laying on the floor. It's a piece of paper."
        "\nYou take a closer look. It's actually a " + Text::blue + "note. " + Text::normal;
    node6->addItem(new Door(1234));
    node6->addItem(new Terminal('$', "Description", {"exit", "list"}));
    node6->addItem(new Note("", "Description", "ds5yA!bTc"));
    node6->addItem(new Bed("The description"));

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
        println("ID: " + to_string(map.nodes.at(i)->id) +
                ", Description: " + map.nodes.at(i)->description +
                ", Unlocked: " + to_string(map.nodes.at(i)->isAccessible()) +
                ", Accessible Nodes: " +
                nodesToString(map.nodes.at(i)->accessible_nodes), 0);
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