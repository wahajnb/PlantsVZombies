#include "world.h"

world::world()
{
    //ctor
}

world::~world()
{
    //dtor
}

int world::to_int(string s)
{
    int x = 0;
    stringstream temp(s);
    temp>>x;
    return x;
}
