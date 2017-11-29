#include "Main_Menu.h"

Main_Menu::Main_Menu(SDL_Renderer* r, SDL_Texture* t)
{
    gRenderer = r;
    gTexture = t;

    mainMenu_Music.set_Music(gMusic,100);
    mainMenu_Music.load_Music("soundtracks/Main menu sound track.wav");

    button_Press.set_Sound(press);
    button_Press.load_Sound("soundtracks/Buttonclick.wav");

    mainMenu_Loop = true;

    full_Screen.set_Coords(gRenderer,0,0,1366,768);                   //fullscreen
    exitGame_Region.set_Coords(gRenderer,800,620,220,50);                //exitgame
    loadGame_Region.set_Coords(gRenderer, 800, 550, 220, 50);            // loadgame
    newGame_Region.set_Coords(gRenderer,800, 480,220, 50);              //newgame

    menu_Screen.ss_Rend = gRenderer;
    menu_Screen.location = &full_Screen;
    menu_Screen.loadMedia("Gifs/Menu Items/Menu Screen.png");     //Loading menu screen texture)

    newGame_Button.ss_Rend = gRenderer;
    newGame_Button.location=&newGame_Region;
    newGame_Button.loadMedia("Gifs/Menu Items/New Game1.png");   //Loading new game icon texture

    newGame_ButtonOn.ss_Rend = gRenderer;
    newGame_ButtonOn.location=&newGame_Region;
    newGame_ButtonOn.loadMedia("Gifs/Menu Items/New Game On.png");   //Loading new game mouse on icon texture

    newGame_ButtonPress.ss_Rend = gRenderer;
    newGame_ButtonPress.location=&newGame_Region;
    newGame_ButtonPress.loadMedia("Gifs/Menu Items/New Game Press.png");   //Loading new game button pressed icon texture

    loadGame_Button.ss_Rend = gRenderer;
    loadGame_Button.location = &loadGame_Region;
    loadGame_Button.loadMedia("Gifs/Menu Items/Load Game1.png");  //Loading load game icon texture

    loadGame_ButtonOn.ss_Rend = gRenderer;
    loadGame_ButtonOn.location = &loadGame_Region;
    loadGame_ButtonOn.loadMedia("Gifs/Menu Items/Load Game On.png");    //Loading load game button mouse on texture

    loadGame_ButtonPress.ss_Rend = gRenderer;
    loadGame_ButtonPress.location = &loadGame_Region;
    loadGame_ButtonPress.loadMedia("Gifs/Menu Items/Load Game Press.png");     //Loading load game button press texture

    exitGame_Button.ss_Rend = gRenderer;
    exitGame_Button.location = &exitGame_Region;
    exitGame_Button.loadMedia("Gifs/Menu Items/Exit Game1.png");  //Loading exit game icon texture

    exitGame_ButtonOn.ss_Rend = gRenderer;
    exitGame_ButtonOn.location = &exitGame_Region;
    exitGame_ButtonOn.loadMedia("Gifs/Menu Items/Exit Game On.png");  //Loading exit game mouse on icon texture

    exitGame_ButtonPress.ss_Rend = gRenderer;
    exitGame_ButtonPress.location = &exitGame_Region;
    exitGame_ButtonPress.loadMedia("Gifs/Menu Items/Exit Game Press.png") ;//Loading exit game button press texture



}

Main_Menu::~Main_Menu()
{
    //dtor
}

void Main_Menu::display_MainMenu()
{
    mainMenu_Loop = true;
    while(mainMenu_Loop == true)
    {

        mainMenu_Music.play_Music();
        while( SDL_PollEvent( &e ) != 0 )
        {
            if (e.type == SDL_QUIT)
            {
                mainMenu_Loop = false;
            }

            else if (e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP )
            {

                SDL_GetMouseState(&mouse_x,&mouse_y);

                menu_Screen.image_Render();

                if (newGame_Button.location->is_Pressed(mouse_x,mouse_y,e) == true)
                {
                    newGame_ButtonPress.image_Render();
                    button_Press.play_Sound();
                    game_Start->display_NewGame();
                    menu_Screen.image_Render();
                    newGame_Button.image_Render();
                }

                else if (newGame_Button.location->isOn(mouse_x,mouse_y) == true)
                {
                    newGame_ButtonOn.image_Render();
                }

                else
                {
                    newGame_Button.image_Render();
                }

                if (loadGame_Button.location->is_Pressed(mouse_x,mouse_y,e) == true)
                {
                    loadGame_ButtonPress.image_Render();
                    button_Press.play_Sound();
                }

                else if (loadGame_Button.location->isOn(mouse_x,mouse_y) == true)
                {
                    loadGame_ButtonOn.image_Render();
                }

                else
                {
                    loadGame_Button.image_Render();
                }

                if (exitGame_Button.location->is_Pressed(mouse_x,mouse_y,e) == true)
                {
                    exitGame_ButtonPress.image_Render();
                    button_Press.play_Sound();
                    mainMenu_Loop = false;
                }

                else if (exitGame_Button.location->isOn(mouse_x,mouse_y) == true)
                {
                    exitGame_ButtonOn.image_Render();
                }

                else
                {
                    exitGame_Button.image_Render();
                }

                 //Update screen
                SDL_RenderPresent( gRenderer );

                //Clears the renderer
                SDL_RenderClear( gRenderer );

            }
        }
    }


}
