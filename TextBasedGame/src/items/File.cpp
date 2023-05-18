#include "items.h"

#include "../../Text-Based-Game-Engine/Engine/src/engine.h"

void File::save(){
    Engine::saveToFile(title, contents);
}

void File::readContents(){
    println("File content: ", 0);
    println(contents, 0);
}