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
    queue<Person> passengers;
    int floorsVisited;
};

class ElevatorBay
{
    public:
        Elevator();
        ~Elevator();

    protected:
    private:
        Elevator e1;
        Elevator e2;
        Elevator e3;



};

#endif // GRAPH_H
