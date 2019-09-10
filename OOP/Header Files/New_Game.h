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
#include "Lawn.h"
#include "Sun.h"
#include "LTexture.h"
#include "Sunflower.h"
#include "PeaShooter.h"
#include "Pea.h"
#include "Chomper.h"
#include "vector"
#include "sunFlower_List.h"
#include "peaPlant_List.h"
#include "chomper_List.h"
#include "potato_Card.h"
#include "Wallnut.h"
#include "potato_List.h"

class New_Game
{
    public:
        New_Game();
        New_Game(SDL_Renderer*, SDL_Texture* );

        SDL_Renderer* gRenderer;
        SDL_Texture* gTexture;

        sun_Count s_count;          //For converting an int to a texture
        int total_suns;             //Keeps the record of total suns

        bool display_NewGame();

        SDL_Event e;
        int mouse_x;
        int mouse_y;

        Mix_Music* gMusic = NULL;
        Music game_Music;

        Mix_Chunk* psound = NULL;
        Sound plant_Place;

        peaPlant_Card p_Card;
        sunFlower_Card s_Card;
        potato_Card pt_Card;

        bool peaPlant_Carry;
        bool sunFlower_Carry;
        bool potato_Carry;
        bool shovel_Carry;

        bool game_Loop ;

        Sun a;          //For creating random suns

        Region full_Screen;
        Region seed_Slot;
        Region shovel_Slot;
        Region pausegame_Region;
        Region peaplant_root;
        Region sunflower_root;
        Region potato_root;
        Region temp_shovel;
        Region temp_plantRegion;
        Region *temp_plantShove;

        screen_Image pauseGame_Button;
        screen_Image pauseGame_ButtonOn;
        screen_Image slot_area;
        screen_Image yard;
        screen_Image peaplant_rooting;
        screen_Image sunflower_rooting;
        screen_Image potato_rooting;
        screen_Image shovel_card;
        screen_Image shovel;

        Lawn front_Yard;

        LTexture SunflowerTexture;
        LTexture PeaShooterTexture;
        LTexture SunningTexture;
        LTexture ChomperTexture;
        LTexture EatingTexture;
        LTexture WallnutTexture;
        LTexture HitTexture;
        LTexture MoreHitTexture;

        sunFlower_List s_List;
        peaPlant_List pp_List;
        potato_List pt_List;

        Pause_Game *p_Menu;
        virtual ~New_Game();

    protected:

    private:
};

#endif // NEW_GAME_H
