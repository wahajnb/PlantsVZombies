#ifndef CHOMPER_LIST_H
#define CHOMPER_LIST_H
#include <vector>
#include <SDL.h>
#include "Chomper.h"

class chomper_List
{
    public:
        chomper_List();
        void get_Renderer(SDL_Renderer*);
        SDL_Renderer* gRenderer;
        vector <Chomper*> chomper_arr;
        void display();
        void add_chomper(Chomper*);
        virtual ~chomper_List();

    protected:

    private:
};

#endif // CHOMPER_LIST_H
