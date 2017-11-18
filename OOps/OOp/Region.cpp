#include "Region.h"

Region::Region(SDL_Renderer* real,int x, int y, int w, int h)
{
    area_Rend = real;

    area.x = x;
    area.y = y;
    area.w = w;
    area.h = h;
}

Region::~Region()
{
    //dtor
}

bool Region::isOn(int x, int y)
{
    if ((x > area.x+10 && x < area.x+area.w-10 ) && (y > area.y+10 && y < area.y+area.h-10) )
       {
         return true;
       }
    else
    {
        return false;
    }
}


void Region::set_Viewport()
{
    SDL_RenderSetViewport( area_Rend, &area );
}

