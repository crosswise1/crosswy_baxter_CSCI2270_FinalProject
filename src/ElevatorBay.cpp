#include "../include/ElevatorBay.h"
#include<queue>
#include<vector>
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>


ElevatorBay::ElevatorBay(std::string fname){
    readFile(fname);
}
ElevatorBay::~ElevatorBay(){
    //nothing
}
void ElevatorBay::readFile(std::string fname){
    std::ifstream inFile;
    inFile.open(fname);
    std::string line;
    std::string name;
    std::string floorStr;
    int floor;
    if(inFile.good()){
        while(getline(inFile, line)){
            std::stringstream ss(line);
            getline(ss, name, ',');
            getline(ss, floorStr, ',');
            floor = std::stoi(floorStr);
            Person newPerson(name, floor);
            people.push_back(newPerson);
        }
        printInitial();
        allocatePeople1();
    }
}

void ElevatorBay::printInitial(){
    for(unsigned int i = 0; i < people.size(); i++){
        std::cout << "Name: " << people[i].id << " Floor: " << people[i].floor << std::endl;
    }
}

void ElevatorBay::allocatePeople1(){ //This method allocates people for floors 1-5
    std::cout << "================" << std::endl; //this is just error checking
    for (unsigned int i = 0; i < people.size(); i++){
        if (people[i].floor >= 1 && people[i].floor <= 5){
            //std::cout << "Name:: " << people[i].id <<", Floor: " << people[i].floor << std::endl;
            e1.passengers.push(people[i]);
        }
        else if(people[i].floor >= 6 && people[i].floor <= 10){
            e2.passengers.push(people[i]);
        }
        else if(people[i].floor >= 11 && people[i].floor <= 15){
            e3.passengers.push(people[i]);
        }
    }
    //Do we need to add a condition if queue is not empty?
    std::cout<<"test" << std::endl;
    processPeople(e1);
}

void ElevatorBay::processPeople(Elevator e){
    int x = 0;
    std::vector <int> tmp;
    while (!e.passengers.empty()){
        //std::cout << e1.passengers.front().id << std::endl;
        int floor = e.passengers.front().floor;
        bool found = false;
        for (int j  = 0; j <= tmp.size(); j++){
            if (tmp[j] == floor) {
                found = true;
                break;
            }
        }
        if(!found) {
            tmp.push_back(floor);
            e.floorsVisited++;
        }
        e.passengers.pop();
        x++;
        if (x == e.capacity-1){
            x = 0;
            tmp.clear();
            e.floorsVisited++;
        }
    }
    if (x != 0)
        e.floorsVisited++;
    std::cout<<"floors visited: "<< e.floorsVisited << std::endl;

}
