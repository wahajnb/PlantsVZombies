#ifndef CHOMPER_H
#define CHOMPER_H
#include "Plants.h"


class Chomper : public Plants
{
    public:
        Chomper(SDL_Renderer * gRenderer, LTexture* NImage, LTexture * EImage, float xcord, float ycord);
        Chomper();
        virtual ~Chomper();
        void die();
        void Eat();
        void IsHit(int damage);
        bool GetExists();
        int GetHealth();
        //Uint32 ChomperFrame;
        float framesxyz[2];

        virtual void Render(Uint32 frame, SDL_Renderer* gRenderer, bool sun);
        void display();
        void displaynormal(SDL_Renderer* gRenderer);
        void displayeating(SDL_Renderer* gRenderer);

    protected:
        enum AnimationFrames {NormalFrames = 31, EatingFrames = 20};
        SDL_Rect ChomperClips[ NormalFrames ];
        LTexture* ChomperTexture;
        SDL_Rect EatingClips[ EatingFrames ];
        LTexture * EatingTexture;

    private:
        bool iseating;
        SDL_Renderer* gRenderer;
};

#endif // CHOMPER_H
