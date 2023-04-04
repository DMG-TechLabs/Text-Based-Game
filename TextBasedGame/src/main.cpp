#include <iostream>
#include <string>
#include "achievements/achievement.h"
#include "terminal/terminal.h"
#include "player/inventory.h"
#include "map/node.h"
#include "progress/progress.h"

using namespace std;

void testTerminal(){
    string commands[] = {"move", "inspect"};
    Terminal *t = new Terminal('$', commands);

    
    string* ret = t->getCommand("Type command");

    if(ret != NULL){
        cout << "Command: " << *ret << "\nArgument: " << *(ret+1) << endl;
        cout << endl << endl;
    }
}

int main(int argc, char *argv[]){
    AchievementCollection *a = new AchievementCollection();
    int day = 2;
    Inventory *i = new Inventory();
    Node *n = new Node();
    n->number = 3;

    Save *s = new Save(i, day, a, n);
    
    cout << endl;
    return 0;
}