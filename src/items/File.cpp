#include "items.h"

#include "engine.h"

void File::save(){
    println("Saving to vault...");
    Engine::saveToFile("../vault/" + title + ".txt", contents);
    println("Saved.");
}

void File::readContents(){
    println("File content: ", 0);
    println(contents, 0);
}
