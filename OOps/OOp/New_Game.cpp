#include "New_Game.h"

New_Game::New_Game()
{
    //ctor
}

New_Game::New_Game(SDL_Renderer* r, SDL_Texture* t)
{
    gRenderer= r;
    gTexture = t;

    plant_Place.set_Sound(psound);
    plant_Place.load_Sound("Soundtracks/plant_placement.wav");

    front_Yard.set_Lawn(gRenderer);

    total_suns = 1000;

    game_Music.set_Music(gMusic,320);
    game_Music.load_Music("soundtracks/day_soundtrack.wav");

    s_count.load_Media(gRenderer,gTexture);

    game_Loop =  true;

    peaPlant_Carry = false;
    sunFlower_Carry = false;
    chomper_Carry = false;
    shovel_Carry = false;

    p_Card.load_Media(gRenderer,gTexture);
    s_Card.load_Media(gRenderer,gTexture);
    c_Card.load_Media(gRenderer,gTexture);

    full_Screen.set_Coords(gRenderer,0,0,1366,768);                   //fullscreen
    seed_Slot.set_Coords(gRenderer, 10, 0, 600, 120);                 //Seed Slot
    shovel_Slot.set_Coords(gRenderer,610,0,90,95);                  //Shovel slot
    pausegame_Region.set_Coords(gRenderer, 1300, 0, 60, 60);  	    //pausegame
    peaplant_root.set_Coords(gRenderer,203, 10, 120,114);
    sunflower_root.set_Coords(gRenderer,120,10,120,114);
    chomper_root.set_Coords(gRenderer,283,10,120,114);
    temp_shovel.set_Coords(gRenderer,610,0,90,95);

    shovel_card.ss_Rend = gRenderer;
    shovel_card.location = &shovel_Slot;
    shovel_card.loadMedia("Gifs/Plants packet/Shovel.png");     //Loading shovel's slot texture

    shovel.ss_Rend = gRenderer;
    shovel.location = &temp_shovel;
    shovel.loadMedia("Gifs/plant rooting/shovel.png");     //Loading shovel's texture

    pauseGame_Button.ss_Rend = gRenderer;
    pauseGame_Button.location = &pausegame_Region;
    pauseGame_Button.loadMedia("Gifs/Menu Items/pause.png");         //Loading pause game button texture

    peaplant_rooting.ss_Rend = gRenderer;
    peaplant_rooting.location = &peaplant_root;
    peaplant_rooting.loadMedia("Gifs/plant rooting/pea_Plant1.png");

    sunflower_rooting.ss_Rend = gRenderer;
    sunflower_rooting.location = &sunflower_root;
    sunflower_rooting.loadMedia("Gifs/plant rooting/sun_Plant.png");

    chomper_rooting.ss_Rend = gRenderer;
    chomper_rooting.location = &chomper_root;
    chomper_rooting.loadMedia("Gifs/plant rooting/chomper.png");

    pauseGame_ButtonOn.ss_Rend = gRenderer;
    pauseGame_ButtonOn.location = &pausegame_Region;
    pauseGame_ButtonOn.loadMedia("Gifs/Menu Items/pause_game_on.png");         //Loading pause game button texture

    yard.ss_Rend = gRenderer;
    yard.location=&full_Screen;
    yard.loadMedia("Gifs/Lawn/yard.png");     //Loading back yard screen texture

    slot_area.ss_Rend = gRenderer;
    slot_area.location = &seed_Slot;
    slot_area.loadMedia("Gifs/Plants packet/SeedBank.png");     //Loading seed slot texture

    a.sun_setcoord(gRenderer);

    if( !SunflowerTexture.LoadFromFile( "Gifs/Sunflower/Sunflower.png", gRenderer  ) )
	{
		printf( "Failed to load sunflower texture!\n" );

	}
	if( !PeaShooterTexture.LoadFromFile( "Gifs/Pea plant/Pea Shooter.png", gRenderer  ) )
	{
		printf( "Failed to load pea shooter texture!\n" );

	}
	if( !SunningTexture.LoadFromFile( "Gifs/Sunflower/Sunning.png", gRenderer  ) )
	{
		printf( "Failed to load sunning texture!\n" );

	}
	if( !ChomperTexture.LoadFromFile( "Gifs/Chomper/Chomper moving.png", gRenderer  ) )
	{
		printf( "Failed to load chomper moving texture!\n" );

	}
	if( !EatingTexture.LoadFromFile( "Gifs/Chomper/ChomperEat.png", gRenderer  ) )
	{
		printf( "Failed to load eating texture!\n" );

	}

    s_List.get_Renderer(gRenderer);
    pp_List.get_Renderer(gRenderer);
    c_List.get_Renderer(gRenderer);

}

New_Game::~New_Game()
{
    //dtor
}

bool New_Game::display_NewGame()
{
    game_Loop = true;

    while(game_Loop)
    {

            SDL_PollEvent( &e );
            game_Music.play_Music();
            a.produce_Sun();
            yard.image_Render();
            slot_area.image_Render();
            pauseGame_Button.image_Render();
            p_Card.display_Card();
            s_Card.display_Card();
            c_Card.display_Card();

            shovel_card.image_Render();

            if (a.show_Sun() == true)
            {
                total_suns = total_suns + 25;
            }

            s_count.set_Suns(total_suns);
            if (e.type == SDL_QUIT)
            {
                game_Loop = false;
                return false;
            }

            else if (e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP )
            {

                SDL_GetMouseState(&mouse_x,&mouse_y);
                a.collect_Sun(mouse_x,mouse_y, e);

                if (pauseGame_Button.location->is_Pressed(mouse_x,mouse_y,e) == true)
                {
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

                if(p_Card.card_Region.is_Pressed(mouse_x,mouse_y,e) && p_Card.on_Cooldown == false && p_Card.sun_required <= total_suns )
                {
                    peaPlant_Carry = true;
                }

                else if (s_Card.card_Region.is_Pressed(mouse_x,mouse_y,e) && s_Card.on_Cooldown == false && s_Card.sun_required <=total_suns)
                {
                    sunFlower_Carry = true;
                }

                else if(c_Card.card_Region.is_Pressed(mouse_x,mouse_y,e) && c_Card.on_Cooldown == false && c_Card.sun_required <= total_suns)
                {
                    chomper_Carry = true;
                }

                else if (shovel_Slot.is_Pressed(mouse_x,mouse_y,e))
                {
                    shovel_Carry = true;
                }


                if (peaPlant_Carry == true)
                {
                    if(e.type == SDL_MOUSEMOTION)
                    {
                        peaplant_root.area.x = mouse_x-50;
                        peaplant_root.area.y = mouse_y-50;
                        peaplant_rooting.image_Render();
                    }
                    else if (e.type == SDL_MOUSEBUTTONUP)
                    {
                        peaPlant_Carry = false;

                        if(front_Yard.onLawn(mouse_x,mouse_y) == true)
                        {
                            temp_plantRegion = front_Yard.return_tile(mouse_x,mouse_y);
                            PeaShooter* p = new PeaShooter(gRenderer, &PeaShooterTexture, temp_plantRegion.area.x+10, temp_plantRegion.area.y+10);
                            pp_List.add_peaPlant(p);
                            p_Card.on_Cooldown = true;
                            total_suns = total_suns - p_Card.sun_required;
                            plant_Place.play_Sound();
                        }
                    }
                }

                else if (sunFlower_Carry == true)
                {
                    if(e.type == SDL_MOUSEMOTION)
                    {
                        sunflower_root.area.x = mouse_x-50;
                        sunflower_root.area.y = mouse_y-50;
                        sunflower_rooting.image_Render();
                    }
                    else if (e.type == SDL_MOUSEBUTTONUP)
                    {
                        sunFlower_Carry = false;

                        if(front_Yard.onLawn(mouse_x,mouse_y) == true)
                        {
                           // plant_drop = true;
                            temp_plantRegion = front_Yard.return_tile(mouse_x,mouse_y);
                            Sunflower *g = new Sunflower(gRenderer,&SunflowerTexture, &SunningTexture, temp_plantRegion.area.x+10, temp_plantRegion.area.y);
                            s_List.add_Sunflower(g);
                            s_Card.on_Cooldown = true;
                            total_suns = total_suns - s_Card.sun_required;
                            plant_Place.play_Sound();
                        }
                    }
                }

                else if (chomper_Carry == true)
                {
                    if(e.type == SDL_MOUSEMOTION)
                    {
                        chomper_root.area.x = mouse_x-50;
                        chomper_root.area.y = mouse_y-50;
                        chomper_rooting.image_Render();
                    }
                    else if (e.type == SDL_MOUSEBUTTONUP)
                    {
                        chomper_Carry = false;
                        if(front_Yard.onLawn(mouse_x,mouse_y) == true)
                        {
                            temp_plantRegion = front_Yard.return_tile(mouse_x,mouse_y);
                            Chomper *c = new Chomper(gRenderer, &ChomperTexture, &EatingTexture, temp_plantRegion.area.x+10, temp_plantRegion.area.y);
                            c_List.add_chomper(c);
                            c_Card.on_Cooldown = true;
                            total_suns = total_suns - c_Card.sun_required;
                            plant_Place.play_Sound();

                        }
                    }
                }

                else if (shovel_Carry == true)
                {
                    if(e.type == SDL_MOUSEMOTION)
                    {
                        temp_shovel.area.x = mouse_x-50;
                        temp_shovel.area.y = mouse_y-50;
                        shovel.image_Render();
                    }
                    else if (e.type == SDL_MOUSEBUTTONUP)
                    {
                        shovel_Carry = false;
                        if(front_Yard.inLawn(mouse_x,mouse_y) == true)
                        {
                            temp_plantShove = NULL;
                            temp_plantShove = front_Yard.uproot(mouse_x,mouse_y);
                            pp_List.del_plant(temp_plantRegion.area.x, temp_plantRegion.area.y);
                            cout <<"bro" << endl;
                        }
                    }
                }
            }

            full_Screen.set_Viewport();
            s_List.display();
            pp_List.display();
            c_List.display();

            //Update screen
            SDL_RenderPresent( gRenderer );

            //Clears the renderer
            SDL_RenderClear( gRenderer );



    }
    return false;
}
