#ifndef ELEVATOR_H
#define ELEVATOR_H
#include<vector>
#include<iostream>

struct Person{
    string identifier;
    int floor;
};

class Elevator
{
    public:
        Elevator();
        ~Elevator();
        void BFTraversalLabel(std::string startingCity, int distID);
        void shortestPath(std::string startingCity,std::string endingCity);
        void shortestDistance(std::string startingCity, std::string endingCity);

    protected:
    private:
        std::vector<Person> people;

};

#endif // GRAPH_H

