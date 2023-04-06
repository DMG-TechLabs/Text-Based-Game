#include <string>
#include "./item.h"
#include "../utils/prompt.h"

using namespace std;

string* Terminal::getCommand(string message){
    return prompt(prompt_char, message, internal_commands);
}