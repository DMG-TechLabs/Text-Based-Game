#include "items.h"

#include "../../Text-Based-Game-Engine/Engine/src/engine.h"

bool isNumber(string s);

void Safe::inspect(){
    println("An old locked safe", 0);
}

void Safe::inspect(Player *player){
    if(this->isLocked){
        inspect();
        return;
    }

    for (int i = 0; i < safeItems.size(); i++){
        player->currentNode->addItem(safeItems.at(i));
        println(Text::blue + safeItems.at(i)->getItemId() + Text::normal + "\n", 0);
    }
}

void Safe::unlock(){
    this->isLocked = false;
}

bool Safe::enterPasscode(){
    string passcode;
    if(!this->isLocked) {
        println("Safe is already unlocked", 0);
        return true;
    }
    
    print("Enter passcode: ");
    getline(cin, passcode);


    if(!isNumber(passcode)){
        println("Invalid passcode", 0);
        return false;
    }

    if(stoi(passcode) != this->passcode) {
        println("Wrong passcode");
        return false;
    } else {
        this->unlock();
        println("Safe unlocked", 0);
        return true;
    }
}

bool isNumber(string s){
    return !s.empty() && std::find_if(s.begin(), 
        s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
}