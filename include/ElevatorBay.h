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
    int capacity;
    Elevator(){
        floorsVisited = 0;
        capacity = 15;
    }
};

class ElevatorBay
{
    public:
        ElevatorBay(std::string);
        ~ElevatorBay();
        void readFile(std::string);
        void allocatePeople1();
        //void allocatePeople2();
        //void allocatePeople3();
        void printResults();
        int nextFloor();
        void printInitialStats();


    protected:
    private:
        Elevator e1;
        Elevator e2;
        Elevator e3;
        Elevator e4old;
        std::vector<Person> people;
        void processPeopleEfficient(Elevator);
        void processPeopleEfficient();
};

#endif // ELEVATORBAY_H
