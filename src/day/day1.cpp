#include "day.h"
#include "command.h"
#include "interactions.h"

#include "engine.h"
#include "items.h"

using namespace CliKit;

using namespace std;
using namespace Engine;

void getAvailableCommands(Prompt p);
bool contains(vector<Item *> arr, string item);
bool contains(vector<string> arr, string item);

void cutscene_one(Prompt p, Response r, Player *player);
bool run(Response response, Prompt p, Player *player, int counter);

bool run(Response response, Prompt p, Player *player, int counter){
    int item_index;
    Item *item_ptr;
    
    ReadableItem *ri;
    CollectableItem *ci;
    OpenableItem *oi;
    EnterableItem *ei;
    SaveableItem *si;
    UnlockableItem *ui;
    SearchableItem *sei;
    BundleItem *bi;

    if(sizeof(response) == 0){
        run(prompt(p, command_list), p, player, counter);
        delete item_ptr;
        return false;
    }

    switch (response.args.size()) {
        case 0:
            if(response.command == "enter") return false;
            if(counter == 1){
                if(response.command == "objectives"){
                    Objective::printObjectives(player->getMission()->objectives);
                    return false;
                }
                if(response.command != "help"){
                    println("Complete your first objective");
                    return false;
                }
                getAvailableCommands(p);
                return true; 
            }
            if(counter == 2 || counter == 3 || counter == 4){
                if(response.command == "help" || response.command == "inventory" || response.command == "sleep"){
                    println("Complete your current objective");
                    return false; 
                }
                if(response.command == "objectives"){
                    Objective::printObjectives(player->getMission()->objectives);
                    return false;
                }
                return false;
            }

            if(counter == 5){
                if (response.command != "inventory"){
                    println("Complete your fifth objective");
                    return false;
                }
                player->getInventory().printInventory();
                return true;
            }

            if(response.command == "objectives"){
                Objective::printObjectives(player->getMission()->objectives);
                return false;
            }
            
            if (response.command == "sleep" && contains(player->currentNode->items, "bed")){
                if(!player->getMission()->isCompleted()){
                    println("Complete your objectives first", 0);
                    return false;
                }

                dynamic_cast<Bed *>(player->currentNode->items.at(matchItemByName("bed", player->currentNode->items)))->sleep();
                return true;
            } 
            return false;            
        case 1:
            item_index = matchItemByName(response.args.at(0), player->currentNode->items);

            item_ptr = player->currentNode->items.at(item_index);

            // Check if the command matches one of items interfaces
            // If the casting gives NULL it means that the object doesn't implement
            // the interface
            ri = dynamic_cast<ReadableItem *>(item_ptr);
            ci = dynamic_cast<CollectableItem *>(item_ptr);
            oi = dynamic_cast<OpenableItem *>(item_ptr);
            ei = dynamic_cast<EnterableItem *>(item_ptr);
            si = dynamic_cast<SaveableItem *>(item_ptr);
            ui = dynamic_cast<UnlockableItem *>(item_ptr);
            sei = dynamic_cast<SearchableItem *>(item_ptr);
            bi = dynamic_cast<BundleItem *>(item_ptr);

            if(counter == 1) {
                println("Complete your first objective");
                return false;
            }

            if(counter == 2){
                if(response.command != "inspect" || response.args.at(0) != "note"){
                    println("Complete your current objective");
                    return false;
                }    
                println(item_ptr->getDescription());
                return true;
            }

            if(counter == 3){
                if(response.command != "read" && ri != NULL){
                    println("Complete your current objective");
                    return false;
                }    
                ri->readContents();
                return true;   
            }

            if(counter == 4){
                if(response.command != "collect" && ci != NULL){
                    println("Complete your current objective");
                    return false;
                }    
                ci->collect(player);
                return true;
            }

            if(counter == 5){
                println("Complete your last objective");
            }          
            
            println("The command doesn't match the item", 0);
            return false;
            
            break;
        default:
            println("This number of arguments is not yet implemnted", 0);
            break;
    }

    return false;
}

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

    player->setInventory(Inventory{});
    player->currentNode = map->getNode(6); // We are in room 6
    player->setName(getPlayerName());

    Text::clearScreen();

    cutscene_one(p, r, player);

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

    p.accepted_commands = {"read", "collect", "open", "help", "inventory", "sleep", "inspect", "unlock", "search", "objectives"};
    p.message = player->currentNode->description;
    r = prompt(p, command_list);
    flag = run(r, p, player, counter);

    if(flag){
        counter++;
        Objective::completeObjective((r.command == "help"), objectives, 0);
    }

    int current_node = player->currentNode->id;
    do{
        r = prompt(p, command_list, false);

        flag = run(r, p, player, counter);
        if(flag){
            counter++;
            if(r.command == "sleep" && player->getMission()->isCompleted()) break;

            Objective::completeObjective((r.command == "help"), objectives, 0);
            Objective::completeObjective((!r.args.empty() && r.command == "inspect" && r.args.at(0) == "note"), objectives, 1);
            Objective::completeObjective((!r.args.empty() && r.command == "read" && r.args.at(0) == "note"), objectives, 2);
            Objective::completeObjective((!r.args.empty() && r.command == "collect" && r.args.at(0) == "note"), objectives, 3);
            Objective::completeObjective((r.command == "inventory"), objectives, 4);

            if(player->getMission()->isCompleted()){
                println("", 5);
                FormattedPrint::playerTalking("I think that was it... I might as well have a nap now");
            }
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

    FormattedPrint::typingInTerminal("terminal", "1. Ask for help");

    FormattedPrint::typingInTerminal("terminal", "2. Inspect the note besides the terminal");

    FormattedPrint::typingInTerminal("terminal", "3. Read the note");

    FormattedPrint::typingInTerminal("terminal", "4. Collect the note");

    FormattedPrint::typingInTerminal("terminal", "5. Open your inventory");

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
