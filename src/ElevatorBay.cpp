#include "../include/ElevatorBay.h"
#include<queue>
#include<vector>
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>


ElevatorBay::ElevatorBay(){
    //nothing
}
ElevatorBay::~ElevatorBay(){
    //nothing
}

void ElevatorBay::init(){
    std::cout << std::string(50, '\n');
    std::string fname;
    std::cout << "Welcome to the Elevator Optimization program." << std::endl;
    std::cout << "To continue, enter the name of the text file containing the passenger information: " << std::endl;
    getline(std::cin, fname);
    std::ifstream inFile;
    inFile.open(fname);
    while(!inFile.good()){
        std::cout << "File not found! Please try again: " << std::endl;
        getline(std::cin, fname);
        inFile.open(fname);
    }

    people.clear();
    readFile(fname);
    inefficientProcessed = false;
    efficientProcessed = false;
    e1 = new Elevator;
    e2 = new Elevator;
    e3 = new Elevator;
    ie1 = new Elevator;
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
    }
    std::cout << "Program built!" << std::endl;
}

void ElevatorBay::printInitialStats(){//new comment!!!!
    std::cout << "Number of passengers to process: " << people.size() <<" people" << std::endl;
    std::cout << "=================================" << std::endl;
    std::cout << "FLOOR DISTRIBUTION" << std::endl;
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
    std::cout<<"... where a single passenger is represented by an x"<<std::endl;

}

void ElevatorBay::allocatePeopleEfficient(){ //This method allocates people for floors 1-5
    std::cout << "================" << std::endl; //this is just error checking
    for (unsigned int i = 0; i < people.size(); i++){
        if (people[i].floor >= 1 && people[i].floor <= 5){
        //    std::cout << "Name:: " << people[i].id <<", Floor: " << people[i].floor << std::endl;
            e1->passengers.push(people[i]);
        }
        else if(people[i].floor >= 6 && people[i].floor <= 10){
        //    std::cout << "Name:: " << people[i].id <<", Floor: " << people[i].floor << std::endl;

            e2->passengers.push(people[i]);
        }
        else if(people[i].floor >= 11 && people[i].floor <= 15){
        //    std::cout << "Name:: " << people[i].id <<", Floor: " << people[i].floor << std::endl;

            e3->passengers.push(people[i]);
        }
    }
    //Do we need to add a condition if queue is not empty?
    //std::cout<<"test" << std::endl;
    processPeople(e1, 1);
    processPeople(e2, 2);
    processPeople(e3, 3);
}

void ElevatorBay::allocatePeopleInefficient(){
    for(unsigned int i = 0; i < people.size(); i++){
        ie1->passengers.push(people[i]);
    }
    processPeople(ie1, 4);
}


void ElevatorBay::processPeople(Elevator *e, int num){
    int numPassengers = 0;
    std::vector <int> uniqueFloors;
    //std::cout << "About to enter loop" << std::endl;
    //std::cout<<"tmp's size: " << tmp.size() << std::endl;

    //std::cout << "Found something" << std::endl;
    while (!e->passengers.empty()){
        //std::cout << e.passengers.front().id << std::endl;
        int floor = e->passengers.front().floor;
        //std::cout <<"Floor number: " << floor << std::endl;
        bool found = false;
        if (!uniqueFloors.empty()){
            for (unsigned int j  = 0; j <= uniqueFloors.size(); j++){
                //std::cout<<"what is J = " << j << std::endl;
                if (uniqueFloors[j] == floor) {
                    found = true;
                    break;
                }
            }
        }
        //std::cout<<"5 test" << std::endl;
        if(!found) {
            uniqueFloors.push_back(floor);
            //std::cout<<"5 test" << std::endl;
            e->floorsVisited++;
            //std::cout<<"6 test" << std::endl;
        }
        e->passengers.pop();
        numPassengers++;
        if (numPassengers == e->capacity){
            numPassengers = 0;
            uniqueFloors.clear();
            e->floorsVisited++;
        }

    }
    if (numPassengers != 0)
        e->floorsVisited++;
        //new comment
    //std::cout<<"floors visited: "<< e.floorsVisited << std::endl;


}


void ElevatorBay::runElevators(std::string option){
    std::cout << "GOT HERE" << std::endl;
    if(option == "efficient" && !efficientProcessed){
        std::cout << "Running the efficient elevators. . . ";
        allocatePeopleEfficient();
        efficientProcessed = true;
        std::cout << ". . . complete! Results are now available." << std::endl;

    }
    else if(option == "inefficient" && !inefficientProcessed){
        std::cout << "Running the inefficient elevator. . . ";
        allocatePeopleInefficient();
        inefficientProcessed = true;
        std::cout << ". . . complete! Results are now available." << std::endl;
    }
    else{
        std::cout << "Whoops! You have already processed the elevator(s)." << std::endl;
    }
}

void ElevatorBay::printResults(){
    std::string decision;
    if(inefficientProcessed && efficientProcessed){
        std::cout << "With the same data, the inefficient elevator accessed a total of " << std::endl;
        std::cout << ie1->floorsVisited << " unique floors, while the efficient elevators accessed a total of " << std::endl;
        std::cout << e1->floorsVisited+e2->floorsVisited+e3->floorsVisited << " unique floors." << std::endl;
    }
    else if(inefficientProcessed && !efficientProcessed){
        std::cout << "Uh oh! It appears you haven't run the efficient elevators." << std::endl;
        std::cout << "Would you like to process those now? y/n" << std::endl;
        getline(std::cin, decision);
        if(decision == "y")
            allocatePeopleEfficient();
        std::cout << "Ready to go! Printing results . . ." << std::endl;
        printResults();
    }
    else if(!inefficientProcessed && efficientProcessed){
        std::cout << "Uh oh! It appears you haven't run the inefficient elevator." << std::endl;
        std::cout << "Would you like to process that now? y/n" << std::endl;
        getline(std::cin, decision);
        if(decision == "y")
            allocatePeopleInefficient();
        std::cout << "Ready to go! Printing results. . ." << std::endl;
        printResults();
    }
    else{
        std::cout << "Uh oh! It appears you haven't run the inefficient elevator OR the efficient elevators.." << std::endl;
        std::cout << "Would you like to process those now? y/n" << std::endl;
        getline(std::cin, decision);
        if(decision == "y"){
            allocatePeopleInefficient();
            allocatePeopleEfficient();
        }
        std::cout << "Ready to go! Printing results. . ." << std::endl;
        printResults();
    }


}
