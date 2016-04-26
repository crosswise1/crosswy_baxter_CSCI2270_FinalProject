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
        void runElevators(std::string);
        void printResults();
        void printInitialStats();
        void printAverage();

    protected:
    private:
        Elevator *e1;
        Elevator *e2;
        Elevator *e3;
        Elevator *ie1;
        bool inefficientProcessed;
        bool efficientProcessed;

        std::vector<Person> people;
        int printPeopleArray[15];
        int buildingHeight = 15;
        void allocatePeopleEfficient();
        void allocatePeopleInefficient();
        void processPeople(Elevator*, int);
};

#endif // ELEVATORBAY_H
