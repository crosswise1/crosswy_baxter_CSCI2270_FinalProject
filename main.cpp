#include "include/ElevatorBay.h"
#include <iostream>

using namespace std;

string selection;

string mainMenu(){
    cout << "======Main Menu======" << endl;
    cout << "1. View data on people riding elevators" << endl;
    cout << "2. Run inefficient elevators" << endl;
    cout << "3. Run efficient elevators" << endl;
    cout << "4. Compare elevator weights" << endl;
    cout << "5. Average length of trip per passenger" << endl;
    cout << "6. Quit" << endl;
    getline(cin, selection);
    return selection;
}

int main(int argc, char* argv[]){
    string fname = argv[1];
    ElevatorBay eb(fname);
    string choice = mainMenu();
    while(choice != "6"){
        if(choice == "1")
            eb.printInitialStats();
        else if(choice == "2"){

        }
        else if(choice == "3"){

        }
        else if (choice == "4"){

        }
        else if (choice == "5"){

        }
        else if (choice == "6"){

        }
        choice = mainMenu();
    }
    cout <<"Goodbye!" <<endl;
    return 0;
}
