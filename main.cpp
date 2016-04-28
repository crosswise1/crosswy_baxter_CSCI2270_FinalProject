#include "include/ElevatorBay.h"
#include <iostream>
#include <fstream>
using namespace std;

/*Documentation:
===Welcome to our program!===
    To get started, enter the name of a txt file that
    contains the information about the passengers and
    their destinations. See people1.txt for the
    structure of the txt file.

    A main menu will now display. First things first, let's check the initial
    conditions by typing 1 and pressing enter. You will see the total number
    of passengers that were read in from the file as well as the distribution
    of passengers throughout all floors.

    Great, so now our passengers are ready for the time of their lives. To start
    the simulation of the elevators transporting the passengers given by the txt
    file, select option 2, then option 3.

    At this point, we're ready to analyze the efficiency of each elevator system
    (by now you're probably beginning to understand why we made this!).
    To do just that, select option 4. This will tell you the number of floors
    that each elevator system visited throughout the day. Obviously less floors
    means more efficient, and you should observe that the inefficient elevator is
    in fact more inefficient than the efficient ones.

    But it doesn't stop there! Select option 5 to view the average numbers of
    floors visited by a passenger before they reached their destinations. Again,
    the efficient elevators should result in an average that is less than that
    of the inefficient elevators.

    Lastly, if you wish to test a different txt file, do not fear! You need not
    restart the program. Instead, simply select option 6. The program should
    essentially restart.


    Thanks for reading! Hope you enjoy the program.
    -David and Landon
*/
string mainMenu();

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
            eb.runElevators("efficient");
        }
        else if (choice == "4"){
            eb.printResults();
        }
        else if (choice == "5"){
            eb.printAverage();
        }
        else if (choice == "6"){
            eb.init();
        }
        choice = mainMenu();
    }
    cout <<"Goodbye!" <<endl;
    return 0;
}

string mainMenu(){
    string selection;
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
