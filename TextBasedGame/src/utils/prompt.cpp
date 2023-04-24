#include "prompt.h"

#include <iostream>
#include <string>

#include "../command/command.h"
#include "../item/item.h"

/* ============={Utils}============= */

bool contains(string *arr, string str) {
    int size = 0;
    while (!arr[size].empty()) ++size;

    bool exists = false;
    for (int i = 0; i < size; i++) {
        if (str == arr[i]) {
            exists = true;
            break;
        }
    }

    return exists;
}

int itemsLength(Item **items) {
    int length_counter = 0;
    while (items[length_counter]) length_counter++;

    return length_counter;
}

/* ============={End of Utils}============= */

string *prompt(char prompt_char, string *accepted_commands) {
    return prompt(prompt_char, "", accepted_commands);
}

string *prompt(char prompt_char, string message, string *accepted_commands) {
    string input, command;
    string *ret = new string[5]{"", "", "", "", ""};

    if (message != "") print(message);
    cout << prompt_char << " ";

    getline(cin, input);

    int counter = 0, from = 0;
    for (int i = 0; i <= input.length(); i++) {
        if (input[i] == ' ' || input[i] == '\0') {
            ret[counter++] = input.substr(from, i - from);
            from = i + 1;
        }
    }

    command = ret[0];

    // Check if command is accepted
    bool is_acceptable = contains(accepted_commands, command);
    if (!is_acceptable) {
        print("You can't do that here");
        return NULL;
    }

    cout << endl << endl;

    return ret;
}

void print(string message) { cout << message << endl << endl; }
void print(int message) { cout << message << endl << endl; }
void print(char message) { cout << message << endl; }

