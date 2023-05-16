#include "day.h"
#include "../command/command.h"
#include "../interactions/interactions.h"

#include "../../Text-Based-Game-Engine/Engine/src/engine.h"

using namespace Engine;

void Day::demo(Player *player, Map *map){
    Prompt p;
    Response r;

    player->setInventory(Inventory{});
    player->addCommand("help");
    player->addCommand("read");
    player->addCommand("enter");
    player->currentNode = map->getNode(6); // We are in room 6

    string player_name;
    println("What's your name?", 0);
    print("Type your name: ");
    getline(cin, player_name);

    println("", 0);
    println("", 0);
    println("", 0);

    player->setName(player_name);


    println("You wake up tired in a room you've never seen before.");
    println("You panic!");
    println("You run to the door hoping you'll get out");

    p.prompt_char = '>';
    p.accepted_commands = {"open", "help"};
    p.message = "Open the " + Text::blue + "door" + Text::normal;
    r = prompt(p, command_list, true);
    Command::run(r, p, player);


    FormattedPrint::playerTalking("Fuck!");
    
    println("After a quick scan of the room you notice an open terminal in a corner of the room", 3);

    println("You sit in front of the terminal and something pops up on the screen!");

    FormattedPrint::typingInTerminal("terminal", "You are awake " + player->getName());

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

    p.accepted_commands = {"read", "collect", "open", "help", "inventory"};
    // by Christina
    p.message = "You look around you. You decide to examine the corner where the "+ Text::blue +"terminal"+ Text::normal + " is."  
        "\nThere is a table there and a chair. You decide to take a closer look."
        "\nThe chair looks rusty and the table looks old and dusty. It feels like everything is going to collapse anytime soon. "
        "\nYou decide to take a step back. You notice the "+ Text::blue + "board"+ Text::normal + ". It has a few pins laying around. All in all, nothing special. "
        "\nThen you decide to rest on the bed. It makes a screeching sound when you sit. "
        "\nAll of a sudden, you get a glimpse of something laying on the floor. It's a piece of paper."
        "\nYou take a closer look. It's actually a " + Text::blue + "note. " + Text::normal;
    
    r = prompt(p, command_list, true);
    Command::run(r, p, player);
}