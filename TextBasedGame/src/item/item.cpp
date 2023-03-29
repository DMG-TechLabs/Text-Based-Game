#include "item.h"


class Item{
private:
    /* data */
public:
    string Description;
    Command commands[1];
    Item(string Description){ this->Description = Description; cout << Description << endl;}
    ~Item(){}

};
