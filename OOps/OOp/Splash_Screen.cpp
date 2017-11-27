#include "Splash_Screen.h"

Splash_Screen::Splash_Screen(SDL_Renderer* r, SDL_Texture* t)
{
    gRenderer = r;
    gTexture = t;
    full_Screen.set_Coords(gRenderer,0,0,1366,768);
    for (int i=0; i<11; i++)
    {
        splash[i].ss_Rend = gRenderer;      //Initializing splash screens
        splash[i].location = &full_Screen;
    }

    // Loading splash screens textures for the animation
    splash[0].loadMedia("Splash Screen/Splash 1.png ");
    splash[1].loadMedia("Splash Screen/Splash 2.png ");
    splash[2].loadMedia("Splash Screen/Splash 3.png ");
    splash[3].loadMedia("Splash Screen/Splash 4.png ");
    splash[4].loadMedia("Splash Screen/Splash 5.png ");
    splash[5].loadMedia("Splash Screen/Splash 6.png ");
    splash[6].loadMedia("Splash Screen/Splash 7.png ");
    splash[7].loadMedia("Splash Screen/Splash 8.png ");
    splash[8].loadMedia("Splash Screen/Splash 9.png ");
    splash[9].loadMedia("Splash Screen/Splash 10.png ");
    splash[10].loadMedia("Splash Screen/Splash 11.png ");

}

Splash_Screen::~Splash_Screen()
{
    //dtor
}

void Splash_Screen::splash_Display()
{
    for (int i =0 ; i< 11; i++)
    {
        //Copies the texture to the renderer
        splash[i].image_Render();

        //Update screen
        SDL_RenderPresent( gRenderer );

        //Clears the renderer
        SDL_RenderClear( gRenderer );

        if (i==0)
        {
            SDL_Delay(3000);               //Delay for the first texture of splash screen
        }
        else
        {
            SDL_Delay(30);                  //Delay for rest of the textures
        }
    }

}
