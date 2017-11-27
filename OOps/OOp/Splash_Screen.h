#ifndef SPLASH_SCREEN_H
#define SPLASH_SCREEN_H
#include "screen_Image.h"
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <stdio.h>

using namespace std;

class Splash_Screen
{
    public:
        Splash_Screen(SDL_Renderer*, SDL_Texture*);
        ~Splash_Screen();
        void splash_Display();
        screen_Image splash[11];                //Array for splash screen animation
        SDL_Renderer* gRenderer;
        SDL_Texture* gTexture;
        Region full_Screen;

    protected:

    private:
};

#endif // SPLASH_SCREEN_H
