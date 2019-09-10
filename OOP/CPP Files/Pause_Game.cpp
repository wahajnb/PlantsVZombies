#include "Pause_Game.h"

Pause_Game::Pause_Game()
{
    //ctor
}

Pause_Game::~Pause_Game()
{
    //dtor
}

Pause_Game::Pause_Game(SDL_Renderer* r, SDL_Texture* t )
{
    gRenderer = r;
    gTexture = t;

    button_Press.set_Sound(press);
    button_Press.load_Sound("soundtracks/Buttonclick.wav");


    pauseMenu_Region.set_Coords(gRenderer, 476, 139,415,491);
    DoN_Region.set_Coords(gRenderer,572,395,220,50);
    saveGame_Region.set_Coords(gRenderer, 572,447, 220, 50);
    full_Screen.set_Coords(gRenderer,0,0,1366,768);                   //fullscreen
  //  resume_Game.set_Coords()

    pause_Menu.ss_Rend = gRenderer;
    pause_Menu.location = &pauseMenu_Region;
    pause_Menu.loadMedia("Gifs/Menu Items/Pause_Menu.png");     //Loading pause menu

    pause_Rect.ss_Rend = gRenderer;
    pause_Rect.location = &full_Screen;
    pause_Rect.loadMedia("Gifs/Menu Items/rect.png");

    saveGame_Button.ss_Rend = gRenderer;
    saveGame_Button.location = &saveGame_Region;
    saveGame_Button.loadMedia("Gifs/Menu Items/Save_game.png") ;    //Loading save game button texture

    saveGame_ButtonOn.ss_Rend = gRenderer;
    saveGame_ButtonOn.location = &saveGame_Region;
    saveGame_ButtonOn.loadMedia("Gifs/Menu Items/Save_game_On.png") ;    //Loading save game mouse on button texture

    saveGame_ButtonPress.ss_Rend = gRenderer;
    saveGame_ButtonPress.location = &saveGame_Region;
    saveGame_ButtonPress.loadMedia("Gifs/Menu Items/Save_game_press.png") ;    //Loading save game button press texture

    DoN_Button.ss_Rend = gRenderer;
    DoN_Button.location = &DoN_Region;
    DoN_Button.loadMedia("Gifs/Menu Items/Do Nothing.png");     //Loading do nothing button

    DoN_ButtonOn.ss_Rend = gRenderer;
    DoN_ButtonOn.location = &DoN_Region;
    DoN_ButtonOn.loadMedia("Gifs/Menu Items/Do Nothing On.png");     //Loading do nothing mouse on button

    DoN_ButtonPress.ss_Rend = gRenderer;
    DoN_ButtonPress.location = &DoN_Region;
    DoN_ButtonPress.loadMedia("Gifs/Menu Items/Do Nothing Press.png");     //Loading do nothing button press
}

void Pause_Game::display_PauseMenu()
{
    pause_Loop = true;
    pause_Rect.image_Render();
    while(pause_Loop)
    {

        while( SDL_PollEvent( &e ) != 0 )
        {

            pause_Menu.image_Render();
            if (e.type == SDL_QUIT)
            {
                pause_Loop = false;
            }

            else if (e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP )
            {
                SDL_GetMouseState(&mouse_x,&mouse_y);
                if (saveGame_Button.location->is_Pressed(mouse_x,mouse_y,e) == true)
                {
                    saveGame_ButtonPress.image_Render();
                    button_Press.play_Sound();
                    //game_Start->display_NewGame();
                }

                else if (saveGame_Button.location->isOn(mouse_x,mouse_y) == true)
                {
                    saveGame_ButtonOn.image_Render();
                }

                else
                {
                    saveGame_Button.image_Render();
                }

                if (DoN_Button.location->is_Pressed(mouse_x,mouse_y,e) == true)
                {
                    DoN_ButtonPress.image_Render();
                    button_Press.play_Sound();

                }

                else if (DoN_Button.location->isOn(mouse_x,mouse_y) == true)
                {
                    DoN_ButtonOn.image_Render();
                }

                else
                {
                    DoN_Button.image_Render();
                }

                if ((mouse_x > 55+476 && mouse_x < 363+476) && (mouse_y > 398+139 && mouse_y < 456+139) )
                {
                    if(e.type == SDL_MOUSEBUTTONDOWN)
                    {
                        if(e.button.button == SDL_BUTTON_LEFT)
                        {
                            pause_Loop = false;
                            button_Press.play_Sound();
                        }
                    }
                }

                 //Update screen
                SDL_RenderPresent( gRenderer );

                }
        }
    }

}
