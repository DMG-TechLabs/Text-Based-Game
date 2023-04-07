#include <iostream>
#include <string>
#include <unistd.h> // for sleep()

#include "achievements/achievement.h"
#include "utils/prompt.h"
#include "player/inventory.h"
#include "map/node.h"
#include "progress/progress.h"
#include "item/item.h"

using namespace std;

void testTerminal(){
    Terminal *t = new Terminal('$', "Room terminal", new string[2]{"move", "inspect"});

    string *ret = t->terminalPrompt("Type command");

    if(ret == NULL) return;

    cout << "Command: " << *ret << "\nArgument: " << *(ret+1) << endl << endl;
}

void testSave(){
    Inventory *i = new Inventory();
    int day = 3;
    Node *n = new Node();
    AchievementCollection *ac = new AchievementCollection();

    new Save(i, day, ac, n);
}

void prototype(){
    string* args = prompt(
        '>',
        "You wake up tired in a room. There is a desk with an open terminal and a note next to it.",
        new string[5]{"enter", "inspect", "help", "exit", "read"}
    );

    if(args == NULL) return;

    Item **room_items = new Item*[2]{
        new Note("domain.xyz\n\njfd73he/;fdshj12"),
        new Terminal('$', "Linux terminal", new string[2]{"ls", "cd"})
    };
    
    runCommand(args[0], args[1], room_items);
}

int main(int argc, char *argv[]){
    print("\n\n");
/*
    std::cout << '-' << std::flush;
    for (;;) {
        sleep(1);
        std::cout << "\b\\" << std::flush;
        sleep(1);
        std::cout << "\b|" << std::flush;
        sleep(1);
        std::cout << "\b/" << std::flush;
        sleep(1);
        std::cout << "\b-" << std::flush;
    }
*/
    for (;;) {

        std::cout << "\b\b\b\b\b\b\b\b\b\bLoading   " << std::flush;
        sleep(1);
        std::cout << "\b\b\b\b\b\b\b\b\b\bLOading   " << std::flush;
        sleep(1);
        std::cout << "\b\b\b\b\b\b\b\b\b\bLoAding   " << std::flush;
        sleep(1);
        std::cout << "\b\b\b\b\b\b\b\b\b\bLoaDing   " << std::flush;
        sleep(1);
        std::cout << "\b\b\b\b\b\b\b\b\b\bLoadIng   " << std::flush;
        sleep(1);
        std::cout << "\b\b\b\b\b\b\b\b\b\bLoadiNg   " << std::flush;
        sleep(1);
        std::cout << "\b\b\b\b\b\b\b\b\b\bLoadinG   " << std::flush;
        sleep(1);
        std::cout << "\b\b\b\b\b\b\b\b\b\bLoading.  " << std::flush;
        sleep(1);
        std::cout << "\b\b\b\b\b\b\b\b\b\bLoading.." << std::flush;
        sleep(1);
        std::cout << "\b\b\b\b\b\b\b\b\b\bLoading..." << std::flush;
        sleep(1);
    }

}
