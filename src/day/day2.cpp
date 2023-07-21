#include "day.h"
#include "command.h"
#include "interactions.h"
#include "../../Mastermind-Minigame/include/game.h"

#include "engine.h"

#include <string>

using namespace std;
using namespace Engine;
using namespace CliKit;

void cutscene_two(Prompt p, Response r, Player *player);
void final_cutscene();

void Day::dayTwo(Player *player, Map *map){
    map->getNode(6)->setDescription(
        "You woke up. You look around you. Nothing has changed since yesterday...The " + Text::blue + "terminal" + Text::normal + " is\n"
        "still on the corner of the room on top of the table. There is the chair too.\n"
        "You decide to take a closer look. The chair looks rusty and the table looks old\n"
        "and dusty. It feels like everything is going to collapse anytime soon. \n"
        "In the right corner of the room, there is the "  + Text::blue + "safe" + Text::normal + ". It has some rough spots where\n"
        "the colour has \"faded\" to cooperish red. It's locked.\n"
        "Above that, you notice the "  + Text::blue + "board" + Text::normal + ". It has a few pins laying around\n"
        "with some old notes attached. All in all, nothing special.\n" 
        "You sit up on the edge of the "  + Text::blue + "bed" + Text::normal + ". It makes a \"screeching\" sound.\n"
    );

    Prompt p;
    p.prompt_char = '>';
    Response r;

    cutscene_two(p, r, player);
    /*

    vector<Objective *> objectives = {
        new Objective("1. Enter terminal"),
        new Objective("2. Unlock safe")
    };
    Mission m{"Tutorial", "The tutorial", objectives};
    Objective::printObjectives(objectives);

    player->setMission(&m);
    player->setCurrentNode(map->getNode(6));

    p.accepted_commands = {"read", "collect", "open", "help", "inventory", "enter", "sleep", "inspect", "unlock", "search", "objectives"};
    p.message = player->currentNode->description;
    r = prompt(p, command_list);
    Command::run(r, p, player);

    Objective::completeObjective((!r.args.empty() && r.command == "enter" && r.args.at(0) == "terminal"), objectives, 0);
    Objective::completeObjective((!r.args.empty() && r.command == "unlock" && r.args.at(0) == "safe"), objectives, 1);

    bool executed;
    int current_node = player->currentNode->id;
    do{
        r = prompt(p, command_list, false);
        executed = Command::run(r, p, player);

        Objective::completeObjective((!r.args.empty() && r.command == "enter" && r.args.at(0) == "terminal"), objectives, 0);
        Objective::completeObjective((!r.args.empty() && r.command == "unlock" && r.args.at(0) == "safe"), objectives, 1);
    } while(!(r.command == "open" && (r.args.at(0) == "door" || r.args.at(0) == "noor") && executed) );
    */
    

    final_cutscene();

}

void cutscene_two(Prompt p, Response r, Player *player){
    Text::clearScreen();

    println("You wake up once again...");

    FormattedPrint::playerTalking("That was not a good sleep. I already hate this bed");

    FormattedPrint::playerTalking("I need to get out of here");

    println("", 3);

    Text::clearScreen();
}

void final_cutscene(){
    Text::clearScreen();
    println("You hear a \"click\" coming from the door and you try to open it.");

    println("");

    println("It works!");
    
    println("");

    println("You cant't believe that you finally managed to eescape this nonesense. Until you look around you...You are still stuck in this place.", 4);
    
    println("");

    println("The hallway is long. You can't see clearly but you think there are more rooms like yours as you spot 2 more doors. There are no windows so the lighting is limited. ");

    println("");
    
    println("You stand there for a second trying to absorb everything you see.");

    println("");
    
    println("The sillence is really loud. You can almost hear the blood running through your veins.");

    println("");

    println("Looking around you realize...");
    
    println("");

    FormattedPrint::playerTalking("Wait.. Are these rooms excactly the same as mine?");
    println("");

    println("Your heart is pounding faster than ever");
    println("");

    FormattedPrint::playerTalking("I have to escape this hellhole...");

    println("", 4);
}
