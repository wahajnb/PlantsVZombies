#ifndef PLANT_CARD_H
#define PLANT_CARD_H
#include "screen_Image.h"
#include <SDL.h>
#include <SDL_image.h>
#include <time.h>
#include <iostream>
#include <stdio.h>
#include <sstream>
#include <ctime>

class plant_Card
{
    public:
        plant_Card();
        SDL_Renderer* gRenderer;
        SDL_Texture* gTexture;

        screen_Image card_State[10];

        Region card_Region;

        bool on_Cooldown;
        int total_Time;
        int taken_Time;
        int sun_required;

        virtual ~plant_Card();

    protected:

    private:
};

#endif // PLANT_CARD_H
