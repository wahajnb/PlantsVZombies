#include "chomper_Card.h"

chomper_Card::chomper_Card()
{
    //ctor
}

chomper_Card::~chomper_Card()
{
    //dtor
}

void chomper_Card::load_Media(SDL_Renderer* r, SDL_Texture* t)
{
    gRenderer = r;
    gTexture = t;

    sun_required = 150;

    total_Time = 200;
    taken_Time = 0;

    on_Cooldown = false;

    card_Region.set_Coords(gRenderer,283, 10, 73,100);          //Pea plant slot

    for (int i = 0 ; i < 7 ; i++)
    {
        stringstream aa;
        string s = "";
        string name = "";
        aa << i+1;
        s = aa.str();
        name = "Gifs/Chomper Card/" + s + ".png";
        card_State[i].location = &card_Region;
        card_State[i].ss_Rend = gRenderer;
        card_State[i].loadMedia(name);
    }

}

void chomper_Card::display_Card()
{
    if (on_Cooldown == false)
    {
        card_State[0].image_Render();
    }
    else
    {
        if(total_Time-taken_Time > 0 && total_Time-taken_Time < 10)
            card_State[0].image_Render();
        else if(total_Time-taken_Time >= 10 && total_Time-taken_Time < 20)
            card_State[1].image_Render();
        else if(total_Time-taken_Time >= 20 && total_Time-taken_Time < 30)
            card_State[2].image_Render();
        else if(total_Time-taken_Time >= 30 && total_Time-taken_Time < 40)
            card_State[3].image_Render();
        else if(total_Time-taken_Time >= 40 && total_Time-taken_Time < 50)
            card_State[4].image_Render();
        else if(total_Time-taken_Time >= 50 && total_Time-taken_Time < 60)
            card_State[5].image_Render();
        else if(total_Time-taken_Time >= 60 && total_Time-taken_Time < 500)
            card_State[6].image_Render();

        taken_Time ++;
    }

    if(taken_Time > total_Time)
    {
        taken_Time = 0;
        on_Cooldown = false;
    }
}
