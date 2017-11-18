#include "screen_Image.h"
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <stdio.h>

using namespace std;

screen_Image::screen_Image()
{
    ss_Rend = NULL;
    ss_Texture = NULL;
}

screen_Image::screen_Image(SDL_Renderer* real)
{
    ss_Rend = real;
    ss_Texture = NULL;
}

screen_Image::~screen_Image()
{
    //Free loaded image
	SDL_DestroyTexture( ss_Texture );
	ss_Texture = NULL;
	cout << "destroy" << endl;
}

SDL_Texture* screen_Image::loadMedia(string path )
{
	//The final texture
	ss_Texture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{
		//Create texture from surface pixels
        ss_Texture = SDL_CreateTextureFromSurface(ss_Rend, loadedSurface );
		if( ss_Texture == NULL )
		{
		    cout << "wtf" << endl;
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	if( ss_Texture == NULL )
	{
		printf( "Failed to load texture image!\n" );
    }

	return ss_Texture;
}

