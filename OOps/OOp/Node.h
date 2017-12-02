#pragma once
#include "world.h"

struct Node
{
    world* obj;
    Node* next;
    Node* prev;

    ~Node()
    {
        delete obj;
    }
};
