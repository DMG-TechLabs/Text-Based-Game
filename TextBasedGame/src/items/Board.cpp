#include "items.h"

#include "../../Text-Based-Game-Engine/Engine/src/engine.h"

void Board::inspect(){
    for (int i = 0; i < board.size(); i++){
        println(Text::blue + board.at(i)->getItemId() + Text::normal + "\n" + board.at(i)->contents + "\n", 0);
    }
}

void Board::inspect(Player *player){
    println(player->currentNode->description);
}