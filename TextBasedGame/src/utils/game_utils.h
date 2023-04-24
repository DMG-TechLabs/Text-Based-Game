#pragma once

#include <iostream>
#include <string>
#include <fstream>
// #include <boost/lexical_cast/lexical_cast_old.hpp>
#include <boost/thread.hpp>   
#include <boost/date_time.hpp>

using std::ofstream;
using std::ifstream;

using namespace std;

void saveToFile(string file_name, string text_data);

string loadFromFile(string file_name);

template <typename T> 
void saveObject(string filename, T object_to_save);

template <typename T> 
T loadObject(string filename, T object_to_load);

//void ThreadworkerFunc();