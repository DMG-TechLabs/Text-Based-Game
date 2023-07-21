#include "items.h"
#include "day.h"

void Bed::sleep(){
    println(epilogue, 4);
    println("\nSleeping...", 0);

    Engine::println("\n\n\nPress enter to continue to the next day...", 0);
    cin.get();
}
