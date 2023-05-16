#pragma once

#include <vector>
#include "../../Text-Based-Game-Engine/Engine/src/player/player.h"
#include "../map/map.h"
#include "../../Text-Based-Game-Engine/Engine/src/node/node.h"
#include "../mission/mission.h"

using namespace Engine;

namespace Day{
    void demo(Player *player, Map *map);
    void dayOne(Player *player, Map *map);
    void dayTwo(Player *player, Map *map);
    void dayThree(Player *player, Map *map);
}