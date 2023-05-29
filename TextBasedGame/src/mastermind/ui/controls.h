#pragma once

static const int ENTER = 0;
static const int KEY_UP = 1;
static const int KEY_DOWN = 2;
static const int KEY_LEFT = 3;
static const int KEY_RIGHT = 4;

int handleKeys();
void enableInputBuffering();
void disableInputBuffering();