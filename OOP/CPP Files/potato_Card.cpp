#include "potato_Card.h"

potato_Card::potato_Card()
{
    //ctor
}

potato_Card::~potato_Card()
{
    //dtor
}

void potato_Card::load_Media(SDL_Renderer* r, SDL_Texture* t)
{
    gRenderer = r;
    gTexture = t;
    sun_required = 50;

    on_Cooldown = false;
    total_Time = 100;
    taken_Time = 0;

    card_Region.set_Coords(gRenderer,283, 10, 73,100);          //Potato plant slot

    for (int i = 0 ; i < 5 ; i++)
    {
        stringstream aa;
        string s = "";
        string name = "";
        aa << i+1;
        s = aa.str();
        name = "Gifs/Potato Plant Card/" + s + ".png";
        card_State[i].location = &card_Region;
        card_State[i].ss_Rend = gRenderer;
        card_State[i].loadMedia(name);
    }

}

potato_Card::potato_Card(SDL_Renderer* r, SDL_Texture* t)
{
    gRenderer = r;
    gTexture = t;
    on_Cooldown = false;

    card_Region.set_Coords(gRenderer,283, 10, 73,100);          //Potato plant slot

    for (int i = 0 ; i < 5 ; i++)
    {
        stringstream aa;
        string s = "";
        string name = "";
        aa << i+1;
        s = aa.str();
        name = "Gifs/Potato Plant Card/" + s + ".png";
        card_State[i].location = &card_Region;
        card_State[i].ss_Rend = gRenderer;
        card_State[i].loadMedia(name);
    }
}

void potato_Card::display_Card()
{
    if (on_Cooldown == false)
    {
        card_State[0].image_Render();
    }
    else
    {
        if(total_Time-taken_Time > 0 && total_Time-taken_Time < 10)
            card_State[1].image_Render();
        else if(total_Time-taken_Time >= 10 && total_Time-taken_Time < 20)
            card_State[2].image_Render();
        else if(total_Time-taken_Time >= 20 && total_Time-taken_Time < 100)
            card_State[3].image_Render();


        taken_Time ++;
    }

    if(taken_Time > total_Time)
    {
        taken_Time = 0;
        on_Cooldown = false;
    }
}

void potato_Card::display()
{
    if (on_Cooldown == false)
    {
        card_State[0].image_Render();
    }
    else
    {
        if(total_Time-taken_Time > 0 && total_Time-taken_Time < 10)
            card_State[1].image_Render();
        else if(total_Time-taken_Time >= 10 && total_Time-taken_Time < 20)
            card_State[2].image_Render();
        else if(total_Time-taken_Time >= 20 && total_Time-taken_Time < 100)
            card_State[3].image_Render();




        taken_Time ++;
    }

    if(taken_Time > total_Time)
    {
        taken_Time = 0;
        on_Cooldown = false;
    }
}

