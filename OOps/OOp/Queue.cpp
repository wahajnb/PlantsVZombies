#include "Queue.h"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

Queue::Queue()
{
    head = NULL;
    tail = NULL;
}

Queue::~Queue()
{
    Node* temp = NULL;
    while(head != NULL)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
}

void Queue::Enqueue(world* obj)
{
    if(head == NULL)                                       //if theres no other node
    {
        head = new Node;
        head->obj = obj;
        head->next = NULL;
        head->prev = NULL;
        tail = head;
    }
    else
    {
        tail->next = new Node;                           //if theres already a node
        tail->next->obj = obj;
        tail->next->next = NULL;
        tail->next->prev = tail;
        tail = tail->next;
    }
}

world* Queue::Dequeue()
{
    world* obj = NULL;
    if(head != NULL)
    {
        Node* temp = head;
        head = head->next;
        obj = temp->obj;
        delete temp;
    }

    return obj;
}

void Queue::Display()
{
    Node* temp = head;
    while(temp!=NULL)
    {
        temp->obj->display();
        temp=temp->next;
    }
}

void Queue::savefile(string fname)
{
    ofstream file;
    file.open(fname.c_str(), ofstream::app);
    Node* temp = head;

    if(!(file.is_open()))
    {
        printf("Error opening the file. ");
    }

    while (temp != NULL)
    {
        temp->obj->save(file);
        temp = temp->next;
    }

    file.close();
}

void Queue::loadfile(string fname)
{
    ifstream inFile;
    string line;
    int x, y, h;
    world* w_ptr;
    inFile.open(fname.c_str(), ifstream::in);
    if(!(inFile.is_open()))
    {
        printf("Error opening the input file. ");
    }

    while(getline(inFile,line))
    {
        if (line == "sunflower")
        {
            getline(inFile, line);
            x = w_ptr->to_int(line);
            getline(inFile, line);
            y = w_ptr->to_int(line);
            getline(inFile, line);
            h = w_ptr->to_int(line);
            world* p = new Sunflower(x, y, h);
            Enqueue(p);
        }
        else if (line == "chomper")
        {
            getline(inFile, line);
            x = w_ptr->to_int(line);
            getline(inFile, line);
            y = w_ptr->to_int(line);
            getline(inFile, line);
            h = w_ptr->to_int(line);
            world* p = new Chomper(x, y, h);
            Enqueue(p);
        }
        else if (line == "peashooter")
        {
            getline(inFile, line);
            x = w_ptr->to_int(line);
            getline(inFile, line);
            y = w_ptr->to_int(line);
            getline(inFile, line);
            h = w_ptr->to_int(line);
            world* p = new PeaShooter(x, y, h);
            Enqueue(p);
        }
        else if (line == "chompercard")
        {
            getline(inFile, line);
            x = w_ptr->to_int(line);
            getline(inFile, line);
            y = w_ptr->to_int(line);
            world* p = new chomper_Card(x,y);
            Enqueue(p);
        }
        else if (line == "sunflowercard")
        {
            getline(inFile, line);
            x = w_ptr->to_int(line);
            getline(inFile, line);
            y = w_ptr->to_int(line);
            world* p = new sunFlower_Card(x, y);
            Enqueue(p);
        }
         else if (line == "peaplantcard")
        {
            getline(inFile, line);
            x = w_ptr->to_int(line);
            getline(inFile, line);
            y = w_ptr->to_int(line);
            world* p = new peaPlant_Card(x,y);
            Enqueue(p);
        }
        else if (line == "fastzombie")
        {
            getline(inFile, line);
            x = w_ptr->to_int(line);
            getline(inFile, line);
            y = w_ptr->to_int(line);
            getline(inFile, line);
            h = w_ptr->to_int(line);
            world* p = new FastZombie(x, y, h);
            Enqueue(p);
        }
        else if (line == "fatzombie")
        {
            getline(inFile, line);
            x = w_ptr->to_int(line);
            getline(inFile, line);
            y = w_ptr->to_int(line);
            getline(inFile, line);
            h = w_ptr->to_int(line);
            world* p = new FatZombie(x, y, h);
            Enqueue(p);
        }
        else if (line == "lawn")
        {
            getline(inFile, line);
            x = w_ptr->to_int(line);
            getline(inFile, line);
            y = w_ptr->to_int(line);
            getline(inFile, line);
            h = w_ptr->to_int(line);
            world* p = new Lawn(x, y, h);
            Enqueue(p);
        }
        else if (line == "sun")
        {
            getline(inFile, line);
            int s_x = w_ptr->to_int(line);
            getline(inFile, line);
            int s_y = w_ptr->to_int(line);
            getline(inFile, line);
            int e_x = w_ptr->to_int(line);
            getline(inFile, line);
            int e_y = w_ptr->to_int(line);
            world* p = new Sun(s_x, s_y, e_x, e_y);
            Enqueue(p);
        }
    }

    inFile.close();
}


