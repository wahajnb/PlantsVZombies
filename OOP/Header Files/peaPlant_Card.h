#ifndef PEAPLANT_CARD_H
#define PEAPLANT_CARD_H
#include "plant_Card.h"

class peaPlant_Card: public plant_Card
{
    public:
        peaPlant_Card();
        peaPlant_Card(SDL_Renderer*, SDL_Texture*);
        void load_Media(SDL_Renderer*, SDL_Texture*);
        void display_Card();
        void display();
        virtual ~peaPlant_Card();

    protected:

    private:
};

#endif // PEAPLANT_CARD_H
