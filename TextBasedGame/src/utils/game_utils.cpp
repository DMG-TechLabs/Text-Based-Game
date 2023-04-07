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

void saveToFile(string file_name, string data,int i){
    ofstream file;
    file.open(file_name, ios::out | ios::binary);
    file.write((char *) &data, sizeof(string));
    file.close();
    if(!file.good()) {
        cout << "Error occurred at writing time!" << endl;
        return;
    }
}