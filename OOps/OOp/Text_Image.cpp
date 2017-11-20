#include "Text_Image.h"

Text_Image::Text_Image()
{
    ss_Rend = NULL;
    ss_Texture = NULL;
}

Text_Image::Text_Image(SDL_Renderer* real)
{
    ss_Rend = real;
    ss_Texture = NULL;
}

Text_Image::~Text_Image()
{
    SDL_DestroyTexture( ss_Texture );
	ss_Texture = NULL;
}

SDL_Texture* Text_Image::loadMedia(string textureText, SDL_Color textColor,TTF_Font* gFont )
{
	//The final texture
	ss_Texture = NULL;

	//Load image at specified path
	SDL_Surface* textSurface = TTF_RenderText_Solid( gFont, textureText.c_str(), textColor );
	cout << "yo";
	if( textSurface == NULL )
	{
		printf( "Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError() );
	}
	else
	{

		//Create texture from surface pixels
        ss_Texture = SDL_CreateTextureFromSurface(ss_Rend, textSurface );
		if( ss_Texture == NULL )
		{
		    cout << "wtf" << endl;
			printf( "Unable to create texture from rendered text %s! SDL Error: %s\n",textureText.c_str(), SDL_GetError() );
		}

		//Get rid of old surface
		SDL_FreeSurface( textSurface );
	}

	if( ss_Texture == NULL )
	{
		printf( "Failed to load texture image!\n" );
    }



	return ss_Texture;
}

