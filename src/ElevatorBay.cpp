#include "ElevatorBay.h"
#include<queue>
#include<vector>
#include<iostream>
#include<fstream>

ElevatorBay::ElevatorBay(std::string fname){
    readFile(fname);
}

void ElevatorBay::readFile(std::string fname){
    ifstream inFile;
    inFile.open(fname);
    if(inFile.good()){
        
    }
}
