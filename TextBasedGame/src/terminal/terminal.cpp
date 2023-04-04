#include <string>
#include "./terminal.h"
#include "./prompt.h"

using namespace std;

string* Terminal::getCommand(string message){
    return prompt(prompt_char, message, commands);
}
