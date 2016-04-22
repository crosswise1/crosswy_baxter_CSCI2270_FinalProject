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
            std::cout << "Name:: " << people[i].id <<", Floor: " << people[i].floor << std::endl;
            e1.passengers.push(people[i]);
        }
    }
    if (e1.passengers.empty())
        std::cout<<"queue is empty"<<std::endl;
    else if (!e1.passengers.empty())
        std::cout <<"QUEUE is not empty"<<std::endl;
    //add a condition if queue is not empty?
    while (!e1.passengers.empty()){
        std::cout << e1.passengers.front() << std::endl;
    }
}
