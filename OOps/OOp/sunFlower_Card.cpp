#include "sunFlower_Card.h"

sunFlower_Card::sunFlower_Card()
{
    //ctor
}

void sunFlower_Card::load_Media(SDL_Renderer* r, SDL_Texture* t)
{
    gRenderer = r;
    gTexture = t;

    total_Time = 40;
    taken_Time = 0;

    on_Cooldown = false;

    card_Region.set_Coords(gRenderer,120, 10, 73,100);          //Pea plant slot

    for (int i = 0 ; i < 5 ; i++)
    {
        stringstream aa;
        string s = "";
        string name = "";
        aa << i+1;
        s = aa.str();
        name = "Gifs/Sunflower Card/" + s + ".png";
        card_State[i].location = &card_Region;
        card_State[i].ss_Rend = gRenderer;
        card_State[i].loadMedia(name);
    }

}

sunFlower_Card::~sunFlower_Card()
{
    //dtor
}

void sunFlower_Card::display_Card()
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
        else if(total_Time-taken_Time >= 20 && total_Time-taken_Time < 30)
            card_State[3].image_Render();
        else if(total_Time-taken_Time >= 30 && total_Time-taken_Time < 40)
            card_State[4].image_Render();

        taken_Time ++;
    }

    if(taken_Time > total_Time)
    {
        taken_Time = 0;
        on_Cooldown = false;
    }
}
