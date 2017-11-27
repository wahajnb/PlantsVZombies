#ifndef SCREEN_IMAGE_H
#define SCREEN_IMAGE_H
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "Region.h"

using namespace std;


class screen_Image              //Basic function is to load textures
{
    public:
        screen_Image();
        screen_Image(SDL_Renderer*);
        ~screen_Image();
        SDL_Renderer* ss_Rend;
        SDL_Texture* ss_Texture;
        SDL_Texture* loadMedia(string);
        Region* location;
        void image_Render();

    protected:

    private:
};

#endif // SCREEN_IMAGE_H
