#include <iostream>
#include <string>
#include "achievements/achievement.h"
#include "terminal/terminal.h"

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


    a->importAchievements("1,1");

    a->printAchievements();

    cout << endl;
    return 0;
}