#ifndef SUN_H
#define SUN_H
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <stdio.h>
#include "screen_Image.h"
#include <vector>
#include <random>
#include "Sound.h"

class Sun
{
    public:
        Sun();

        SDL_Renderer *gRenderer;
        SDL_Texture *sun_Texture;
        screen_Image sun_Flow;
        Region sun_Region;
        bool show_Sun();
        int cur_Timer;
        void produce_Sun();
        vector <screen_Image*> sun_arr;
        void sun_setcoord(SDL_Renderer*);
        bool collect_Sun(int,int,SDL_Event);
        virtual ~Sun();

        Mix_Chunk* gSound = NULL;
        Sound point_Sound;

    protected:

    private:
};

#endif // SUN_H
