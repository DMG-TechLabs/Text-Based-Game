#include "day.h"

//Constructors
Day::Day(){}

Day::Day(vector<Node> nodes, vector<Mission> missions, Player player, bool completed){
    this->nodes = nodes;
    this->missions = missions;
    this->player = player;
    this->completed = completed;
}

Day::~Day(){}