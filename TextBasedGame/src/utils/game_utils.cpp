#include "game_utils.h"

void saveToFile(string file_name, string text_data){
    ofstream file;
    file.open (file_name);
    file << text_data;
    file.close();
}

string loadFromFile(string file_name){
    string text_data;
    ifstream file;
    file.open (file_name);
    file >> text_data;
    file.close();

    return text_data;
}