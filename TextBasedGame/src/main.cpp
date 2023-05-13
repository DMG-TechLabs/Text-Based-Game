#include <iostream>
#include <vector>

#include "../Text-Based-Game-Engine/Engine/src/engine.h"
#include "./command/command.h"
#include "./items/items.h"
#include "./map/map.h"
#include "./text/text.h"

int main() {

    Node *start = new Node();
    start->setId(1);
    start->setDescription("The starting room");
    start->addItem(new Note{"dmg-techlabs.theworkpc.com"});
    start->addItem(new Terminal{'$', "Linux Terminal", vector<string>{"ls", "cd"}});
    start->unlock();

    Map map{};
    map.addNode(start);
    map.addNode(new Node(2, "A new node", true), vector<int>{1});


    Inventory inventory{};

    Player player{};
    player.setInventory(inventory);
    player.addCommand("help");
    player.addCommand("read");
    player.addCommand("enter");
    player.currentNode = start;

    Prompt p;
    p.prompt_char = '>';
    p.message = "You wake up in a room you've never seen before. There is a desk with an open " + Text::red + "terminal" + Text::normal + " and a " + Text::red + "note" + Text::normal;
    p.accepted_commands = {"help", "read", "enter", "collect"};
    Response r = prompt(p, command_list);

    Engine::Command::run(r, &player);

    player.getInventory().printInventory();


    return 0;
}