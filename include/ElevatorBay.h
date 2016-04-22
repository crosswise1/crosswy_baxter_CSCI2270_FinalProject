#ifndef ELEVATORBAY_H
#define ELEVATORBAY_H
#include<vector>
#include<queue>
#include<iostream>

struct Person{
    std::string id;
    int floor;
    Person(){};
    Person(std::string _id, int _floor){
        id = _id;
        floor = _floor;
    }
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
        void allocatePeople();
        void printResults();
        int nextFloor();

    protected:
    private:
        Elevator e1;
        Elevator e2;
        Elevator e3;
        std::vector<Person> people;
        void printInitial();



};

#endif // GRAPH_H
