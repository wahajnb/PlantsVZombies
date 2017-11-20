#ifndef SOUND_H
#define SOUND_H
#include <SDL_mixer.h>
#include <iostream>
using namespace std;


class Sound         //For loading sounds
{
    public:
        Sound(Mix_Chunk *);
        virtual ~Sound();
        Mix_Chunk *short_Sound;
        void load_Sound(string);
        void play_Sound();

    protected:

    private:
};

#endif // SOUND_H
