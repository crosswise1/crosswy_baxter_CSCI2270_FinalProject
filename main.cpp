#include "include/ElevatorBay.h"
#include <iostream>
#include <fstream>
using namespace std;

string selection;

string mainMenu(){
    cout << "======Main Menu======" << endl;
    cout << "1. View data on people riding elevators" << endl;
    cout << "2. Run inefficient elevators" << endl;
    cout << "3. Run efficient elevators" << endl;
    cout << "4. Compare elevator weights" << endl;
    cout << "5. Average length of trip per passenger" << endl;
    cout << "6. Reset program" << endl;
    cout << "7. Quit" << endl;
    getline(cin, selection);
    return selection;
}

int main(int argc, char* argv[]){
    string fname;
    ElevatorBay eb;
    eb.init();
    string choice = mainMenu();
    while(choice != "7"){
        if(choice == "1")
            eb.printInitialStats();
        else if(choice == "2"){
            eb.runElevators("inefficient");
        }
        else if(choice == "3"){
            cout << "Time to go" << endl;
            eb.runElevators("efficient");
        }
        else if (choice == "4"){
            eb.printResults();
        }
        else if (choice == "5"){

        }
        else if (choice == "6"){
            eb.init();
        }
        choice = mainMenu();
    }
    cout <<"Goodbye!" <<endl;
    return 0;
}
