#include "include/game_utils.h"
#include "items.h"

#include "engine.h"

#include <string>
#include <iostream>

namespace StringUtils{
string removeSubstring(string originalString, string substringToRemove) {
    size_t startPos = originalString.find(substringToRemove);
    while (startPos != std::string::npos) {
        originalString.erase(startPos, substringToRemove.length());
        startPos = originalString.find(substringToRemove, startPos);
    }

	return originalString;
}
};

void File::save(){
    println("Saving to vault...");
	string path = StringUtils::removeSubstring(Engine::getProjectPath(), "build") + "/vault/" + title + ".txt";
    Engine::saveToFile(path, contents);
    println("Saved.");
}

void File::readContents(){
    println("File content: ", 0);
    println(contents, 0);
}
