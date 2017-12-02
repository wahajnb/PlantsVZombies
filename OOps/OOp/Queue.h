#ifndef QUEUE_H
#define QUEUE_H
#include "Node.h"
#include "Sunflower.h"
#include "Chomper.h"
#include "PeaShooter.h"
#include "plant_Card.h"
#include "sunFlower_Card.h"
#include "chomper_Card.h"
#include "Lawn.h"
#include "Sun.h"

class Queue
{
    private:
        Node* head;
        Node* tail;

    public:
        Queue();
        ~Queue();
        void Enqueue(world*);
        world* Dequeue();
        void Display();
        void savefile(string fname);
        void loadfile(string fname);
};

#endif // QUEUE_H
