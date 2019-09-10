#ifndef PEAPLANT_LIST_H
#define PEAPLANT_LIST_H
#include "PeaShooter.h"
#include <vector>
#include <SDL.h>

class peaPlant_List
{
    public:
        peaPlant_List();
        void get_Renderer(SDL_Renderer*);
        SDL_Renderer* gRenderer;
        vector <PeaShooter*> PeaShooter_arr;
        void display();
        void add_peaPlant(PeaShooter*);
        void del_plant(float,float);
        virtual ~peaPlant_List();

    protected:

    private:
};

#endif // PEAPLANT_LIST_H
