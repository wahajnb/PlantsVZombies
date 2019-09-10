#ifndef POTATO_LIST_H
#define POTATO_LIST_H
#include "Wallnut.h"
#include <vector>
#include <SDL.h>

class potato_List
{
    public:
        potato_List();
        void get_Renderer(SDL_Renderer*);
        SDL_Renderer* gRenderer;
        vector <Wallnut*> potato_arr;
        void display();
        void add_potato(Wallnut*);
        void del_plant(float,float);
        virtual ~potato_List();

    protected:

    private:
};

#endif // POTATO_LIST_H
