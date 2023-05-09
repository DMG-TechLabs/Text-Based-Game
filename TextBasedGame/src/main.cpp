#include <iostream>

#include "../Text-Based-Game-Engine/Engine/src/engine.h"
#include "./command/command.h"
#include "./items/items.h"
#include "./map/map.h"

int main() {
    // Node *start = new Node(1, "The starting room",
    // vector<Item>{Note{"dmg-techlabs.thewokpc.com"}, Terminal{'$', "Linux
    // Terminal", new string[2]{"ls", "cd"}}});

    Node *start = new Node();
    start->setId(1);
    start->setDescription("The starting room");
    start->addItem(Note{"dmg-techlabs.theworkpc.com"});
    start->addItem(Terminal{'$', "Linux Terminal", new string[2]{"ls", "cd"}});
    start->unlock();

    Map map{};
    // map.addNode(new Node(2, "A new node", true), vector<int>{1});

    Inventory inventory{};
    inventory.addItem(Note{"1", "test"});

    Player player{};
    player.setInventory(inventory);
    player.addCommand("help");
    player.addCommand("read");
    player.addCommand("enter");
    player.currentNode = start;

    player.collectItem(Note{"2", "A note"});

    player.getInventory().printInventory();

    return 0;
}