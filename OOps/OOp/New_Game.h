#ifndef NEW_GAME_H
#define NEW_GAME_H
#include "screen_Image.h"
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <stdio.h>
#include "Music.h"
#include "Sound.h"
#include "peaPlant_Card.h"
#include "sunFlower_Card.h"
#include "chomper_Card.h"
#include "sun_Count.h"
#include "Pause_Game.h"


class New_Game
{
    public:
        New_Game();
        New_Game(SDL_Renderer*, SDL_Texture* );

        SDL_Renderer* gRenderer;
        SDL_Texture* gTexture;

        sun_Count s_count;
        int total_suns;

        void display_NewGame();

        SDL_Event e;
        int mouse_x;
        int mouse_y;

        Mix_Music* gMusic = NULL;
        Music game_Music;

        peaPlant_Card p_Card;
        sunFlower_Card s_Card;
        chomper_Card c_Card;

        bool peaPlant_Carry;
        bool sunFlower_Carry;
        bool chomper_Carry;

        bool game_Loop ;

        Region full_Screen;
        Region seed_Slot;

        Region shovel_Slot;

        Region pausegame_Region;

        screen_Image pauseGame_Button;
        screen_Image pauseGame_ButtonOn;
        screen_Image slot_area;
        screen_Image yard;

        Pause_Game *p_Menu;
        virtual ~New_Game();

    protected:

    private:
};

#endif // NEW_GAME_H
