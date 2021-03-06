#include "../include/ElevatorBay.h"
#include<queue>
#include<vector>
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<iomanip>

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
    /*for (int floor = 0; floor < buildingHeight; floor++){
        for (unsigned int index = 0; index < people.size(); index++){
            if (people[index].floor == floor+1)
                printPeopleArray[floor]++;
        }

        std::cout << "Floor ";
        std::cout << std::setw(2) << std::setfill('0') << floor+1;
        std::cout << ":";
        for (int x = 0; x < printPeopleArray[floor]; x++)
            std::cout<<'x';
        std::cout<<std::endl;
    }*/
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
}

void ElevatorBay::allocatePeopleInefficient(){
    for(unsigned int i = 0; i < people.size(); i++){
        ie1->passengers.push(people[i]);
    }
}


void ElevatorBay::processPeople(Elevator *e){
    int numPassengers = 0;
    std::vector <int> uniqueFloors;
    while (!e->passengers.empty()){
        int floor = e->passengers.front().floor;
        bool found = false;
        if (!uniqueFloors.empty()){
            for (unsigned int j  = 0; j <= uniqueFloors.size(); j++){
                if (uniqueFloors[j] == floor) {
                    found = true;
                    break;
                }
            }
        }
        if(!found) {
            uniqueFloors.push_back(floor);
            e->floorsVisited++;
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
}

void ElevatorBay::processPeopleFloors(Elevator *e){
    int peopleFloors[buildingHeight]; //needs to be linked to the floors in the building
    int numPassengers = 0;
    int counter1 = 1;
    for (int x = 0; x < buildingHeight; x++)
        peopleFloors[x] = 0;
    while (!e->passengers.empty()){
        //std::cout << "WHILE LOOP" << std::endl;
        int floor = e->passengers.front().floor;
        peopleFloors[floor] = peopleFloors[floor] + 1;
        e->passengers.pop();
        numPassengers++;
        counter1 = 1;
        if(numPassengers == e->capacity){
            for (int y = 0; y < 16; y++){
                if (peopleFloors[y] > 0){
                    e->totalPeopleFloors += ((counter1) * peopleFloors[y]);
                    counter1++;
                    //std::cout << "Floor weights: " << floorWeightsPerTrip << std::endl;
                }
            }
            numPassengers = 0;
            for (int x = 0; x < buildingHeight; x++)
                peopleFloors[x] = 0;
        }
    }
    counter1 = 1;
    for (int y = 0; y < 16; y++){
        if (peopleFloors[y] > 0){
            e->totalPeopleFloors += ((counter1) * peopleFloors[y]);
            counter1++;
            //std::cout << "Floor weights: " << floorWeightsPerTrip << std::endl;
        }
    }
}


void ElevatorBay::runElevators(std::string option){
    if(option == "efficient" && !efficientProcessed){
        std::cout << "Running the efficient elevators. . . ";
        allocatePeopleEfficient();
        processPeople(e1);
        processPeople(e2);
        processPeople(e3);
        allocatePeopleEfficient();
        processPeopleFloors(e1);
        processPeopleFloors(e2);
        processPeopleFloors(e3);
        efficientProcessed = true;
        //std::cout << e1->floorsVisited+e2->floorsVisited+e3->floorsVisited << std::endl;
        std::cout << ". . . complete! Results are now available for the efficient elevators." << std::endl;
        if(inefficientProcessed)
            std::cout << "You can now compare the floors visited by each system! Returning to main menu." << std::endl;

    }
    else if(option == "inefficient" && !inefficientProcessed){
        std::cout << "Running the inefficient elevator. . . ";
        allocatePeopleInefficient();
        processPeople(ie1);
        allocatePeopleInefficient();
        processPeopleFloors(ie1);
        //std::cout << ie1->floorsVisited << std::endl;
        inefficientProcessed = true;
        std::cout << ". . . complete! Results are now available for the inefficient elevator." << std::endl;
        if(efficientProcessed)
            std::cout << "You can now compare the floors visited by each system! Returning to main menu." << std::endl;

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
        std::cout << std::endl;
        std::cout << "Running the same number of people efficient elevators visited " << ie1->floorsVisited - (e1->floorsVisited+e2->floorsVisited+e3->floorsVisited) << " fewer floors" << std::endl;
    }
    else if(inefficientProcessed && !efficientProcessed){
        std::cout << "Uh oh! It appears you haven't run the efficient elevators." << std::endl;
        std::cout << "Would you like to process those now? y/n" << std::endl;
        getline(std::cin, decision);
        if(decision == "y"){
            runElevators("efficient");
            efficientProcessed = true;
            std::cout << "Ready to go! Printing results. . ." << std::endl;
            printResults();
        }
        else{
            std::cout << "No problem! Run the elevators when ready." << std::endl;
        }
    }
    else if(!inefficientProcessed && efficientProcessed){
        std::cout << "Uh oh! It appears you haven't run the inefficient elevator." << std::endl;
        std::cout << "Would you like to process that now? y/n" << std::endl;
        getline(std::cin, decision);
        if(decision == "y"){
            runElevators("inefficient");
            inefficientProcessed = true;
            std::cout << "Ready to go! Printing results. . ." << std::endl;
            printResults();
        }
        else{
            std::cout << "No problem! Run the elevators when ready." << std::endl;
        }

    }
    else{
        std::cout << "Uh oh! It appears you haven't run the inefficient elevator OR the efficient elevators.." << std::endl;
        std::cout << "Would you like to process those now? y/n" << std::endl;
        getline(std::cin, decision);
        if(decision == "y"){
            runElevators("efficient");
            efficientProcessed = true;
            runElevators("inefficient");
            inefficientProcessed = true;
            std::cout << "Ready to go! Printing results. . ." << std::endl;
            printResults();
        }
    }
}

void ElevatorBay::printAverage(){
    if(inefficientProcessed && efficientProcessed){
        double iSum = ie1->totalPeopleFloors;
        double eSum = e1->totalPeopleFloors + e2->totalPeopleFloors + e3->totalPeopleFloors;
        std::cout << "The average number of floors visited by each passenger for each case is:" << std::endl;
        std::cout << "Efficient Elevators: " << eSum/people.size() << std::endl;
        std::cout << "Inefficient Elevator: " << iSum/people.size() << std::endl;
    }
    else{
        std::cout << "Results not available. Please process the elevators." << std::endl;
    }

}
