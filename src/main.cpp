#include <iostream>

#include "engine.h"
#include "command.h"
#include "include/game_utils.h"
#include "items.h"
#include "map.h"
#include "day.h"
#include "interactions.h"
#include "menu.h"

void deleteVaultFile(){
	if(Engine::getExecutablePath().find("build")){
		Engine::deleteFile(Engine::getProjectPath().replace(Engine::getProjectPath().find("build"), 5, "") + "vault/OPERATION SENTINEL SHIELD.txt");		
	} else {
		Engine::deleteFile(Engine::getProjectPath() + "vault/OPERATION SENTINEL SHIELD.txt");		

	}	
}

int main() {
	Map map{new Node(0, "Hall", true)};
	Player player{};

	cout << Engine::getExecutablePath() << endl;
	cout << Engine::getProjectPath() << endl;

	cin.get();
		
	while (true){
		GameMenu::demoMenu();
		Day::dayOne(&player, &map);
		Day::dayTwo(&player, &map);
		GameMenu::credits();
		deleteVaultFile();
	}
	
	return 0;
}
