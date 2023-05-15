#include <iostream>
#include <vector>
#include <unistd.h>

#include "../Text-Based-Game-Engine/Engine/src/engine.h"
#include "./command/command.h"
#include "./items/items.h"
#include "./map/map.h"

int main() {

    Map map{};

    Player player{};
    player.setInventory(Inventory{});
    player.addCommand("help");
    player.addCommand("read");
    player.addCommand("enter");
    player.currentNode = map.getNode(6); // We are in room 6

    // string player_name;
    // println("What's your name?", 0);
    // print("Type your name: ");
    // getline(cin, player_name);

    // println("", 0);
    // println("", 0);
    // println("", 0);

    // player.setName(player_name);



    println("===========TITLE OF THE GAME===========");

    println("You wake up tired in a room you've never seen before.");
    println("You panic!");
    println("You run to the door hoping you'll get out");

    Prompt p;
    p.prompt_char = '>';
    p.accepted_commands = {"open", "help"};
    p.message = "Open the " + Text::red + "door" + Text::normal;
    Response r = prompt(p, command_list);
    Engine::Command::run(r, p, &player);


    println(Text::italic + "\n-Fuck!\n" + Text::normal);


    println("After a quick scan of the room you notice an open terminal in a corner of the room", 5);

    println("You sit in front of the terminal and something pops up on the screen!");

    print("Terminal: ");
    Text::delayedTyping("You are awake " + player.getName() +  ".\n");

    println(Text::italic + "\n-Is...someone talking to me?\n" + Text::normal);

    print("$ ");
    Text::delayedTyping("Who is this?");
    
    
    return 0;
}