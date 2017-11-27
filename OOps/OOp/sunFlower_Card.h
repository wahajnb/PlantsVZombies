#ifndef SUNFLOWER_CARD_H
#define SUNFLOWER_CARD_H
#include "plant_Card.h"

class sunFlower_Card: public plant_Card
{
    public:
        sunFlower_Card();
        virtual ~sunFlower_Card();
        void load_Media(SDL_Renderer*, SDL_Texture*);
        void display_Card();

    protected:

    private:
};

#endif // SUNFLOWER_CARD_H
