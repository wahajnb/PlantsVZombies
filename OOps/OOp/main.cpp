/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SDL, SDL_image, standard IO, and strings
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <stdio.h>
#include <string>
#include "screen_Image.h"
#include "Region.h"

//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

void update_Screen();

//Screen dimension constants
const int SCREEN_WIDTH = 1366;
const int SCREEN_HEIGHT = 768;

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;

//The texture
SDL_Texture* screen_Texture=NULL;

bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		//Create window
		gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_BORDERLESS );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Create renderer for window
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
			if( gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}
			}
		}
	}

	return success;
}


void update_Screen()
{


    //Render texture to screen
    SDL_RenderCopy( gRenderer, screen_Texture, NULL, NULL );

    //Update screen
    SDL_RenderPresent( gRenderer );

    SDL_RenderClear( gRenderer );

}

void close()
{

	//Destroy window
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;
	//Free loaded image
	SDL_DestroyTexture( screen_Texture );
	screen_Texture = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

int main( int argc, char* args[] )
{

	//Start up SDL and create window
	if( !init() )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{

		bool quit = false;              //  Main loop flag
		bool screen_flag = true;            // Splash Screen flag
		bool menu_flag = true;               // Main Menu flag
        int mouse_x;                //mouse x coordinates
        int mouse_y;                //mouse y coordinates

		int i=0;    //Splash screen Animation ending flag

		Region fu(gRenderer,0,0,1366,768);              //fullscreen
		Region ex(gRenderer,800,620,220,50);              //exitgame
		Region lo(gRenderer, 800, 550, 220, 50);              // loadgame
		Region ne(gRenderer,800, 480,220, 50);              //newgame

		int x_lawn=68;
		int y_lawn=85;
		Region *Lawn[5][9];                                 //lawn tiles
		for (int i=0; i<5; i++)
        {
            for (int j=0; j<9; j++)
            {
                Lawn[i][j] = new Region(gRenderer,x_lawn ,y_lawn ,137,128);
                x_lawn = x_lawn + 137;
            }
            x_lawn = 68;
            y_lawn = y_lawn + 128;
        }



		//Event handler
		SDL_Event e;

		screen_Image menu(gRenderer);
        menu.loadMedia("Menu Screen.png");     //Loading menu screen texture

        screen_Image yard(gRenderer);
        yard.loadMedia("Gifs/Lawn/Yard1.png");     //Loading back yard screen texture

        screen_Image new_Game(gRenderer);
        new_Game.loadMedia("Gifs/Menu Items/New Game1.png");   //Loading new game icon texture

        screen_Image new_GameOn(gRenderer);
        new_GameOn.loadMedia("Gifs/Menu Items/New Game On.png");   //Loading new game mouse on icon texture

        screen_Image new_GamePress(gRenderer);
        new_GamePress.loadMedia("Gifs/Menu Items/New Game Press.png");  //Loading new game button press texture

        screen_Image load_Game(gRenderer);
        load_Game.loadMedia("Gifs/Menu Items/Load Game1.png");  //Loading load game icon texture

        screen_Image load_GameOn(gRenderer);
        load_GameOn.loadMedia("Gifs/Menu Items/Load Game On.png");  //Loading load game mouse on icon texture

        screen_Image load_GamePress(gRenderer);
        load_GamePress.loadMedia("Gifs/Menu Items/Load Game Press.png");    //Loading load game button press texture

        screen_Image exit_Game(gRenderer);
        exit_Game.loadMedia("Gifs/Menu Items/Exit Game1.png");  //Loading exit game icon texture

        screen_Image exit_GameOn(gRenderer);
        exit_GameOn.loadMedia("Gifs/Menu Items/Exit Game On.png");  //Loading exit game mouse on icon texture

        screen_Image exit_GamePress(gRenderer);
        exit_GamePress.loadMedia("Gifs/Menu Items/Exit Game Press.png") ;//Loading exit game button press texture

        screen_Image light_Lawn(gRenderer);
        light_Lawn.loadMedia("Gifs/Grass/darkgrass.png");

        screen_Image dark_Lawn(gRenderer);
        dark_Lawn.loadMedia("Gifs/Grass/lightgrass.png");

        screen_Image splash[11];
	    for (int i=0; i<11; i++)
        {
            splash[i].ss_Rend = gRenderer;
        }

        bool load_On = false;
        bool exit_On = false;
        bool new_On = false;

        bool load_pressed = false;
        bool exit_pressed = false;
        bool new_pressed = false;

        // Initializing array of splash screens for the animation
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

			//While application is running
			while( !quit )
			{
			    if (screen_flag == true)        //Splash Screen Loop
                {
                    //Handle events on queue
                    while( SDL_PollEvent( &e ) != 0 )
                    {
                        //User requests quit
                        if( e.type == SDL_QUIT )
                        {
                            quit = true;
                        }
                    }

                    screen_Texture=splash[i].ss_Texture;    //Updates the current texture
                    update_Screen();

                    if (i==0)
                    {
                        SDL_Delay(3000);        //Delay for the first texture
                    }
                    else
                    {
                        SDL_Delay(30);
                    }
                    i++;
                    if (i>=10)
                    {
                        screen_flag = false;
                        //delete []splash;
                    }



                }
                else if (menu_flag == true)          //Main menu loop
                {
                    //Handle events on queue

                    fu.set_Viewport();
                    screen_Texture = menu.ss_Texture;
                    SDL_RenderCopy( gRenderer, screen_Texture, NULL, NULL );


                    ne.set_Viewport();
                    if (new_On == true)
                    {
                        if (new_pressed == true)
                        {
                            screen_Texture = new_GamePress.ss_Texture;
                            SDL_RenderCopy( gRenderer, screen_Texture, NULL, NULL );
                        }
                        else
                        {
                            screen_Texture = new_GameOn.ss_Texture;
                            SDL_RenderCopy( gRenderer, screen_Texture, NULL, NULL );
                        }

                    }
                    else if (new_On == false)
                    {
                        screen_Texture = new_Game.ss_Texture;
                        SDL_RenderCopy( gRenderer, screen_Texture, NULL, NULL );
                    }

                    lo.set_Viewport();
                    if (load_On == true)
                    {
                        if (load_pressed == true)
                        {
                            screen_Texture = load_GamePress.ss_Texture;
                            SDL_RenderCopy( gRenderer, screen_Texture, NULL, NULL );
                        }
                        else
                        {
                            screen_Texture = load_GameOn.ss_Texture;
                            SDL_RenderCopy( gRenderer, screen_Texture, NULL, NULL );
                        }

                    }
                    else if ( load_On == false)
                    {
                        screen_Texture = load_Game.ss_Texture;
                        SDL_RenderCopy( gRenderer, screen_Texture, NULL, NULL );
                    }


                    ex.set_Viewport();
                    if (exit_On == true)
                    {
                        if (exit_pressed == true)
                        {
                            screen_Texture = exit_GamePress.ss_Texture;
                            SDL_RenderCopy( gRenderer, screen_Texture, NULL, NULL );
                        }
                        else
                        {
                            screen_Texture = exit_GameOn.ss_Texture;
                            SDL_RenderCopy( gRenderer, screen_Texture, NULL, NULL );
                        }

                    }
                    else if (exit_On == false)
                    {
                        screen_Texture = exit_Game.ss_Texture;
                        SDL_RenderCopy( gRenderer, screen_Texture, NULL, NULL );
                    }



                    //Update screen
                    SDL_RenderPresent( gRenderer );
//                    SDL_Delay(500);
                    SDL_RenderClear( gRenderer );

                    if (new_pressed == true)
                    {
                        bool game_flag = true;
                        while(game_flag)
                        {
                            fu.set_Viewport();
                            screen_Texture=yard.ss_Texture;
                            SDL_RenderCopy( gRenderer, screen_Texture, NULL, NULL );



                            for (int i=0; i<5;i++)
                            {
                                for (int j=0; j<9;j++)
                                {
                                    Lawn[i][j]->set_Viewport();
                                    if(j%2==0 && i%2==0)
                                    {
                                        screen_Texture = dark_Lawn.ss_Texture;
                                    }

                                    else if (j%2!=0 && i%2==0)
                                    {
                                        screen_Texture = light_Lawn.ss_Texture;
                                    }

                                    else if (j%2==0 && i%2!=0)
                                    {
                                        screen_Texture = light_Lawn.ss_Texture;
                                    }

                                    else
                                    {
                                        screen_Texture = dark_Lawn.ss_Texture;
                                    }
                                    SDL_RenderCopy( gRenderer, screen_Texture, NULL, NULL );




                                }
                            }




                            SDL_RenderPresent( gRenderer );
                            SDL_RenderClear(gRenderer);
                            SDL_Delay(5000);
                            break;

                        }
                        new_pressed = false;
                    }

                    if (exit_pressed == true)
                    {
                        quit = true;
                    }



                    while( SDL_PollEvent( &e ) != 0 )
                    {
                        //User requests quit
                        if( e.type == SDL_QUIT )
                        {
                            quit = true;
                        }

                        else if (e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP)
                        {
                            SDL_GetMouseState(&mouse_x, &mouse_y);      // store mouse coordinates


                                if (ne.isOn(mouse_x, mouse_y) == true)
                                    {
                                        if(e.type == SDL_MOUSEBUTTONDOWN)
                                        {
                                            if(e.button.button == SDL_BUTTON_LEFT)
                                            {
                                                new_pressed = true;
                                                exit_pressed = false;
                                                load_pressed = false;
                                            }
                                        }
                                        else
                                        {
                                            new_On = true;
                                            load_On = false;
                                            exit_On = false;
                                            new_pressed = false;
                                        }

                                    }
                                else if (ex.isOn(mouse_x, mouse_y) == true)
                                    {
                                        if(e.type == SDL_MOUSEBUTTONDOWN)
                                        {
                                            if(e.button.button == SDL_BUTTON_LEFT)
                                            {
                                                exit_pressed = true;
                                                new_pressed = false;
                                                load_pressed = false;
                                            }
                                        }
                                        else
                                        {
                                            new_On = false;
                                            load_On = false;
                                            exit_On = true;;
                                            exit_pressed = false;
                                        }

                                    }
                                else if (lo.isOn(mouse_x, mouse_y) == true)
                                    {
                                        if(e.type == SDL_MOUSEBUTTONDOWN)
                                        {
                                            if(e.button.button == SDL_BUTTON_LEFT)
                                            {
                                                load_pressed = true;
                                                new_pressed = false;
                                                exit_pressed = false;
                                            }
                                        }
                                        else
                                        {
                                            new_On = false;
                                            load_On = true;
                                            exit_On = false;
                                            load_pressed = false;
                                        }

                                    }
                                else
                                    {
                                        new_On = false;
                                        load_On = false;
                                        exit_On = false;
                                    }



                            mouse_x=0;
                            mouse_y=0;


                        }
                    }

                }



		}
	}

	//Free resources and close SDL
	close();

	return 0;
}
