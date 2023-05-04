

#include "items.h"
#include "../../Text-Based-Game-Engine/Engine/src/item/item.h"
#include "../../Text-Based-Game-Engine/Engine/src/utils/game_utils.h"

void Note::saveNote(string note_name){
    saveToFile(note_name, this->getDescription());
}