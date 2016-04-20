#ifndef ELEVATOR_H
#define ELEVATOR_H
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

    protected:
    private:


};

#endif // GRAPH_H
