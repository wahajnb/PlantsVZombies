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
        Music mainMenu_Music (gMusic,100);
        mainMenu_Music.load_Music("soundtracks/Main menu sound track.wav");

        //Loading In Game music
        Music game_Music (gMusic,320);
        game_Music.load_Music("soundtracks/day_soundtrack.wav");

        //Loading button click sound
        Sound button_ClickMusic (bpress_Music);
        button_ClickMusic.load_Sound("soundtracks/Buttonclick.wav");

        int suns_Num = 0;               // Number of suns the user have
        string str_SunNum;              // Total number of suns string

		bool quit = false;              //  Main loop flag
		bool screen_flag = true;        // Splash Screen flag
		bool menu_flag = true;          // Main Menu flag
        int mouse_x;                   //mouse x coordinates
        int mouse_y;                  //mouse y coordinates

		int i=0;    //Splash screen Animation ending flag

		Region fu(gRenderer,0,0,1366,768);                   //fullscreen
		Region ex(gRenderer,800,620,220,50);                //exitgame
		Region lo(gRenderer, 800, 550, 220, 50);            // loadgame
		Region ne(gRenderer,800, 480,220, 50);              //newgame
        Region sslot(gRenderer, 40, 0, 600, 120);           //Seed Slot
        Region sunslot(gRenderer, 150, 10, 73, 100 );       //Sunflower slot
        Region pslot (gRenderer, 233, 10, 73,100);          //Pea plant slot
        Region chompslot (gRenderer, 313, 10, 73,100);      //chomper plant slot
        Region shovelslot (gRenderer,640,0,90,95);          //Shovel slot
        Region scount_1Digit (gRenderer,85,85,14,28);       //Sun count 1 digit slot
        Region scount_2Digit (gRenderer,80,85,24,28);       //Sun count 2 digit slot
        Region scount_3Digit (gRenderer,74,85,35,28);       //Sun count 3 digit slot

		int x_lawn=68;          //starting x-coordinate of 1st tile
		int y_lawn=100;         //starting y-coordinate of 1st tile
		Region *Lawn[5][9];     //lawn tiles array
		for (int i=0; i<5; i++)
        {
            for (int j=0; j<9; j++)
            {
                Lawn[i][j] = new Region(gRenderer,x_lawn ,y_lawn ,137,128);     //Initializing lawn tiles
                x_lawn = x_lawn + 137;
            }
            x_lawn = 68;
            y_lawn = y_lawn + 128;
        }


		//Event handler
		SDL_Event e;

		screen_Image menu(gRenderer);
        menu.loadMedia("Gifs/Menu Items/Menu Screen.png");     //Loading menu screen texture

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
        light_Lawn.loadMedia("Gifs/Grass/lightgrass.png");      //Loading light grass texture for tiles

        screen_Image dark_Lawn(gRenderer);
        dark_Lawn.loadMedia("Gifs/Grass/darkgrass.png");        //Loading dark grass texture for tiles

        screen_Image seed_Slot(gRenderer);
        seed_Slot.loadMedia("Gifs/Plants packet/SeedBank.png"); //Loading seed slot texture

        screen_Image pea_Plantcard(gRenderer);
        pea_Plantcard.loadMedia("Gifs/Plants packet/Peashooter_HD_Seed.png");   //Loading pea's plant card texture

        screen_Image sun_Plantcard(gRenderer);
        sun_Plantcard.loadMedia("Gifs/Plants packet/Sunflower_HD_Seed.png");    //Loading sunflower's plant card texture

        screen_Image chomper_plantcard(gRenderer);
        chomper_plantcard.loadMedia("Gifs/Plants packet/Chomper_Seed.png");     //Loading chomper's plant card texture

        screen_Image shovel_card(gRenderer);
        shovel_card.loadMedia("Gifs/Plants packet/Shovel.png");     //Loading shovel's slot texture

        Text_Image sun_count(gRenderer);        //Loading sun count texture

        screen_Image splash[11];                //Array for splash screen animation
	    for (int i=0; i<11; i++)
        {
            splash[i].ss_Rend = gRenderer;      //Initializing splash sreens
        }

        bool load_On = false;           //Bool telling whether the mouse is on load button
        bool exit_On = false;           //Bool telling whether the mouse is on exit button
        bool new_On = false;            //Bool telling whether the mouse is on newgame button

        bool load_pressed = false;      //Bool telling whether the load button is pressed
        bool exit_pressed = false;      //Bool telling whether the exit button is pressed
        bool new_pressed = false;       //Bool telling whether the new game button is pressed

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

			//While application is running
			while( !quit )
			{
			    if (screen_flag == true)             //Splash Screen Loop
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
                        SDL_Delay(3000);               //Delay for the first texture of splash screen
                    }
                    else
                    {
                        SDL_Delay(30);                  //Delay for rest of the textures
                    }
                    i++;
                    if (i>=10)                          //Checking if animation textures have ended
                    {
                        screen_flag = false;
                    }

                }

                else if (menu_flag == true)            //Main menu loop
                {
                    mainMenu_Music.play_Music();        //Plays main menu music

                    fu.set_Viewport();         //Sets the viewport for full screen
                    screen_Texture = menu.ss_Texture;
                    SDL_RenderCopy( gRenderer, screen_Texture, NULL, NULL );


                    ne.set_Viewport();          //Sets the viewport for new game button
                    if (new_On == true)         //Checks if the mouse is on the new button
                    {
                        if (new_pressed == true)    //Checks whether the new game button is pressed
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

                    lo.set_Viewport();          //Sets the view port for load game button
                    if (load_On == true)       //Checks if the mouse is on the load game button
                    {
                        if (load_pressed == true)       //Checks if the load game button is being pressed
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


                    ex.set_Viewport();      //Sets the view port for exit game button
                    if (exit_On == true)    //Checks if the mouse is on the exit gamr button
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


                    update_Screen();

                    if (new_pressed == true)            //Runs a new game;
                    {
                        bool game_flag = true;          //For checking when to go out of the game to main menu
                        game_Music.replay();            //Plays game music from the start
                        while(game_flag)                //New game loop
                        {
                            game_Music.play_Music();      //Plays Music

                            for (int i=0; i<5;i++)          //Condition to choose the texture for each tile
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

                            sslot.set_Viewport();                   //Set viewport for seed slot
                            screen_Texture = seed_Slot.ss_Texture;
                            SDL_RenderCopy( gRenderer, screen_Texture, NULL, NULL );

                            sunslot.set_Viewport();                 //Set viewport for sunplant card
                            screen_Texture = sun_Plantcard.ss_Texture;
                            SDL_RenderCopy( gRenderer, screen_Texture, NULL, NULL );

                            pslot.set_Viewport();                   //Set viewport for pea plant card
                            screen_Texture = pea_Plantcard.ss_Texture;
                            SDL_RenderCopy( gRenderer, screen_Texture, NULL, NULL );

                            chompslot.set_Viewport();               //Set viewport for chomper plant card
                            screen_Texture = chomper_plantcard.ss_Texture;
                            SDL_RenderCopy( gRenderer, screen_Texture, NULL, NULL );

                            shovelslot.set_Viewport();              ////Set viewport for shovel
                            screen_Texture = shovel_card.ss_Texture;
                            SDL_RenderCopy( gRenderer, screen_Texture, NULL, NULL );

                            //Converts the int sun_count to string sun_count to render on screen
                            stringstream ss;
                            ss << suns_Num;
                            str_SunNum = ss.str();

                            if (suns_Num>=0 && suns_Num<10)     //Condition for setting viewport for 1-digit sun count
                            {
                                scount_1Digit.set_Viewport();
                                screen_Texture = sun_count.loadMedia(str_SunNum,black_color,roboto_Font);
                                SDL_RenderCopy( gRenderer, screen_Texture, NULL, NULL );
                            }

                            else if (suns_Num>=10 && suns_Num <100)     //Condition for setting viewport for 2-digit sun count
                            {
                                scount_2Digit.set_Viewport();
                                screen_Texture = sun_count.loadMedia(str_SunNum,black_color,roboto_Font);
                                SDL_RenderCopy( gRenderer, screen_Texture, NULL, NULL );
                            }

                            else       //Condition for setting viewport for 3-digit sun count
                            {
                                scount_3Digit.set_Viewport();
                                screen_Texture = sun_count.loadMedia(str_SunNum,black_color,roboto_Font);
                                SDL_RenderCopy( gRenderer, screen_Texture, NULL, NULL );
                            }

                            update_Screen();        //Updates the screen
                            SDL_Delay(7000);        //Delay for testinf

                            break;
                        }

                        new_pressed = false;
                        mainMenu_Music.replay();        //Starts main menu music from the beginning
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
                            SDL_GetMouseState(&mouse_x, &mouse_y);                   // store mouse coordinates

                                if (ne.isOn(mouse_x, mouse_y) == true)
                                    {
                                        if(e.type == SDL_MOUSEBUTTONDOWN)
                                        {
                                            button_ClickMusic.play_Sound();         //Plays click sounds
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
                                            button_ClickMusic.play_Sound();         //Plays click sound
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
                                            button_ClickMusic.play_Sound();     //Plays click sound
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
