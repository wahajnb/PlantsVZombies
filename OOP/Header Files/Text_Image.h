#ifndef TEXT_IMAGE_H
#define TEXT_IMAGE_H
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <iostream>
#include <stdio.h>

using namespace std;

class Text_Image            //Converts the text into image
{
    public:
        Text_Image();
        Text_Image(SDL_Renderer*);
        ~Text_Image();
        SDL_Renderer* ss_Rend;
        SDL_Texture* ss_Texture;

        SDL_Texture* loadMedia(string textureText, SDL_Color textColor,TTF_Font*);

    protected:

    private:
};

#endif // TEXT_IMAGE_H
