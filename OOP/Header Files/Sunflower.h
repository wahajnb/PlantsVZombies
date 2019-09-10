#ifndef SUNFLOWER_H
#define SUNFLOWER_H
#include "Plants.h"
#include <stdio.h>
#include <time.h>
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include"LTexture.h"



class Sunflower : public Plants
{
    public:
        Sunflower(SDL_Renderer * gRenderer, LTexture * NImage, LTexture * SImage, float x, float y);
        Sunflower();
        virtual ~Sunflower();
        void LoopSun(int rate);
        bool SunIsClicked();
        void die ();
        void wait(int);
        bool GetExists();
        int GetHealth();
        void IsHit(int);
        //Uint32 SunflowerFrame;
        //Uint32 SunningFrame;
        float framesxyz[2];

        virtual void Render(Uint32 frame, SDL_Renderer* gRenderer, bool);
        void display();
        void displaynormal(SDL_Renderer * gRenderer);
        void displaysunning(SDL_Renderer * gRenderer);

    protected:
        enum NormalFrames {NormalFrames = 60, SFrames = 8};
        SDL_Rect SunflowerClips[ NormalFrames ];
        LTexture * SunflowerTexture;
        SDL_Rect SunningClips[SFrames];
        LTexture * SunningTexture;


    private:
        SDL_Renderer * gRenderer;
};

#endif // SUNFLOWER_H
