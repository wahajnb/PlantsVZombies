#ifndef PAUSE_GAME_H
#define PAUSE_GAME_H
#include "screen_Image.h"
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <stdio.h>
#include "Sound.h"

class Pause_Game
{
    public:
        Pause_Game();
        Pause_Game(SDL_Renderer*, SDL_Texture* );

        SDL_Renderer* gRenderer;
        SDL_Texture* gTexture;

        Region pauseMenu_Region;         //Pausemenu
        Region DoN_Region;         //Do nothing button
        Region saveGame_Region;       //savegame380
        Region full_Screen;
        //Region resume_Game;

        screen_Image saveGame_Button;
        screen_Image saveGame_ButtonOn;
        screen_Image saveGame_ButtonPress;
        screen_Image pause_Menu;
        screen_Image DoN_Button;
        screen_Image DoN_ButtonOn;
        screen_Image DoN_ButtonPress;
        screen_Image pause_Rect;

        Mix_Chunk* press = NULL;
        Sound button_Press;

        SDL_Event e;

        int mouse_x;
        int mouse_y;


        void display_PauseMenu();
        bool pause_Loop;


        virtual ~Pause_Game();

    protected:

    private:
};

#endif // PAUSE_GAME_H
