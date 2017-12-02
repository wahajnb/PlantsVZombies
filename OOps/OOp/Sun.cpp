#include "Sun.h"
#include <vector>

Sun::Sun()
{
    //ctor
}

Sun::~Sun()
{
    //dtor
}

void Sun::sun_setcoord(SDL_Renderer* r)
{
    gRenderer = r;
    cur_Timer = 0;
    sun_Flow.ss_Rend = gRenderer;
    sun_Flow.location = &sun_Region;
    sun_Texture = sun_Flow.loadMedia("gifs/Sun/Sun.png");

    point_Sound.set_Sound(gSound);
    point_Sound.load_Sound("Soundtracks/Points.wav");

}

void Sun::produce_Sun()
{
    if (cur_Timer > 10000)
    {
        screen_Image *s = new screen_Image;
        s->ss_Texture = sun_Flow.loadMedia("gifs/Sun/Sun.png");
        s->ss_Rend = gRenderer;
        Region *r = new Region;
        r->area_Rend = gRenderer;
        s->start_x = (rand () % 1310 ) + 40 ;
        s->start_y = 0;
        s->end_x = s->start_x;
        s->end_y = (rand() % 700)+50;
        s->location = r;
        sun_arr.push_back(s);
        cur_Timer = 0;
    }
    cur_Timer++;

}

bool Sun::show_Sun()
{
    for (auto i = sun_arr.begin(); i!=sun_arr.end();i++)
    {
        if((*i)->pick == false)
        {
            (*i)->location->area.x = (*i)->start_x;
            (*i)->location->area.y = (*i)->start_y;
            (*i)->location->area.h = 62;
            (*i)->location->area.w = 62;
            if ((*i)->start_x < (*i)->end_x)
                (*i)->start_x++;
            if ((*i)->start_y < (*i)->end_y)
                (*i)->start_y++;

            (*i)->image_Render();
        }
        else if ((*i)->pick == true)
        {
            (*i)->location->area.x = (*i)->start_x;
            (*i)->location->area.y = (*i)->start_y;
            (*i)->location->area.h = 62;
            (*i)->location->area.w = 62;

            if ((*i)->start_x >25)
                (*i)->start_x = (*i)->start_x - 20;
            if ((*i)->start_y >20)
            (*i)->start_y = (((20-(*i)->start_y)/(20-(*i)->start_x))*(-20))+(*i)->start_y;
            (*i)->image_Render();

            if ((*i)->start_x <=25 && (*i)->start_y <=20)
            {
                delete (*i)->location;
                delete (*i);
                sun_arr.erase(i);
                point_Sound.play_Sound();
                return true;

            }

        }

    }
}

bool Sun::collect_Sun(int x, int y, SDL_Event ke)
{
    for (auto i = sun_arr.begin(); i!=sun_arr.end();i++)
    {
        if ((*i)->location->is_Pressed(x,y,ke) == true )
            {
                (*i)->pick = true;
            }
    }
}




