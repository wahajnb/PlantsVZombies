#ifndef POTATO_CARD_H
#define POTATO_CARD_H
#include "plant_Card.h"


class potato_Card : public plant_Card
{
    public:
        potato_Card();
        potato_Card(SDL_Renderer*, SDL_Texture*);
        void load_Media(SDL_Renderer*, SDL_Texture*);
        void display_Card();
        void display();
        virtual ~potato_Card();

    protected:

    private:
};

#endif // POTATO_CARD_H
