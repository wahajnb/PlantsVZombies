#include "chomper_List.h"

chomper_List::chomper_List()
{
    //ctor
}

chomper_List::~chomper_List()
{
    //dtor
}

void chomper_List::get_Renderer(SDL_Renderer* g)
{
    gRenderer = g;
}

void chomper_List::display()
{
    for (auto i = chomper_arr.begin(); i!=chomper_arr.end();i++)
    {
        (*i)->display();
    }
}

void chomper_List::add_chomper(Chomper* x)
{
    chomper_arr.push_back(x);
}

