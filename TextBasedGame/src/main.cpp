#include <iostream>
#include <string>
#include "prompt.h"

using namespace std;

int main(int argc, char *argv[]){
    string commands[] = {"run", "pick"};

    prompt('$', "What's your name?", commands);

    
    

    return 0;
}