#include "potato_List.h"

potato_List::potato_List()
{
    //ctor
}

potato_List::~potato_List()
{
    //dtor
}

void potato_List::get_Renderer(SDL_Renderer* g)
{
    gRenderer = g;
}

void potato_List::display()
{
    for (auto i = potato_arr.begin(); i!=potato_arr.end();i++)
    {
        (*i)->display();
    }
}

void potato_List::add_potato(Wallnut* x)
{
    potato_arr.push_back(x);
}

void potato_List::del_plant(float a, float b)
{
    cout <<"Kr de" << endl;
    for (auto i = potato_arr.begin(); i!=potato_arr.end();i++)
    {
        if ((*i)->xcord == (a + 10) && (*i)->ycord == b+10 )
        {
            delete (*i);
           // (*i) -> die();
            potato_arr.erase(i);
            cout <<"potato deleted" << endl;
            break;
        }
    }
}
