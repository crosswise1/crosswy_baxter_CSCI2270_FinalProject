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
            getline(ss, name);
            getline(ss, floorStr);
            floor = stoi(floorStr);
            Person newPerson(name, floor);
            people.push_back(newPerson);
        }
        printInitial();
    }
}

void ElevatorBay::printInitial(){
    for(int i = 0; i < people.size(); i++){
        std::cout << "Name: " << people[i].id << ", Floor: " << people[i].floor << std::endl;
    }
}
