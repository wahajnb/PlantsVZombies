#include "New_Game.h"

New_Game::New_Game()
{
    //ctor
}


New_Game::New_Game(SDL_Renderer* r, SDL_Texture* t)
{
    gRenderer = r;
    gTexture = t;

    total_suns = 0;

    game_Music.set_Music(gMusic,320);
    game_Music.load_Music("soundtracks/day_soundtrack.wav");

    s_count.load_Media(gRenderer,gTexture);

    game_Loop =  true;

    peaPlant_Carry = false;
    sunFlower_Carry = false;
    chomper_Carry = false;

    p_Card.load_Media(gRenderer,gTexture);
    s_Card.load_Media(gRenderer,gTexture);
    c_Card.load_Media(gRenderer,gTexture);

    full_Screen.set_Coords(gRenderer,0,0,1366,768);                   //fullscreen
    seed_Slot.set_Coords(gRenderer, 10, 0, 600, 120);                 //Seed Slot
    shovel_Slot.set_Coords(gRenderer,640,0,90,95);                  //Shovel slot
    pausegame_Region.set_Coords(gRenderer, 1300, 0, 60, 60);  	    //pausegame

    pauseGame_Button.ss_Rend = gRenderer;
    pauseGame_Button.location = &pausegame_Region;
    pauseGame_Button.loadMedia("Gifs/Menu Items/pause.png");         //Loading pause game button texture

    pauseGame_ButtonOn.ss_Rend = gRenderer;
    pauseGame_ButtonOn.location = &pausegame_Region;
    pauseGame_ButtonOn.loadMedia("Gifs/Menu Items/pause_game_on.png");         //Loading pause game button texture

    yard.ss_Rend = gRenderer;
    yard.location=&full_Screen;
    yard.loadMedia("Gifs/Lawn/yard.png");     //Loading back yard screen texture

    slot_area.ss_Rend = gRenderer;
    slot_area.location = &seed_Slot;
    slot_area.loadMedia("Gifs/Plants packet/SeedBank.png");     //Loading seed slot texture

}

New_Game::~New_Game()
{
    //dtor
}

void New_Game::display_NewGame()
{
    game_Loop = true;
    while(game_Loop)
    {
            SDL_PollEvent( &e );
            game_Music.play_Music();

            yard.image_Render();
            slot_area.image_Render();
            pauseGame_Button.image_Render();
            p_Card.display_Card();
            s_Card.display_Card();
            c_Card.display_Card();

            s_count.set_Suns(total_suns);
            if (e.type == SDL_QUIT)
            {
                game_Loop = false;
            }

            else if (e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP )
            {

                SDL_GetMouseState(&mouse_x,&mouse_y);
                if (pauseGame_Button.location->is_Pressed(mouse_x,mouse_y,e) == true)
                {
                  //  button_Press.play_Sound();
                  p_Menu->display_PauseMenu();
                }

                else if (pauseGame_Button.location->isOn(mouse_x,mouse_y) == true)
                {
                    pauseGame_ButtonOn.image_Render();
                }

                else
                {
                    pauseGame_Button.image_Render();
                }


            }






            //Update screen
            SDL_RenderPresent( gRenderer );

            //Clears the renderer
            SDL_RenderClear( gRenderer );



    }
}
