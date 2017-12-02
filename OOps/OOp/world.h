#ifndef WORLD_H
#define WORLD_H
#include <string>
#include <sstream>
using namespace std;

class world
{
    public:
        world();
        virtual ~world();
        int to_int(string);
        void display();
        void save();
        void save(ofstream&);

    protected:

    private:
};

#endif // WORLD_H
