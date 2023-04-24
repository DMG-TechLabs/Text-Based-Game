#include <unistd.h>  // for sleep()

#include <iostream>
#include <string>

#include "engine.h"

using namespace std;

void testSave() {
    Inventory *i = new Inventory();
    int day = 3;
    Node *n = new Node();
    AchievementCollection *ac = new AchievementCollection();

    new Save(i, day, ac, n);
}

int main(int argc, char *argv[]) {
    print("hello");

    return 0;
}
