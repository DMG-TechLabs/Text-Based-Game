#include "prompt.h"

using namespace std;

int main(int argc, char *argv[]){

    vector<string> acceptedCommands;

    acceptedCommands.push_back("run");
    acceptedCommands.push_back("pick");

    prompt('$', "What's your name?", acceptedCommands);

    return 0;
}