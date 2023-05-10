#include <iostream>

#include "../Text-Based-Game-Engine/Engine/src/engine.h"
#include "./command/command.h"
#include "./items/items.h"
#include "./map/map.h"

#include "./text/text.h"

int main() {
/*
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

*/

    
    cout << "This is some " << Text::bold << "bold" << Text::normal << " text" << endl;
    cout << "This is some " << Text::underline << "underline" << Text::normal << " text" << endl;
    cout << "This is " << Text::red << "red" << Text::normal << " colored" << endl;
    cout << "This is " << Text::u_blue << "underlined blue" << Text::normal << " colored" << endl;
    cout << "This is " << Text::b_yellow << "bold yellow" << Text::normal << " colored" << endl;

    cout << Text::color("bg", 1) << "something" << Text::normal << endl;

    print("Hello world");
    println(Text::erase_line);

    return 0;
}