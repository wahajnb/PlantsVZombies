#include "peaPlant_List.h"

peaPlant_List::peaPlant_List()
{
    //ctor
}

void peaPlant_List::get_Renderer(SDL_Renderer* g)
{
    gRenderer = g;
}

peaPlant_List::~peaPlant_List()
{
    //dtor
}

void peaPlant_List::display()
{
    for (auto i = PeaShooter_arr.begin(); i!=PeaShooter_arr.end();i++)
    {
        (*i)->display();
    }
}

void peaPlant_List::add_peaPlant(PeaShooter* x)
{
    PeaShooter_arr.push_back(x);
}

void peaPlant_List::del_plant(float a, float b)
{
    cout <<"Kr de" << endl;
    for (auto i = PeaShooter_arr.begin(); i!=PeaShooter_arr.end();i++)
    {
        if ((*i)->xcord == a + 10 && (*i)->ycord == b + 10)
        {
            delete (*i);
            (*i) -> die();
            PeaShooter_arr.erase(i);
            cout <<"Peashooter deleted" << endl;
            break;
        }
    }
}
