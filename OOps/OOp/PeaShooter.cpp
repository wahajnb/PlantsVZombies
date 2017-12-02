#include "PeaShooter.h"
#include <time.h>
#include "Pea.h"
#include "PeaShooter.h"
#include <windows.h>

using namespace std;


PeaShooter::PeaShooter(SDL_Renderer * gRenderer, LTexture* image, float x, float y)
{
    //Sets up a basic sunflower plant in-game.
    this -> cost = 50;
    this -> health = 100;
    this -> range = 0;
    this -> damage = 0;
    this -> rate = 0;
    this -> sun = false;
    this -> exists = true;
    name = "PeaShooter";
    P1 = NULL;
    //LoopSun(rate);

    int tempx = 0;
    int tempy = 0;
    int z = 0;
    PeaShooterTexture = image;
    this -> gRenderer = gRenderer;

    for (int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 7; j++)
        {
            PeaShooterClips[ z ].x = tempx;
            PeaShooterClips[ z ].y = tempy;
            PeaShooterClips[ z ].w = 644;
            PeaShooterClips[ z ].h = 616;

            z = z + 1;
            tempx = tempx + 644;
        }
        tempx = 0;
        tempy = tempy + 616;
    }

    this -> xcord = x;
    this -> ycord = y;

    this -> width = PeaShooterClips[ 0 ].w;
    this -> height = PeaShooterClips[ 0 ].h;

    pea_Shoot.set_Sound(psound);
    pea_Shoot.load_Sound("Soundtracks/Throw.wav");
}




PeaShooter::PeaShooter()
{
    //Sets up a basic peashooter plant in-game.
    //SDL function to display a Peashooter plant here.
    this -> cost = 75;
    this -> health = 100;
    this -> range = 9999;
    this -> damage = 0;
    this -> rate = 3;
    this -> exists = true;
    name = "Pea Shooter";
    P1 = NULL;
    //LoopShooting(rate);
}


void PeaShooter::display()
{
    Uint32 ticks = SDL_GetTicks();
    PeaShooterFrame = (ticks/50)%56;
    this -> Render(PeaShooterFrame, gRenderer);
    ++PeaShooterFrame;
    if (PeaShooterFrame == 29)
    {
        delete P1;
        P1 = new Pea(gRenderer, this -> xcord +100, this -> ycord +35);
        pea_Shoot.play_Sound();
    }
    if(P1)
    {
        P1 -> display();
    }
}


bool PeaShooter::GetExists()
{
    return this -> exists;
}

int PeaShooter::GetHealth()
{
    return this -> health;
}

void PeaShooter::IsHit(int damage)
{
    this -> health = this -> health - damage;
}



void PeaShooter::Render(Uint32 frame, SDL_Renderer* gRenderer)
{
    PeaShooterTexture -> Render( xcord, ycord, 130, 124, &PeaShooterClips[ frame % NormalFrames ], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
}



void PeaShooter::die()
{
    this -> exists = false;
    //SDL function to kill the plant
}



PeaShooter::~PeaShooter()
{
    //dtor
}
