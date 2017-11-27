//Including the headers the program is going to use
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include "screen_Image.h"
#include "Region.h"
#include "Text_Image.h"
#include "Music.h"
#include "Sound.h"
#include "Splash_Screen.h"
#include "Main_Menu.h"
#include "New_Game.h"
#include "peaPlant_Card.h"
#include "Pause_Game.h"


//Starts up SDL and creates window
bool init();

//Frees media and shuts down SDL
void close();

// Updates the screen
void update_Screen();

//Screen dimension constants
const int SCREEN_WIDTH = 1366;
const int SCREEN_HEIGHT = 768;

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;

//The texture to store texture
SDL_Texture* screen_Texture=NULL;

//The font to be used
TTF_Font* roboto_Font = NULL;

//Sound effects that will be used
Mix_Music *gMusic = NULL;
Mix_Chunk *bpress_Music = NULL;

//The color to be used
SDL_Color black_color ;

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
		gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_FULLSCREEN_DESKTOP );
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

				//Initialize SDL_mixer
                if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
                {
                    printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
                    success = false;
                }

				//Initialize SDL_ttf
				if( TTF_Init() == -1 )
				{
					printf( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() );
					success = false;
				}

				roboto_Font= TTF_OpenFont("Fonts/Roboto/Roboto-Bold.ttf", 100);         //Initializing roboto font

                if( roboto_Font == NULL )
                {
                    printf( "Failed to load roboto font! SDL_ttf Error: %s\n", TTF_GetError() );
                    success = false;
                }
                else
                {
                    black_color = { 0, 0, 0 };          //Initializing color

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

    //Clears the renderer
    SDL_RenderClear( gRenderer );

}

void close()
{
    //Free global font
    TTF_CloseFont( roboto_Font );
	roboto_Font = NULL;

	//Free the sound effects
	Mix_FreeChunk(bpress_Music);
	bpress_Music = NULL;

	//Free the music
	Mix_FreeMusic(gMusic);
	gMusic = NULL;

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
	TTF_Quit();
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
	    //Loading Main menu music
        Splash_Screen h(gRenderer,screen_Texture);
        Main_Menu m(gRenderer,screen_Texture);
        New_Game n(gRenderer,screen_Texture);
        Pause_Game p(gRenderer,screen_Texture);
       // peaPlant_Card p(gRenderer,screen_Texture);
        m.game_Start = &n;
        n.p_Menu = &p;


        h.splash_Display();
        m.display_MainMenu();


	}
}


