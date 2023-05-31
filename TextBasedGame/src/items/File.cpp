#include "items.h"

#include "../../Text-Based-Game-Engine/Engine/src/engine.h"

void File::save(){
    println("Saving to vault...");
    Engine::saveToFile("../vault/" + title + ".txt", contents);
    println("Saved.");
}

void File::readContents(){
    println("File content: ", 0);
    println(contents, 0);
}