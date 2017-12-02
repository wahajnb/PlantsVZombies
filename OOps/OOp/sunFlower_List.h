#ifndef SUNFLOWER_LIST_H
#define SUNFLOWER_LIST_H
#include "Sunflower.h"
#include "LTexture.h"
#include "SDL.h"
#include <vector>


class sunFlower_List
{
    public:
        sunFlower_List();
        void get_Renderer(SDL_Renderer*);
        SDL_Renderer* gRenderer;
        vector <Sunflower*> sunflower_arr;
        virtual ~sunFlower_List();
        void display();
        void add_Sunflower(Sunflower*);

    protected:

    private:
};

#endif // SUNFLOWER_LIST_H
