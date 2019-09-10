#ifndef WALLNUT_H
#define WALLNUT_H

#include "Plants.h"


class Wallnut : public Plants
{
    public:
        Wallnut(SDL_Renderer * gRenderer, LTexture * NImage, LTexture * HImage, LTexture * MHImage, float x, float y);
        virtual ~Wallnut();
        void die();
        bool GetExists();
        int GetHealth();
        void IsHit(int);
        float frames;

        virtual void Render(Uint32 frame, SDL_Renderer* gRenderer, int x);
        void display();
        void displaynormal();
        void displayhit();
        void displaymorehit();

    protected:
        enum NormalFrames {WallnutFrames = 20, HitFrame = 1, MoreHitFrame = 1};
        SDL_Rect WallnutClips[ WallnutFrames ];
        LTexture * WallnutTexture;
        SDL_Rect HitClip[ HitFrame ];
        LTexture * HitTexture;
        SDL_Rect MoreHitClip[ MoreHitFrame ];
        LTexture * MoreHitTexture;

    private:
        SDL_Renderer * gRenderer;
};

#endif // WALLNUT_H
