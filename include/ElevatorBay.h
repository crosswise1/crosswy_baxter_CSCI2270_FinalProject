#ifndef ELEVATORBAY_H
#define ELEVATORBAY_H
#include<vector>
#include<queue>
#include<iostream>

struct Person{
    std::string id;
    int floor;
};

struct Elevator{
    std::queue<Person> passengers;
    int floorsVisited;
};

class ElevatorBay
{
    public:
        ElevatorBay(std::string);
        ~ElevatorBay();
        void readFile(std::string);
        void Allocatepeople();
        void Printresults();
        int nextFloor(); //new comment that i added

    protected:
    private:
        Elevator e1;
        Elevator e2;
        Elevator e3;



};

#endif // GRAPH_H
