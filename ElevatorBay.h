#ifndef ELEVATORBAY_H
#define ELEVATORBAY_H
#include<vector>
#include<queue>
#include<iostream>

struct Person{
    string identifier;
    int floor;
};

struct Elevator{
    queue<Person> people;
    int floorsVisited;
};

class ElevatorBay
{
    public:
        Elevator();
        ~Elevator();
        Readfile (char*);
        void Allocatepeople();
        void Printresults();

    protected:
    private:


};

#endif // GRAPH_H
