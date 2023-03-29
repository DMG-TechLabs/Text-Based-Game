#include "room.h"

class Room{
private:
    /* data */
public:
    std::string Description;
    Item terminal = Item("Terminal");
    Movement movement;
    // Item items[];
    // Command commands[];


    Room(/* args */){cout << "Hello from Room" << endl;}
    ~Room(){}
};