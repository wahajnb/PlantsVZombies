#include "Chomper.h"
#include <time.h>
#include "Pea.h"
#include "PeaShooter.h"
#include <windows.h>
#include "LTexture.h"



Chomper::Chomper(SDL_Renderer * gRenderer, LTexture* NImage, LTexture * EImage, float x, float y)
{
    //Sets up a basic sunflower plant in-game.
    int health = 150;
    int damage = 50;
    int cost = 100;
    int range = 2;
    int rate = 0;
    //this -> sun = false;
    bool exists = true;
    name = "Chomper";

    int tempy = 0;
    ChomperTexture = NImage;
    EatingTexture = EImage;
    this -> gRenderer = gRenderer;

    for (int i = 0; i < 31; i++)
    {
        ChomperClips[ i ].x = 0;
        ChomperClips[ i ].y = tempy;
        ChomperClips[ i ].w = 100;
        ChomperClips[ i ].h = 100;

        tempy = tempy + 100;
    }
    tempy=0;

    for (int i = 0; i < 20; i++)
    {
        EatingClips[ i ].x = 0;
        EatingClips[ i ].y = tempy;
        EatingClips[ i ].w = 83;
        EatingClips[ i ].h = 84;

        tempy = tempy + 84;
    }

    this -> xcord = x;
    this -> ycord = y;

    this -> width = ChomperClips[0].w;
    this -> height = ChomperClips[0].h;
}



/*Chomper::Chomper()
{
    int health = 150;
    int damage = 50;
    int cost = 100;
    int range = 2;
    int rate = 4;
    string name = "Chomper";
    bool exists = true;
}*/



void Chomper::display()
{
    if (!sun)
    {
        this -> Render(framesxyz[0], gRenderer, false);
        framesxyz[0] += 0.158;
        if (framesxyz[0] >= 30.9875)
        {
            sun = true;
            framesxyz[0] = 0.5;
        }
    }
    else if(sun == true)
    {
        this -> Render(framesxyz[1], gRenderer, true);
        framesxyz[1] += 0.2;
        if(framesxyz[1] >= 17.9875)
        {
            sun = false;
            framesxyz[1] = 0;
        }
    }
}



void Chomper::displaynormal(SDL_Renderer* gRenderer)
{
    Uint32 ticks = SDL_GetTicks();
    Uint32 ChomperFrame = (ticks/75)%31;
    this -> Render(ChomperFrame, gRenderer, false);
}

void Chomper::displayeating(SDL_Renderer* gRenderer)
{
    Uint32 ticks = SDL_GetTicks();
    Uint32 EatingFrame = (ticks/100)%20;
    this -> Render(EatingFrame, gRenderer, true);
    //++EatingFrame;
}



bool Chomper::GetExists()
{
    return this -> exists;
}

int Chomper::GetHealth()
{
    return this -> health;
}

void Chomper::IsHit(int damage)
{
    this -> health = this -> health - damage;
}



void Chomper::Render(Uint32 frame, SDL_Renderer* gRenderer, bool x)
{
    if(x == false)
    {
        ChomperTexture -> Render( xcord, ycord, 124, 144, &ChomperClips[ frame % NormalFrames ], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    }
    else if (x == true)
    {
        EatingTexture -> Render( xcord, ycord, 124, 144, &EatingClips[ frame % EatingFrames ], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    }
}



/*void die()
{
    this -> exists = false;
    //SDL function to kill the plant
}*/



Chomper::~Chomper()
{
    //dtor
}
