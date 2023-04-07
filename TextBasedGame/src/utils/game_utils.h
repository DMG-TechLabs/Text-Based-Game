#pragma once

#include <iostream>
#include <string>
#include <fstream>

using std::ofstream;
using std::ifstream;

using namespace std;

void saveToFile(string file_name, string text_data);

string loadFromFile(string file_name);