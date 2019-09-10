#include "Wallnut.h"

Wallnut::Wallnut(SDL_Renderer * gRenderer, LTexture * NImage, LTexture * HImage, LTexture * MHImage, float x, float y)
{
    this -> cost = 150;
    this -> health = 500;
    this -> range = 0;
    this -> damage = 0;
    this -> sun = false;
    this -> exists = true;
    name = "Wallnut";

    WallnutTexture = NImage;
    HitTexture = HImage;
    MoreHitTexture = MHImage;
    this -> gRenderer = gRenderer;
    int tempx = 0;
    int tempy = 0;
    int z = 0;

        for (int i = 0; i < 10; i++)
        {
            for(int j = 0; j < 2; j++)
            {
                WallnutClips[ z ].x = tempx;
                WallnutClips[ z ].y = tempy;
                WallnutClips[ z ].w = 452;
                WallnutClips[ z ].h = 500;

                z = z + 1;
                tempx = tempx + 452;
            }
            tempx = 0;
            tempy = tempy + 500;
        }

    HitClip[ 0 ].x = 0;
    HitClip[ 0 ].y = 0;
    HitClip[ 0 ].w = 100;
    HitClip[ 0 ].h = 100;

    MoreHitClip[ 0 ].x = 0;
    MoreHitClip[ 0 ].y = 0;
    MoreHitClip[ 0 ].w = 100;
    MoreHitClip[ 0 ].h = 100;

    this -> xcord = x;
    this -> ycord = y;

    this -> width = WallnutClips[ 0 ].w;
    this -> height = WallnutClips[ 0 ].h;
}



void Wallnut::display()
{
    if (health > 250 && health <= 500)
    {
        this -> Render(frames, gRenderer, 0);
        frames += 0.158;
        health -= 1;
    }
    else if(health <= 250 && health > 100)
    {
        this -> Render(0, gRenderer, 1);
        health -= 1;
    }
    else if(health <= 100 && health > 0)
    {
        this -> Render(0, gRenderer, 2);
        health -= 1;
    }
    else if(health == 0)
    {
        health = 500;
        //delete this;
    }
}



void Wallnut::displaynormal()
{
        Uint32 ticks = SDL_GetTicks();
        Uint32 FrameNormal = (ticks/80)%20;
        this -> Render(FrameNormal, gRenderer, 0);
}

void Wallnut::displayhit()
{
        Uint32 ticks = SDL_GetTicks();
        Uint32 Framehit = (ticks/80)%1;
        this -> Render(Framehit, gRenderer, 1);
}

void Wallnut::displaymorehit()
{
        Uint32 ticks = SDL_GetTicks();
        Uint32 Framemorehit = (ticks/80)%1;
        this -> Render(Framemorehit, gRenderer, 2);
}



bool Wallnut::GetExists()
{
    return this -> exists;
}

int Wallnut::GetHealth()
{
    return this -> health;
}

void Wallnut::IsHit(int damage)
{
    this -> health = this -> health - damage;
}



void Wallnut::Render(Uint32 frame, SDL_Renderer* gRenderer, int x)
{
    if(x == 0)
    {
        WallnutTexture -> Render( xcord, ycord, 110, 121, &WallnutClips[ frame % WallnutFrames ], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    }
    if(x == 1)
    {
        HitTexture -> Render( xcord, ycord, 110, 121, &HitClip[ frame % HitFrame ], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    }
    if(x == 2)
    {
        MoreHitTexture -> Render( xcord, ycord, 110, 121, &MoreHitClip[ frame % MoreHitFrame ], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    }
}



void Wallnut::die()
{
    delete this;
    //SunflowerTexture = NULL;
    //SDL function to kill the plant
}



Wallnut::~Wallnut()
{
    //dtor
}
