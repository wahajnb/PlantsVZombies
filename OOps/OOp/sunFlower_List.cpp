#include "sunFlower_List.h"

sunFlower_List::sunFlower_List()
{

}

void sunFlower_List::get_Renderer(SDL_Renderer* g)
{
    gRenderer = g;
}

void sunFlower_List::display()
{
    for (auto i = sunflower_arr.begin(); i!=sunflower_arr.end();i++)
    {
        (*i)->display();
    }
}

void sunFlower_List::add_Sunflower(Sunflower* x)
{
    sunflower_arr.push_back(x);
}

sunFlower_List::~sunFlower_List()
{
    //dtor
}
