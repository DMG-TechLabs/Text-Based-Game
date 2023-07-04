#include "day.h"
#include "../command/command.h"
#include "../interactions/interactions.h"
#include "../mastermind/game/game.h"

#include "../../Text-Based-Game-Engine/Engine/src/engine.h"

#include <string>

using namespace std;
using namespace Engine;

void cutscene_two(Prompt p, Response r, Player *player);
void final_cutscene();

void Day::dayTwo(Player *player, Map *map){
    map->getNode(6)->setDescription(
        "You woke up. You look around you. Nothing has changed since yesterday...The " + Text::blue + "terminal" + Text::normal + " is"
        "still on the corner of the room on top of the table. There is the chair too."
        "You decide to take a closer look. The chair looks rusty and the table looks old"
        "and dusty. It feels like everything is going to collapse anytime soon. "
        "In the right corner of the room, there is the "  + Text::blue + "safe" + Text::normal + ". It has some rough spots where"
        "the colour has \"faded\" to cooperish red. It's locked."
        "Above that, you notice the "  + Text::blue + "terminal" + Text::normal + ". It has a few pins laying around"
        "with some old notes attached. All in all, nothing special." 
        "You sit up on the edge of the "  + Text::blue + "terminal" + Text::normal + ". It makes a \"screeching\" sound."
    );

    Prompt p;
    p.prompt_char = '>';
    Response r;

    cutscene_two(p, r, player);

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
    

    final_cutscene();

}

void cutscene_two(Prompt p, Response r, Player *player){
    Text::clearScreen();
}

void final_cutscene(){
    Text::clearScreen();
    println("I GOT OUT");
}