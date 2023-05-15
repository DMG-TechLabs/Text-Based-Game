#pragma once

#include <vector>
#include "../../Text-Based-Game-Engine/Engine/src/player/player.h"
#include "../map/map.h"
#include "../../Text-Based-Game-Engine/Engine/src/node/node.h"
#include "../mission/mission.h"

/**
 * @brief Day class. Each day sets up the map as well as all the missions of each day. The player object is inherited form the previous day/ initial initialization 
 * 
 */
class Day{
private:

public:
    //Class variables
    Map map;
    vector<Mission> missions;
    Player player;
    bool completed;

    //Constructors
    Day(Map map, vector<Mission> missions ,Player player, bool completed){
        this->map = map;
        this->missions = missions;
        this->player = player;
        this->completed = completed;
    }
    ~Day(){}
}; 