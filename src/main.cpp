#include <iostream>

#include "engine.h"
#include "command.h"
#include "include/game_utils.h"
#include "items.h"
#include "map.h"
#include "day.h"
#include "interactions.h"
#include "menu.h"

string removeSubstring(string originalString, string substringToRemove) {
    size_t startPos = originalString.find(substringToRemove);
    while (startPos != std::string::npos) {
        originalString.erase(startPos, substringToRemove.length());
        startPos = originalString.find(substringToRemove, startPos);
    }

	return originalString;
}

void deleteVaultFile(){
	string path = removeSubstring(Engine::getProjectPath(), "build")+ "/vault/OPERATION SENTINEL SHIELD.txt";
	
	cout << path << endl;
	Engine::deleteFile(path);		
}

int main() {
	Map map{new Node(0, "Hall", true)};
	Player player{};

	
	while (true){
		GameMenu::demoMenu();
		Day::dayOne(&player, &map);
		Day::dayTwo(&player, &map);
		GameMenu::credits();
		deleteVaultFile();
	}
	
	return 0;
}
