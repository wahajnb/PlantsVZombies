#ifndef SUN_COUNT_H
#define SUN_COUNT_H
#include "screen_Image.h"
#include "Text_Image.h"
#include <sstream>
#include <SDL_ttf.h>

class sun_Count
{
    public:
        sun_Count();
        void load_Media(SDL_Renderer*, SDL_Texture*);
        SDL_Renderer *gRenderer;
        SDL_Texture *gTexture;
        Region suncount_1digit;
        Region suncount_2digit;
        Region suncount_3digit;
        Text_Image s_count;
        void set_Suns (int );
        TTF_Font* roboto_Font = NULL;
        SDL_Color black_color ;
        int suns;
        virtual ~sun_Count();

    protected:

    private:
};

#endif // SUN_COUNT_H
