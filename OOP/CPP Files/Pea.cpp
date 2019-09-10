#include "Pea.h"
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include "LTexture.h"
#include <time.h>
#include "Sunflower.h"
#include "PeaShooter.h"

using namespace std;


Pea::Pea()
{

}



Pea::Pea(SDL_Renderer* gRenderer, float x, float y)
{
    this -> speed = 8;
    this -> damage = 20;
    this -> exists = true;
    this -> name = "pea";

    PeaClip[ 0 ].x = 0;
    PeaClip[ 0 ].y = 0;
    PeaClip[ 0 ].w = 152;
    PeaClip[ 0 ].h = 138;

    this -> xcord = x;
    this -> ycord = y;

    this -> width = PeaTexture . GetWidth();
    this -> height = PeaTexture . GetHeight();
    this->gRenderer = gRenderer;

    if(!loadMedia()){
        cout<<"Unable to load Pea Texture"<<endl;
    }
}



void Pea::display()//Uint32 frame)
{
    Uint32 ticks = SDL_GetTicks();
    PeaFrame = (ticks/1)%1;
    this -> Render(PeaFrame, gRenderer);
    this -> move(this -> speed);
}



int Pea::GetDamage()
{
   return (this -> damage);
}



int Pea::GetSpeed()
{
    return (this -> speed);
}



void Pea::move(int speed)
{
    xcord = xcord + speed;
}



bool Pea::Die()
{
    if(this -> xcord > 1366)
        return true;
    else
        return false;
    //if yes this -> exists = false
}



void Pea::Render(Uint32 frame, SDL_Renderer* gRenderer)
{
    PeaTexture . Render( xcord, ycord, 25, 25, &PeaClip[ frame % NormalFrame ], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
}


Pea::~Pea()
{
    //dtor
}
bool Pea::loadMedia()
{
	if( !PeaTexture.LoadFromFile( "Gifs/Pea/Pea.png", gRenderer  ) )
	{
		printf( "Failed to load pea texture!\n" );
		return false;
	}
	return true;
}
