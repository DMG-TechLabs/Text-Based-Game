#include <iostream>
#include <vector>
#include <unistd.h>

#include "../Text-Based-Game-Engine/Engine/src/engine.h"
#include "./command/command.h"
#include "./items/items.h"
#include "./map/map.h"
#include "./day/day.h"
#include "./interactions/interactions.h"

struct GameState{
    Player *player;
    Day *day;
};


int main() {
    Prompt p;
    Response r;
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




    println("You wake up tired in a room you've never seen before.");
    println("You panic!");
    println("You run to the door hoping you'll get out");

    p.prompt_char = '>';
    p.accepted_commands = {"open", "help"};
    p.message = "Open the " + Text::blue + "door" + Text::normal;
    r = prompt(p, command_list);
    Engine::Command::run(r, p, &player);


    FormattedPrint::playerTalking("Fuck!");
    
    println("After a quick scan of the room you notice an open terminal in a corner of the room", 3);

    println("You sit in front of the terminal and something pops up on the screen!");

    FormattedPrint::typingInTerminal("terminal", "You are awake");

    FormattedPrint::playerTalking("Is...someone talking to me?");

    FormattedPrint::typingInTerminal("player", "Who is this?");

    FormattedPrint::typingInTerminal("terminal", "It doesn't matter.");

    FormattedPrint::typingInTerminal("player", "Where am I?");

    FormattedPrint::typingInTerminal("terminal", "That doesn't matter either");

    FormattedPrint::typingInTerminal("player", "What CAN you tell me?");

    FormattedPrint::typingInTerminal("terminal", "...");

    FormattedPrint::typingInTerminal("player", "PLEASE");
    // more stuff here
    FormattedPrint::typingInTerminal("terminal", "We'll talk soon");

    println("Exiting...\n");

    FormattedPrint::playerTalking("Anyways.. Let's search the room");

    p.accepted_commands = {"read", "collect", "open", "help"};
    p.message = "";
    r = prompt(p);
    Engine::Command::run(r, p, &player);
    
    
    return 0;
}