#pragma once

#include <string>
#include <vector>

using namespace std;

void menu(int bgColor, vector<string> options, void (*handleOptionsFunc)(int selectedOption));