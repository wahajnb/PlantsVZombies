#include "Music.h"
#include <stdio.h>

Music::Music(Mix_Music *m, time_t l)
{
    music_Audio = m;
    music_length = l;
    music_On = false;

}

void Music::set_Music(Mix_Music *m, time_t l)
{
    music_Audio = m;
    music_length = l;
    music_On = false;

}

Music::Music()
{

}

Music::~Music()
{
    //dtor
}

void Music::load_Music(string path)
{
    music_Audio = Mix_LoadMUS( path.c_str() );
    if( music_Audio == NULL )
    {
        printf(path.c_str());
        printf( "Failed to load main menu sound track! SDL_mixer Error: %s\n", Mix_GetError() );
    }
}

void Music::play_Music()
{
    if (music_On == false)          // Conditions to stop playing music from the start
    {
        Mix_PlayMusic( music_Audio, -1 );
        music_On = true;
        start_Time = time(NULL);
        end_Time = start_Time + music_length;
    }
    else
    {
        if (start_Time > end_Time)
        {
            music_On = false;
        }
    }

}

void Music::replay()        //Plays music from the start
{
    Mix_PlayMusic( music_Audio, -1 );
}
