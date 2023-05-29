

#include "items.h"
#include "../command/command.h"
#include "../../Text-Based-Game-Engine/Engine/src/item/item.h"
#include "../../Text-Based-Game-Engine/Engine/src/utils/game_utils.h"

void Note::saveNote(string note_name){
    saveToFile(note_name, this->getDescription());
}

void Note::collect(Player *player){
    player->collectItem(this);
    player->currentNode->items.erase(player->currentNode->items.begin() + matchItemByName(this->getName(), player->currentNode->items)); // Delete item from node vector

    println("Note added to inventory", 0);
}

void Note::collect(Player *player, BundleItem *bundle){
    player->collectItem(this);
    bundle->bundle_items.erase(bundle->bundle_items.begin() + matchItemByName(this->getName(), bundle->bundle_items)); // Delete item from bundle

    println("Note added to inventory", 0);
}

void Note::readContents(){
    println(Text::bold + "The following is written on the note:" + Text::normal, 0);
    println(this->contents);
}