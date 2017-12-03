#ifndef PEA_H
#define PEA_H
#include <stdio.h>
#include <time.h>
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include "LTexture.h"

using namespace std;


class Pea
{
    public:
        Pea();
        Pea(SDL_Renderer* gRenderer, float x, float y);
        virtual ~Pea();
        bool Die();
        void move(int speed);
        int GetDamage();
        int GetSpeed();
        float Getxcord();
        float Getycord();
        Uint32 PeaFrame;

        virtual void Render(Uint32 frame, SDL_Renderer* gRenderer);
        void display();//);

    protected:
        enum AnimationFrame {NormalFrame = 1};
        SDL_Rect PeaClip[ NormalFrame ];
        LTexture PeaTexture;

    private:
        int width;
        int height;
        float xcord;
        float ycord;
        int speed;
        int damage;
        string name;
        bool exists;
        bool loadMedia();
        SDL_Renderer* gRenderer;
};

#endif // PEA_H
