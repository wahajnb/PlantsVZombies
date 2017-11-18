#ifndef REGION_H
#define REGION_H
#include <SDL.h>
#include <SDL_image.h>


class Region
{
    public:
        Region(SDL_Renderer* , int, int, int, int);
        ~Region();
        SDL_Rect area;
        SDL_Renderer* area_Rend;
        bool button_Pressed(int,int);
        bool isOn(int, int);
        void set_Viewport();

    protected:

    private:
};

#endif // REGION_H
