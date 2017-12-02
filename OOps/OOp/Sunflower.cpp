#include "Sunflower.h"
#include "Plants.h"
#include <windows.h>
#include"LTexture.h"



using namespace std;

Sunflower::Sunflower()
{
    //Sets up a basic sunflower plant in-game.
    this -> cost = 50;
    this -> health = 100;
    this -> range = 0;
    this -> damage = 0;
    this -> rate = 3;
    this -> sun = true;
    this -> exists = true;
    name = "Sunflower";
    //LoopSun(rate);

}


Sunflower::Sunflower(SDL_Renderer * gRenderer, LTexture* NImage, LTexture * SImage, float x, float y)
{
    //Sets up a basic sunflower plant in-game.
    //SDL function to display a Sunflower plant.
    this -> cost = 50;
    this -> health = 100;
    this -> range = 0;
    this -> damage = 0;
    this -> rate = 3;
    this -> sun = false;
    this -> exists = true;
    name = "Sunflower";
    //LoopSun(rate);

    int tempx = 0;
    int tempy = 0;
    int z = 0;
    SunflowerTexture = NImage;
    SunningTexture = SImage;
    this -> gRenderer = gRenderer;

        for (int i = 0; i < 2; i++)
        {
            for(int j = 0; j < 30; j++)
            {
                SunflowerClips[ z ].x = tempx;
                SunflowerClips[ z ].y = tempy;
                SunflowerClips[ z ].w = 203;
                SunflowerClips[ z ].h = 219;

                z = z + 1;
                tempy = tempy + 219;
            }
            tempy = 0;
            tempx = tempx + 203;
        }

        for(int i = 0; i < 8; i++)
        {
            SunningClips[ i ].x = 0;
            SunningClips[ i ].y = tempy;
            SunningClips[ i ].w = 468;
            SunningClips[ i ].h = 542;

            tempy = tempy + 542;
        }
    this -> xcord = x;
    this -> ycord = y;

    this -> width = SunflowerClips[ 0 ].w;
    this -> height = SunflowerClips[ 0 ].h;
}

void Sunflower::display()
{
    if (exists == true)
    {
            if (!sun)
        {
            this -> Render(framesxyz[0], gRenderer, false);
            framesxyz[0] += 0.158;
            if (framesxyz[0] >= 59.9875)
            {
                sun = true;
                framesxyz[0] = 0.5;
            }
        }
        else if(sun == true)
        {
            this -> Render(framesxyz[1], gRenderer, true);
            framesxyz[1] += 0.2;
            if(framesxyz[1] >= 7.9875)
            {
                sun = false;
                framesxyz[1] = 0;
            }
        }
    }

}

/*
void Sunflower::display(SDL_Renderer* gRenderer)
{
    Uint32 ticks = SDL_GetTicks();
    if (!sun)
    {
        //Uint32 ticks = SDL_GetTicks();
        Uint32 FrameNormal = (ticks/80)%60;
        this -> Render(FrameNormal, gRenderer, false);
        ++FrameNormal;
        if (FrameNormal == 60)
        {
            sun = true;
            ticks = 0;
        }
    }
    else if(sun == true)
    {
        //Uint32 ticks = SDL_GetTicks();
        Uint32 FrameSunning = (ticks/80)%13;
        this -> Render(FrameSunning, gRenderer, true);
        ++FrameSunning;
        if(FrameSunning == 13)
        {
            sun = false;
            ticks = 0;
        }
    }
}
*/

void Sunflower::displaynormal(SDL_Renderer* gRenderer)
{
        Uint32 ticks = SDL_GetTicks();
        Uint32 FrameNormal = (ticks/80)%60;
        this -> Render(FrameNormal, gRenderer, false);
}

void Sunflower::displaysunning(SDL_Renderer* gRenderer)
{
        Uint32 ticks = SDL_GetTicks();
        Uint32 FrameSunning = (ticks/80)%13;
        this -> Render(FrameSunning, gRenderer, true);
        ++FrameSunning;
}


bool Sunflower::GetExists()
{
    return this -> exists;
}

int Sunflower::GetHealth()
{
    return this -> health;
}

void Sunflower::IsHit(int damage)
{
    this -> health = this -> health - damage;
}

bool Sunflower::SunIsClicked()
{

}



void Sunflower::LoopSun(int rate)
{
    if (this -> exists)
    {
        if (!sun)
        {
            Sleep(rate*1000);
            //SDL function to display a dropping sun
            sun = true;
        }
        if (sun)
        {
            if(SunIsClicked() == true)
            {
                //SDL function to remove the sun from the screen
                sun = false;
            }
        }
    }
}



void Sunflower::Render(Uint32 frame, SDL_Renderer* gRenderer, bool sunning)
{
    if (sunning == false)
    {
        SunflowerTexture -> Render( xcord, ycord, 115, 130, &SunflowerClips[ frame % NormalFrames ], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    }
    else if (sunning == true)
    {
        SunningTexture -> Render( xcord-7, ycord-18, 125, 150, &SunningClips[ frame % SFrames ], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    }
}




void Sunflower::die()
{
    delete this;
    //SunflowerTexture = NULL;
    //SDL function to kill the plant
}



Sunflower::~Sunflower()
{

}


