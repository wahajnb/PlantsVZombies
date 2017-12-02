#ifndef PEASHOOTER_H
#define PEASHOOTER_H
#include "Plants.h"
#include "Pea.h"
#include "Sound.h"


class PeaShooter : public Plants
{
    public:
        PeaShooter(SDL_Renderer * gRenderer, LTexture* image, float x, float y);
        PeaShooter();
        virtual ~PeaShooter();
        void die();
        bool GetExists();
        int GetHealth();
        void IsHit(int);
        Uint32 PeaShooterFrame;

        Mix_Chunk* psound = NULL;
        Sound pea_Shoot;

        virtual void Render(Uint32 frame, SDL_Renderer* gRenderer);
        void display();

    protected:
        enum AnimationFrames {NormalFrames = 56};
        SDL_Rect PeaShooterClips[ NormalFrames ];
        LTexture* PeaShooterTexture;
        Pea* P1;

    private:
        SDL_Renderer * gRenderer;
};

#endif // PEASHOOTER_H
