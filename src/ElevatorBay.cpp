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
        //printInitialStats();
        allocatePeopleEfficient(); //changed allocatePeople1 to allocatePeopleEfficient
    }
}

void ElevatorBay::printInitialStats(){ //david comment: there has to be a more efficient way than this
    std::cout << "Number of passengers to process: " << people.size() <<" people" << std::endl;
    std::cout << "=================================" << std::endl;
    std::cout << "FLOOR DISTRIBUTION" << std::endl;
    int one = 0, two = 0, three = 0, four = 0, five = 0, six = 0, seven = 0, eight = 0, nine = 0, ten = 0, eleven = 0, twelve = 0, thirteen = 0, fourteen =0, fifteen = 0;
    for(unsigned int i = 0; i < people.size(); i++){
        if (people[i].floor == 1)
            one =  one + 1;
        else if (people[i].floor == 2)
            two = two + 1;
        else if (people[i].floor == 3)
            three = three + 1;
        else if (people[i].floor == 4)
            four = four + 1;
        else if (people[i].floor == 5)
            five = five + 1;
        else if (people[i].floor == 6)
            six = six + 1;
        else if (people[i].floor == 7)
            seven = seven + 1;
        else if (people[i].floor == 8)
            eight = eight + 1;
        else if (people[i].floor == 9)
            nine = nine + 1;
        else if (people[i].floor == 10)
            ten = ten + 1;
        else if (people[i].floor == 11)
            eleven = eleven + 1;
        else if (people[i].floor == 12)
            twelve = twelve + 1;
        else if (people[i].floor == 13)
            thirteen = thirteen + 1;
        else if (people[i].floor == 14)
            fourteen = fourteen + 1;
        else if (people[i].floor == 15)
            fifteen = fifteen + 1;
        //std::cout << "Name: " << people[i].id << " Floor: " << people[i].floor << std::endl;
    }
    /*
    std::cout<< one << std::endl;
    std::cout<< two << std::endl;
    std::cout<< three << std::endl;
    std::cout<< four << std::endl;
    std::cout<< five << std::endl;
    std::cout<< six << std::endl;
    std::cout<< seven << std::endl;
    std::cout<< eight << std::endl;
    std::cout<< nine << std::endl;
    std::cout<< ten << std::endl;
    std::cout<< eleven << std::endl;
    std::cout<< twelve << std::endl;
    std::cout<< thirteen << std::endl;
    std::cout<< fourteen << std::endl;
    std::cout<< fifteen << std::endl;
    */
    std::cout << "FLOOR 01: ";
    for(int i = 0; i < one; i++)
        std::cout<<'x';
    std::cout<<std::endl;
    std::cout << "FLOOR 02: ";
    for(int i = 0; i < two; i++)
        std::cout<<'x';
    std::cout<<std::endl;
    std::cout << "FLOOR 03: ";
    for(int i = 0; i < three; i++)
        std::cout<<'x';
    std::cout<<std::endl;
    std::cout << "FLOOR 04: ";
    for(int i = 0; i < four; i++)
        std::cout<<'x';
    std::cout<<std::endl;
    std::cout << "FLOOR 05: ";
    for(int i = 0; i < five; i++)
        std::cout<<'x';
    std::cout<<std::endl;
    std::cout << "FLOOR 06: ";
    for(int i = 0; i < six; i++)
        std::cout<<'x';
    std::cout<<std::endl;
    std::cout << "FLOOR 07: ";
    for(int i = 0; i < seven; i++)
        std::cout<<'x';
    std::cout<<std::endl;
    std::cout << "FLOOR 08: ";
    for(int i = 0; i < eight; i++)
        std::cout<<'x';
    std::cout<<std::endl;
    std::cout << "FLOOR 09: ";
    for(int i = 0; i < nine; i++)
        std::cout<<'x';
    std::cout<<std::endl;
    std::cout << "FLOOR 10: ";
    for(int i = 0; i < ten; i++)
        std::cout<<'x';
    std::cout<<std::endl;
    std::cout << "FLOOR 11: ";
    for(int i = 0; i < eleven; i++)
        std::cout<<'x';
    std::cout<<std::endl;
    std::cout << "FLOOR 12: ";
    for(int i = 0; i < twelve; i++)
        std::cout<<'x';
    std::cout<<std::endl;
    std::cout << "FLOOR 13: ";
    for(int i = 0; i < thirteen; i++)
        std::cout<<'x';
    std::cout<<std::endl;
    std::cout << "FLOOR 14: ";
    for(int i = 0; i < fourteen; i++)
        std::cout<<'x';
    std::cout<<std::endl;
    std::cout << "FLOOR 15: ";
    for(int i = 0; i < fifteen; i++)
        std::cout<<'x';
    std::cout<<std::endl;
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
    std::cout<<"floors visited: "<< e.floorsVisited << std::endl;
}

void ElevatorBay::allocatePeopleInefficient(){
    for(unsigned int i = 0; i < people.size(); i++){
        ie1.passengers.push(people[i]);
    }
    processPeopleInefficient(ie1);
}

void ElevatorBay::processPeopleInefficient(Elevator e){ //I think we should be able to use the ProcessPeople method even for the inefficient version of things.
    std::vector<int> uniqueFloors;

    while(!e.passengers.empty()){

    }
}
