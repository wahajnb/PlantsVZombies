#ifndef REGION_H
#define REGION_H
#include <SDL.h>
#include <SDL_image.h>


class Region        //Its basic function is to allocate a region on which we will be rendering our texture
{
    public:
        Region(SDL_Renderer* , int, int, int, int);     //Constructor
        Region(SDL_Renderer*);
        Region();
        void set_Coords (SDL_Renderer*,int, int, int ,int);
        ~Region();
        SDL_Rect area;
        SDL_Renderer* area_Rend;
        bool is_Pressed(int,int,SDL_Event);
        bool isOn(int, int);
        void set_Viewport();

    protected:

    private:
};

#endif // REGION_H
