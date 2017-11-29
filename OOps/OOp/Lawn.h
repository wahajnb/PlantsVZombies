#ifndef LAWN_H
#define LAWN_H
#include "Region.h"


class Lawn
{
    public:
        Lawn();
        SDL_Renderer *gRenderer;
        void set_Lawn(SDL_Renderer*);
        Region lawn_Tiles[5][9];     //lawn tiles array
        bool onLawn(int,int);
        Region return_tile(int,int);
        int x_Lawn;
        int y_Lawn;

        virtual ~Lawn();

    protected:

    private:
};

#endif // LAWN_H
