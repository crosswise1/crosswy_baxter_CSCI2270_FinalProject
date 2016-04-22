#include "../include/ElevatorBay.h"
#include<queue>
#include<vector>
#include<iostream>
#include<fstream>

ElevatorBay::ElevatorBay(std::string fname){
    readFile(fname);
}
ElevatorBay::~ElevatorBay(){
    //nothing
}
void ElevatorBay::readFile(std::string fname){
    std::ifstream inFile;
    inFile.open(fname);
    if(inFile.good()){

    }
}
