#include "Sound.h"
#include <stdio.h>

Sound::Sound(Mix_Chunk *s)
{
    short_Sound = s;
}


Sound::~Sound()
{
    Mix_FreeChunk(short_Sound);
    short_Sound = NULL;
}

Sound::Sound()
{

}

void Sound::set_Sound(Mix_Chunk *s)
{
    short_Sound = s;
}


void Sound::load_Sound(string path)
{
    short_Sound = Mix_LoadWAV( path.c_str() );
    if( short_Sound == NULL )
    {
        printf(path.c_str());
        printf( "Failed to load scratch sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
    }

}

void Sound::play_Sound()
{
    Mix_PlayChannel( -1, short_Sound, 0 );
}
