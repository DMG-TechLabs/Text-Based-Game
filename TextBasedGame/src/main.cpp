#include <iostream>
#include <vector>

#include "../Text-Based-Game-Engine/Engine/src/engine.h"
#include "./command/command.h"
#include "./items/items.h"
#include "./map/map.h"

int main() {

    Node *start = new Node();
    start->setId(1);
    start->setDescription("You wake up in a room you've never seen before. There is a desk with an open " + Text::red + "terminal" + Text::normal + " and a " + Text::red + "note" + Text::normal);
    start->addItem(new Note{"dmg-techlabs.theworkpc.com"});
    start->addItem(new Terminal{'$', "Linux Terminal", vector<string>{"ls", "cd"}});
    start->unlock();

    Map map{};
    map.addNode(start);
    map.addNode(new Node(2, "A new node", true), vector<int>{1});

    Player player{};
    player.setInventory(Inventory{});
    player.addCommand("help");
    player.addCommand("read");
    player.addCommand("enter");
    player.currentNode = start;

    Prompt p;
    p.prompt_char = '>';
    p.message = player.currentNode->description;
    p.accepted_commands = {"help", "read", "enter", "collect", "inventory"};
    Response r = prompt(p, command_list);

    Engine::Command::run(r, p, &player);

    player.getInventory().printInventory();

    return 0;
}