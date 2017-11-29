#include "Region.h"

Region::Region(SDL_Renderer* real,int x, int y, int w, int h)
{
    area_Rend = real;
    area.x = x;
    area.y = y;
    area.w = w;
    area.h = h;
}

Region::Region(SDL_Renderer* real)
{
    area_Rend = real;
}

Region::Region()
{

}

Region::~Region()
{
    //dtor
}

bool Region::isOn(int x, int y)         //Checks if the mouse is on certain area with a negative 10 from each side
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
    SDL_RenderSetViewport( area_Rend, &area );      //Sets the region to render
}

bool Region::is_Pressed(int x1, int y1, SDL_Event se)           //Checks whether the mouse is clicked on a certain area
{
    if (this->isOn(x1,y1) == true)
    {
        if(se.type == SDL_MOUSEBUTTONDOWN)
        {
            if(se.button.button == SDL_BUTTON_LEFT)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }

}

bool Region::onLawn(int x, int y)       //Checks if the mouse is on certain area with a negative 2 from each side
{
    if ((x > area.x+2 && x < area.x+area.w-2 ) && (y > area.y+2 && y < area.y+area.h-2) )
       {
         return true;
       }
    else
    {
        return false;
    }
}

void Region::set_Coords (SDL_Renderer* real,int x, int y, int w, int h)         //Set the coordinates for a region
{
    area_Rend = real;
    area.x = x;
    area.y = y;
    area.w = w;
    area.h = h;
}
