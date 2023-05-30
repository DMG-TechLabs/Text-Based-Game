#include "game.h"

#include <vector>

#include "../../../Text-Based-Game-Engine/Engine/src/engine.h"
#include "../ui/controls.h"
#include "checks.h"

using namespace Engine;

static const string EQUALS_PRESSED = "fn8r3u2isjicd392cunhefu93rneuwheduj3n92r8rnyejwheu";

void printCharacter(int selectedItem, int index, int color, char character);
string makeWord(int *indexes, string characters, int length);
void clearRow(int num);

string render(string word, string characters) {
    int color = 1;
    int numOfCharacters = word.length();
    int selected = 0;
    int *indexes = new int[numOfCharacters];

    Mastermind::disableInputBuffering();

    // start every character from 'a'
    for (int i = 0; i < numOfCharacters; i++) {
        indexes[i] = 0;
    }

    while (true) {
        clearRow(numOfCharacters);
        for (int i = 0; i < numOfCharacters; i++) {
            printCharacter(selected, i, color, characters.at(indexes[i]));
            // cout << characters.at(*indexes.at(i)) << " ";
        }

        // Handle user input
        int keyPressed = Mastermind::handleKeys();
        switch (keyPressed) {
            case LEFT:
                selected = (selected == 0) ? numOfCharacters - 1 : selected - 1;
                break;
            case RIGHT:
                selected = (selected == numOfCharacters - 1) ? 0 : selected + 1;
                break;
            case UP:
                indexes[selected] = (indexes[selected] == characters.size() - 1)
                                        ? 0
                                        : indexes[selected] + 1;
                break;
            case DOWN:
                indexes[selected] = (indexes[selected] == 0)
                                        ? characters.size() - 1
                                        : indexes[selected] - 1;
                break;
            case EQUALS:
                println("\n\nCrack failed...", 0);
                println("Terminating...", 2);
                return EQUALS_PRESSED;
            case ENTER:
                Mastermind::enableInputBuffering();
                return makeWord(indexes, characters, numOfCharacters);
        }
    }

    return "Error";
}

bool Mastermind::start(string key, string characters) {
    Text::clearScreen();

    println("Press \'=\' to quit");

    std::string user_try = "";

    while(user_try != key){
        user_try = render(key, characters);

        if (user_try == EQUALS_PRESSED) return false;

        vector<int> correct = checks(key, user_try);

        cout << endl << correct.at(0) << " correct but in the wrong position" << endl;
        cout << correct.at(1) << " correct and in the correct posstion" << endl << endl;
    }



    cout << Text::green + "\n\nPassword cracked!" + Text::normal << endl;
    return true;
}

void printCharacter(int selectedItem, int index, int color, char character) {
    std::cout << (selectedItem == index
                      ? Text::color("bg", color) + character + Text::normal
                      : Text::blue + character + Text::normal)
              << " ";
}

string makeWord(int *indexes, string characters, int length) {
    string word = "";

    for (int i = 0; i < length; i++) {
        word += characters.at(indexes[i]);
    }

    return word;
}

void clearRow(int num) {
    string s = "";

    for (int i = 0; i < num*2; i++) {
        s += "\b";
    }

    cout << s;
}