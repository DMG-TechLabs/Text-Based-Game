#include "items.h"
#include "../day/day.h"

void Bed::sleep(){
    println(epilogue, 4);
    println("\nSleeping...", 0);

    Engine::println("\n\n\nPress any key to continue to the next day...", 0);
    cin.get();
}