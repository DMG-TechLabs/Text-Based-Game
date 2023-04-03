#include <iostream>
#include <string>
#include "prompt.h"

using namespace std;

int main(int argc, char *argv[]){
    string commands[] = {"move", "inspect"};

    string* ret = prompt('$', "Enter command", commands);

    if(ret != NULL){
        cout << "Command: " << *ret << "\nArgument: " << *(ret+1) << endl;
        cout << endl << endl;
    }
    

    return 0;
}