#ifndef LAWN_H
#define LAWN_H
#include "Region.h"
#include "Sound.h"


class Lawn
{
    public:
        Lawn();
        SDL_Renderer *gRenderer;
        void set_Lawn(SDL_Renderer*);
        Region lawn_Tiles[5][9];     //lawn tiles array
        Region dummy_Region;
        bool inLawn(int,int);
        bool onLawn(int,int);
        Region return_tile(int,int);
        Region* uproot(int,int);
        int x_Lawn;
        int y_Lawn;

        Mix_Chunk* shove_sound = NULL;
        Sound shovel_plant;

        virtual ~Lawn();

    protected:

    private:
};

#endif // LAWN_H
