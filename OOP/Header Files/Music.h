#ifndef MUSIC_H
#define MUSIC_H
#include <time.h>
#include <SDL_mixer.h>
#include <iostream>
using namespace std;

class Music             //For loading music
{
    public:
        Music(Mix_Music *, time_t);
        Music();
        virtual ~Music();
        time_t start_Time;
        time_t end_Time;
        time_t music_length;
        Mix_Music *music_Audio;
        void load_Music (string);
        void play_Music ();
        void replay();
        void set_Music(Mix_Music *m, time_t l);
        bool music_On;

    protected:

    private:
};

#endif // MUSIC_H
