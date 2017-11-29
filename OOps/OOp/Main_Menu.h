#ifndef MAIN_MENU_H
#define MAIN_MENU_H
#include "screen_Image.h"
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <stdio.h>
#include "New_Game.h"
#include "Music.h"
#include "Sound.h"

using namespace std;

class Main_Menu
{
    public:
        Main_Menu(SDL_Renderer*, SDL_Texture* );
        void display_MainMenu ();
        SDL_Renderer* gRenderer;
        SDL_Texture* gTexture;
        Mix_Music* gMusic = NULL;
        Mix_Chunk* press = NULL;
        Music mainMenu_Music;
        Sound button_Press;

        bool mainMenu_Loop;
        SDL_Event e;
        int mouse_x;
        int mouse_y;

        Region full_Screen;
        Region newGame_Region;
        Region loadGame_Region;
        Region exitGame_Region;
        screen_Image menu_Screen;
        screen_Image newGame_Button;
        screen_Image loadGame_Button;
        screen_Image exitGame_Button;
        screen_Image newGame_ButtonOn;
        screen_Image loadGame_ButtonOn;
        screen_Image exitGame_ButtonOn;
        screen_Image newGame_ButtonPress;
        screen_Image loadGame_ButtonPress;
        screen_Image exitGame_ButtonPress;

        New_Game *game_Start;

        virtual ~Main_Menu();

    protected:

    private:
};

#endif // MAIN_MENU_H
