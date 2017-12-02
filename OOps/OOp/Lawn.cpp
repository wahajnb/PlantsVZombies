#include "Lawn.h"

Lawn::Lawn()
{
    //ctor
}

Lawn::~Lawn()
{
    //dtor
}

void Lawn::set_Lawn(SDL_Renderer* r)
{
    gRenderer = r;
    x_Lawn = 13;
    y_Lawn = 105;

    shovel_plant.set_Sound(shove_sound);
    shovel_plant.load_Sound("Soundtracks/Shovel.wav");
    dummy_Region.set_Coords(gRenderer,5000,2230,1,1);

    for (int i=0; i<5; i++)
        {
            for (int j=0; j<9; j++)
            {
                lawn_Tiles[i][j].set_Coords(gRenderer,x_Lawn,y_Lawn,144,128);
                lawn_Tiles[i][j].lawn_Occupied = false;
                x_Lawn = x_Lawn + 144;

            }
            x_Lawn = 13;
            y_Lawn = y_Lawn + 128;
        }
}

Region Lawn::return_tile(int x, int y)
{
    for (int i=0; i<5; i++)
        {
            for (int j=0; j<9; j++)
            {
                if (lawn_Tiles[i][j].onLawn(x,y) == true)
                    {
                        lawn_Tiles[i][j].lawn_Occupied = true;
                        return lawn_Tiles[i][j];
                    }

            }
        }
}

bool Lawn::ret_occTile(int x,int y)
{
   for (int i=0; i<5; i++)
        {
            for (int j=0; j<9; j++)
            {
                if (lawn_Tiles[i][j].onLawn(x,y) == true)
                    {
                       // lawn_Tiles[i][j].lawn_Occupied = true;
                        return lawn_Tiles[i][j].lawn_Occupied;
                    }

            }
        }
}

bool Lawn::onLawn(int a, int b)
{
    for (int i=0; i<5; i++)
        {
            for (int j=0; j<9; j++)
            {
                if (lawn_Tiles[i][j].onLawn(a,b) == true && lawn_Tiles[i][j].lawn_Occupied == false)
                    return true;
            }
        }
    return false;
}

bool Lawn::inLawn(int a, int b)
{
    for (int i=0; i<5; i++)
        {
            for (int j=0; j<9; j++)
            {
                if (lawn_Tiles[i][j].onLawn(a,b) == true)
                    return true;
            }
        }
    return false;
}

Region* Lawn::uproot(int l, int m)
{
    for (int i=0; i<5; i++)
        {
            for (int j=0; j<9; j++)
            {
                if (lawn_Tiles[i][j].onLawn(l,m) == true)
                    {
                        if (lawn_Tiles[i][j].lawn_Occupied == true)
                            {
                                lawn_Tiles[i][j].lawn_Occupied = false;
                                shovel_plant.play_Sound();
                                return &lawn_Tiles[i][j];

                            }
                    }
            }
        }
        return &dummy_Region;
}
