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
        allocatePeopleEfficient(); //changed allocatePeople1 to allocatePeopleEfficient
    }
}

void ElevatorBay::printInitialStats(){//new comment!!!!
    std::cout << "Number of passengers to process: " << people.size() <<" people" << std::endl;
    std::cout << "=================================" << std::endl;
    std::cout << "FLOOR DISTRIBUTION" << std::endl;
    int printPeopleArray[15];
    int buildingHeight = 15;
    for (int floor = 0; floor < buildingHeight; floor++){
        int counter = 0;
        for (unsigned int index = 0; index < people.size(); index++){
            if (people[index].floor == floor+1)
                counter++;
            printPeopleArray[floor] = counter;
        }
        if (floor < 9){
            std::cout << "Floor 0" << floor+1<<":";
            for (int x = 0; x < printPeopleArray[floor]; x++)
                std::cout<<'x';
        }
        else{
            std::cout << "Floor " << floor+1 <<":";
            for (int x = 0; x < printPeopleArray[floor]; x++)
                std::cout<<'x';
        }
        std::cout<<std::endl;
    }
}

void ElevatorBay::allocatePeopleEfficient(){ //This method allocates people for floors 1-5
    std::cout << "================" << std::endl; //this is just error checking
    for (unsigned int i = 0; i < people.size(); i++){
        if (people[i].floor >= 1 && people[i].floor <= 5){
            std::cout << "Name:: " << people[i].id <<", Floor: " << people[i].floor << std::endl;
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
    processPeopleEfficient(e1);  //unsure about what this thing does exactly...
}

void ElevatorBay::processPeopleEfficient(Elevator e){
    int numPassengers = 0;
    std::vector <int> uniqueFloors;
    //std::cout<<"tmp's size: " << tmp.size() << std::endl;
    while (!e.passengers.empty()){
        //std::cout << e1.passengers.front().id << std::endl;
        int floor = e.passengers.front().floor;
        std::cout <<"Floor number: " << floor << std::endl;
        bool found = false;
        if (!uniqueFloors.empty()){
            for (unsigned int j  = 0; j <= uniqueFloors.size(); j++){
                std::cout<<"what is J = " << j << std::endl;
                if (uniqueFloors[j] == floor) {
                    found = true;
                    break;
                }
            }
        }
        std::cout<<"5 test" << std::endl;
        if(!found) {
            uniqueFloors.push_back(floor);
            //std::cout<<"5 test" << std::endl;
            e.floorsVisited++;
            //std::cout<<"6 test" << std::endl;
        }
        e.passengers.pop();
        numPassengers++;
        if (numPassengers == e.capacity){
            numPassengers = 0;
            uniqueFloors.clear();
            e.floorsVisited++;
        }
    }
    if (numPassengers != 0)
        e.floorsVisited++;
        //new comment
    std::cout<<"floors visited: "<< e.floorsVisited << std::endl;
}

void ElevatorBay::allocatePeopleInefficient(){
    for(unsigned int i = 0; i < people.size(); i++){
        ie1.passengers.push(people[i]);
    }
    processPeopleInefficient(ie1);
}
