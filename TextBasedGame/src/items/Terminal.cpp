#include <string>
#include "../../Text-Based-Game-Engine/Engine/src/item/item.h"
#include "../../Text-Based-Game-Engine/Engine/src/utils/prompt.h"

#include "./items.h"

using namespace std;

string* Terminal::terminalPrompt(string message){
    return prompt(prompt_char, message, internal_commands);
}
