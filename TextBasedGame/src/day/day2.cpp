#include "day.h"
#include "../command/command.h"
#include "../interactions/interactions.h"
#include "../mastermind/game/game.h"

#include "../../Text-Based-Game-Engine/Engine/src/engine.h"

#include <string>

using namespace std;
using namespace Engine;

void cutscene_two(Prompt p, Response r, Player *player);

void Day::dayTwo(Player *player, Map *map){
    Prompt p;
    p.prompt_char = '>';
    Response r;

    vector<Objective *> objectives = {
        new Objective("1. Enter terminal"),
        new Objective("2. Hack the terminal"),
        new Objective("3. Unlock safe")
    };
    Mission m{"Tutorial", "The tutorial", objectives};
    Objective::printObjectives(objectives);

    player->setMission(&m);

    p.accepted_commands = {"read", "collect", "open", "help", "inventory", "enter", "sleep", "inspect", "unlock", "search", "objectives"};
    p.message = player->currentNode->description;
    r = prompt(p, command_list);
    Command::run(r, p, player);

    Objective::completeObjective((r.command == "enter" && r.args.at(0) == "terminal"), objectives, 0);
    //Objective::completeObjective((), objectives, 1);
    Objective::completeObjective((r.command == "unlock" && r.args.at(0) == "safe"), objectives, 2);

    int current_node = player->currentNode->id;
    do{
        r = prompt(p, command_list, false);
        Command::run(r, p, player);

        Objective::completeObjective((r.command == "enter" && r.args.at(0) == "terminal"), objectives, 0);
        //Objective::completeObjective((), objectives, 1);
        Objective::completeObjective((r.command == "unlock" && r.args.at(0) == "safe"), objectives, 2);
    } while(current_node == player->currentNode->id && !player->currentNode->isAccessible());

    //Mastermind::start("abcd", "abcdef");
}

void cutscene_two(Prompt p, Response r, Player *player){

}

