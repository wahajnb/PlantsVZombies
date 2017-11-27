#ifndef CHOMPER_CARD_H
#define CHOMPER_CARD_H
#include "plant_Card.h"

class chomper_Card : public plant_Card
{
    public:
        chomper_Card();
        void load_Media(SDL_Renderer*, SDL_Texture*);
        void display_Card();
        virtual ~chomper_Card();

    protected:

    private:
};

#endif // CHOMPER_CARD_H
