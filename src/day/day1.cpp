#include "day.h"
#include "command.h"
#include "include/command.h"
#include "interactions.h"

#include "engine.h"
#include "items.h"
#include <algorithm>
#include <unistd.h>

using namespace CliKit;

using namespace std;
using namespace Engine;

void getAvailableCommands(Prompt p);
bool contains(vector<Item *> arr, string item);
bool contains(vector<string> arr, string item);

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
    int counter = 1;
    bool flag;
	bool skip_run = true;

    player->setInventory(Inventory{});
    player->currentNode = map->getNode(6); // We are in room 6
    player->setName(getPlayerName());

    Text::clearScreen();

    cutscene_one(p, r, player);

    Text::clearScreen();


    FormattedPrint::playerTalking("Anyways... I should search the room");

    vector<Objective *> objectives = {
        new Objective("Ask for help"),
        new Objective("Inspect the note besides the terminal"),
        new Objective("Read the note"),
        new Objective("Collect the note"),
        new Objective("Open your inventory")
    };

	// Setting objective dependencies
	objectives.at(3)->parent = objectives.at(2);
	objectives.at(2)->parent = objectives.at(1);

    Mission m{"Tutorial", "The tutorial", objectives};
    Objective::printObjectives(objectives);

    player->setMission(&m);

    p.accepted_commands = {"read", "collect", "open", "help", "inventory", "inspect", "unlock", "search", "objectives"};
    p.message = player->currentNode->description;
    r = prompt(p, command_list);
	
	// If one of them is false means that a objective was completed before its parent so skip run
	skip_run = !(
			Objective::completeObjective((r.command == "help"), objectives, 0) && 
			Objective::completeObjective((!r.args.empty() && r.command == "inspect" && r.args.at(0) == "note"), objectives, 1) &&
			Objective::completeObjective((!r.args.empty() && r.command == "read" && r.args.at(0) == "note"), objectives, 2) &&
			Objective::completeObjective((!r.args.empty() && r.command == "collect" && r.args.at(0) == "note"), objectives, 3) &&
			Objective::completeObjective((r.command == "inventory"), objectives, 4)
		);

	if (!skip_run)
		flag = Command::run(r, p, player);

    int current_node = player->currentNode->id;
	bool sleep_message_printed_once = false; // To not print the sleep message every time after completing the objectives
    do{
        r = prompt(p, command_list, false);

		// If one of them is false means that a objective was completed before its parent so skip run
		skip_run = !(
			Objective::completeObjective((r.command == "help"), objectives, 0) && 
			Objective::completeObjective((!r.args.empty() && r.command == "inspect" && r.args.at(0) == "note"), objectives, 1) &&
			Objective::completeObjective((!r.args.empty() && r.command == "read" && r.args.at(0) == "note"), objectives, 2) &&
			Objective::completeObjective((!r.args.empty() && r.command == "collect" && r.args.at(0) == "note"), objectives, 3) &&
			Objective::completeObjective((r.command == "inventory"), objectives, 4)
		);

		if (!skip_run)
			flag = Command::run(r, p, player);

		if(flag && r.command == "sleep" && sleep_message_printed_once) return; // if `sleep` continue to the next day
		
		if(player->getMission()->isCompleted() && !sleep_message_printed_once){
			sleep_message_printed_once = true;
			println("");
			FormattedPrint::playerTalking("I think that was it... I might as well have a nap now");
			p.accepted_commands.push_back("sleep"); // now allow the player to sleep
		}
               
    } while(current_node == player->currentNode->id);
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

    FormattedPrint::typingInTerminal("terminal", "We'll talk soon...");

    println("\nExiting...\n");
}

void getAvailableCommands(Prompt p) {
    println("-" + Text::b_green + "Available commands" + Text::normal + "-", 0);
    for (int i = 0; i < p.accepted_commands.size(); i++) {
        cout << Text::red << i + 1 << ". " << Text::normal << p.accepted_commands.at(i)
             << endl;
    }
}

bool contains(vector<Item *> arr, string item) {
    bool exists = false;
    for (int i = 0; i < arr.size(); i++) {
        if (item == arr.at(i)->getName()) {
            exists = true;
            break;
        }
    }

    return exists;
}

bool contains(vector<string> arr, string item) {
    bool exists = false;
    for (int i = 0; i < arr.size(); i++) {
        if (item == arr.at(i)) {
            exists = true;
            break;
        }
    }

    return exists;
}
