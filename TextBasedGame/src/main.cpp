#include <unistd.h>  // for sleep()

#include <iostream>
#include <string>

#include "engine.h"

using namespace std;

void testTerminal() {
    Terminal *t =
        new Terminal('$', "Room terminal", new string[2]{"move", "inspect"});

    string *ret = t->terminalPrompt("Type command");

    if (ret == NULL) return;

    cout << "Command: " << *ret << "\nArgument: " << *(ret + 1) << endl << endl;
}

void testSave() {
    Inventory *i = new Inventory();
    int day = 3;
    Node *n = new Node();
    AchievementCollection *ac = new AchievementCollection();

    new Save(i, day, ac, n);
}

void prototype() {
    string *args =
        prompt('>',
               "You wake up tired in a room. There is a desk with an open "
               "terminal and a note next to it.",
               new string[5]{"enter", "inspect", "help", "exit", "read"});

    if (args == NULL) return;

    Item **room_items = new Item *[2] {
        new Note("domain.xyz\n\njfd73he/;fdshj12"),
            new Terminal('$', "Linux terminal", new string[2]{"ls", "cd"})
    };

    runCommand(args[0], args[1], room_items);
}

int main(int argc, char *argv[]) {
    // Sound *s = new Sound("../sound_effects/bass.wav");
    // s->play();
    // s->terminate();

    Soloud *soloud = Soloud_create();
Speech *speech = Speech_create();

Speech_setText(speech, "Hello c-api");

Soloud_initEx(soloud, SOLOUD_CLIP_ROUNDOFF | SOLOUD_ENABLE_VISUALIZATION, 
              SOLOUD_AUTO, SOLOUD_AUTO, SOLOUD_AUTO, SOLOUD_AUTO);
Soloud_setGlobalVolume(soloud, 4);
Soloud_play(soloud, speech);

// ...

Soloud_deinit(soloud);
    
Speech_destroy(speech);
Soloud_destroy(soloud);

    return 0;
}
