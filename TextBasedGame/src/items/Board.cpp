#include "items.h"

#include "../../Text-Based-Game-Engine/Engine/src/engine.h"

void Board::inspect(){
    for (int i = 0; i < board.size(); i++){
        println(board.at(i)->getItemId() + "\n", 0);
    }
}