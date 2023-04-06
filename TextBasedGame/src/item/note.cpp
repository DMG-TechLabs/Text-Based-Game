#include "item.h"
#include "../utils/game_utils.h"

void Note::saveNote(string note_name){
    saveToFile(note_name, this->getDescription());
}