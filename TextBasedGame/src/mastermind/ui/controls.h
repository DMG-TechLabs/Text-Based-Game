#pragma once

static const int ENTER = 0;
static const int UP = 1;
static const int DOWN = 2;
static const int LEFT = 3;
static const int RIGHT = 4;
static const int EQUALS = 200;


namespace Mastermind{
    int handleKeys();
    void enableInputBuffering();
    void disableInputBuffering();
}