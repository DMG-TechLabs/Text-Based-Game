#include "items.h"
#include "../day/day.h"

void Bed::sleep(Day d){
    if(!d.isCompleted()) return;

    d.completed = true;
}