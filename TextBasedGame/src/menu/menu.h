#pragma once

#include "../../Text-Based-Game-Engine/Engine/src/engine.h"

using namespace Engine;

void disableInputBuffering();
void enableInputBuffering();
void mainMenu(Player player, Map map);
void demoMenu(Player player, Map map);