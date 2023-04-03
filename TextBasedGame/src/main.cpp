#include <iostream>
#include <string>
#include "terminal/terminal.h"

using namespace std;

int main(int argc, char *argv[]){



    
    


    string commands[] = {"move", "inspect"};
    Terminal *t = new Terminal('$', commands);

    
    string* ret = t->getCommand("Type command");

    if(ret != NULL){
        cout << "Command: " << *ret << "\nArgument: " << *(ret+1) << endl;
        cout << endl << endl;
    }

    return 0;
}