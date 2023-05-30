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

    Objective::completeObjective((r.command == "enter" && r.args.at(0) == "terminal"), objectives, 0);
    Objective::completeObjective((r.command == "unlock" && r.args.at(0) == "safe"), objectives, 1);

    int current_node = player->currentNode->id;
    do{
        r = prompt(p, command_list, false);
        Command::run(r, p, player);

        if(r.command == "open" && r.args.at(0) == "door"){
            break;
        }

        Objective::completeObjective((r.command == "enter" && r.args.at(0) == "terminal"), objectives, 0);
        Objective::completeObjective((r.command == "unlock" && r.args.at(0) == "safe"), objectives, 1);
    } while(current_node == player->currentNode->id);
    

    final_cutscene();

}

void cutscene_two(Prompt p, Response r, Player *player){
    Text::clearScreen();
}

void final_cutscene(){
    Text::clearScreen();
    println("I GOT OUT");
}