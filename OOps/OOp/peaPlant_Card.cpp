#include "peaPlant_Card.h"


peaPlant_Card::peaPlant_Card()
{
    //ctor
}

peaPlant_Card::~peaPlant_Card()
{
    //dtor
}

void peaPlant_Card::load_Media(SDL_Renderer* r, SDL_Texture* t)
{
    gRenderer = r;
    gTexture = t;

    on_Cooldown = false;

    card_Region.set_Coords(gRenderer,203, 10, 73,100);          //Pea plant slot

    for (int i = 0 ; i < 10 ; i++)
    {
        stringstream aa;
        string s = "";
        string name = "";
        aa << i+1;
        s = aa.str();
        name = "Gifs/Pea Plant Card/" + s + ".png";
        card_State[i].location = &card_Region;
        card_State[i].ss_Rend = gRenderer;
        card_State[i].loadMedia(name);
    }

    cooldown = 9;

}

peaPlant_Card::peaPlant_Card(SDL_Renderer* r, SDL_Texture* t)
{
    gRenderer = r;
    gTexture = t;

    on_Cooldown = false;

    card_Region.set_Coords(gRenderer,203, 10, 73,100);          //Pea plant slot

    for (int i = 0 ; i < 10 ; i++)
    {
        stringstream aa;
        string s = "";
        string name = "";
        aa << i;
        s = aa.str();
        name = "Gifs/Pea Plant Card/" + s + ".png";
        card_State[i].location = &card_Region;
        card_State[i].loadMedia(name);
    }

    cooldown = 9;

}

void peaPlant_Card::display_Card()
{
    if (on_Cooldown == false)
    {
        card_State[0].image_Render();
    }
    else
    {
        start_Time = time(NULL);
        if(difftime(end_Time,start_Time) > 0 && difftime(end_Time,start_Time) < 1)
            card_State[1].image_Render();
        else if(difftime(end_Time,start_Time) >= 1 && difftime(end_Time,start_Time) < 2)
            card_State[2].image_Render();
        else if(difftime(end_Time,start_Time) >= 2 && difftime(end_Time,start_Time) < 3)
            card_State[3].image_Render();
        else if(difftime(end_Time,start_Time) >= 3 && difftime(end_Time,start_Time) < 4)
            card_State[4].image_Render();
        else if(difftime(end_Time,start_Time) >= 4 && difftime(end_Time,start_Time) < 5)
            card_State[5].image_Render();
        else if(difftime(end_Time,start_Time) >= 5 && difftime(end_Time,start_Time) < 6)
            card_State[6].image_Render();
        else if(difftime(end_Time,start_Time) >= 6 && difftime(end_Time,start_Time) < 7)
            card_State[7].image_Render();
        else if(difftime(end_Time,start_Time) >= 7 && difftime(end_Time,start_Time) < 8)
            card_State[8].image_Render();
        else if(difftime(end_Time,start_Time) >= 8 && difftime(end_Time,start_Time) < 9)
            card_State[9].image_Render();

    }
}

