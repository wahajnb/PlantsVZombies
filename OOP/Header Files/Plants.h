#ifndef PLANTS_H
#define PLANTS_H
#include <string>
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include"LTexture.h"


using namespace std;

class Plants
{
    public:
        Plants();
        virtual ~Plants();
        float xcord;
        float ycord;

        int width;
        int height;

        int health;
        int damage;
        int cost;
        int range;
        int rate;
        string name;
        bool sun;
        bool exists;


    private:


};

#endif // PLANTS_H
