#include "day.h"
#include "../command/command.h"
#include "../interactions/interactions.h"

#include "../../Text-Based-Game-Engine/Engine/src/engine.h"

using namespace std;
using namespace Engine;

void cutscene_one(Prompt p, Response r, Player *player);

string getPlayerName(){
    string player_name;
    println("What's your name?", 0);
    print("Type your name: ");
    getline(cin, player_name);

    return player_name;
}

void Day::dayOne(Player *player, Map *map){
    Prompt p;
    p.prompt_char = '>';
    Response r;

    player->setInventory(Inventory{});
    player->currentNode = map->getNode(6); // We are in room 6
    player->setName(getPlayerName());

    Text::clearScreen();

    //cutscene_one(p, r, player);

    Text::clearScreen();

    FormattedPrint::playerTalking("Anyways... Let's search the room");


    vector<Objective *> objectives = {
        new Objective("1. Ask for help"),
        new Objective("2. Inspect the note besides the terminal"),
        new Objective("3. Read the note"),
        new Objective("4. Collect the note"),
        new Objective("5. Open your inventory")
    };
    Mission m{"Tutorial", "The tutorial", objectives};
    Objective::printObjectives(objectives);

    player->setMission(&m);


    p.accepted_commands = {"read", "collect", "open", "help", "inventory", "enter", "sleep", "inspect", "unlock", "search", "objectives"};
    p.message = player->currentNode->description;
    r = prompt(p, command_list);
    Command::run(r, p, player);

    Objective::completeObjective((r.command == "help"), objectives, 0);
    Objective::completeObjective((r.command == "inspect" && r.args.at(0) == "note"), objectives, 1);
    Objective::completeObjective((r.command == "read" && r.args.at(0) == "note"), objectives, 2);
    Objective::completeObjective((r.command == "collect" && r.args.at(0) == "note"), objectives, 3);
    Objective::completeObjective((r.command == "inventory"), objectives, 4);

    int current_node = player->currentNode->id;
    do{
        r = prompt(p, command_list, false);
        Command::run(r, p, player);



        Objective::completeObjective((r.command == "help"), objectives, 0);
        Objective::completeObjective((r.command == "inspect" && r.args.at(0) == "note"), objectives, 1);
        Objective::completeObjective((r.command == "read" && r.args.at(0) == "note"), objectives, 2);
        Objective::completeObjective((r.command == "collect" && r.args.at(0) == "note"), objectives, 3);
        Objective::completeObjective((r.command == "inventory"), objectives, 4);
    } while(current_node == player->currentNode->id && r.command != "sleep");
}


void cutscene_one(Prompt p, Response r, Player *player){
    println("You wake up tired in a room you've never seen before.");
    println("You panic!");
    println("You run to the door hoping you'll get out");

    p.accepted_commands = {"open", "help"};
    p.message = "Open the " + Text::blue + "door" + Text::normal;
    
    do{
        r = prompt(p, command_list, true);
        Command::run(r, p, player);
    } while((r.command != "open" || r.args.at(0) != "door") && (r.command != "open" || r.args.at(0) != "noor"));


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
    
    FormattedPrint::typingInTerminal("terminal", "If you want to talk again, complete these tasks for me");

    FormattedPrint::typingInTerminal("terminal", "1. Ask for help");

    FormattedPrint::typingInTerminal("terminal", "2. Inspect the note besides the terminal");

    FormattedPrint::typingInTerminal("terminal", "3. Read the note");

    FormattedPrint::typingInTerminal("terminal", "4. Collect the note");

    FormattedPrint::typingInTerminal("terminal", "5. Open your inventory");

    FormattedPrint::typingInTerminal("terminal", "We'll talk soon...");

    println("Exiting...\n");
}