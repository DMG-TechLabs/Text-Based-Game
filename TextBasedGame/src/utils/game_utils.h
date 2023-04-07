#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <boost/lexical_cast/lexical_cast_old.hpp>

using std::ofstream;
using std::ifstream;

using namespace std;

void saveToFile(string file_name, string text_data);

string loadFromFile(string file_name);

void saveToFile(string file_name, string data,int i);