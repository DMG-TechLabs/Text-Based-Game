#pragma once

#include <iostream>
#include <string>

using namespace std;

class Text{
    public:
        static const string normal;
        static const string bold;
        static const string underline;

        static const string clear;
        static const string erase_line;

        static const string black;
        static const string red;
        static const string green;
        static const string yellow;
        static const string blue;
        static const string purple;
        static const string cyan;
        static const string lgrey;
        static const string dgrey;
        
        static const string u_black;
        static const string u_red;
        static const string u_green;
        static const string u_yellow;
        static const string u_blue;
        static const string u_purple;
        static const string u_cyan;
        static const string u_lgrey;
        static const string u_dgrey;
        
        static const string b_black;
        static const string b_red;
        static const string b_green;
        static const string b_yellow;
        static const string b_blue;
        static const string b_purple;
        static const string b_cyan;
        static const string b_lgrey;
        static const string b_dgrey;

        static string color(string where, int color);
};

