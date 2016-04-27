# Project Summary
*Elevator Optimization:*  
Our project seeks to create a system which will improve upon the current elevator system. If we think about an elevator as having a limited amount of trips/time, etc. and that people want to make use of this functionality, current elevator systems are poorly designed to take advantage of existing information. First, typically, people know what floor they wish to go to before they enter an elevator, and current systems do not take advantage of this information. There is another contraint or factor with elevators which needs to be considered: they face a "rush hour" effect (e.g., most ridership occurs during determinable times). Therefore, given elevator riding trends (most trips occur within preset time periods) and the fact that we can take advantage of rider information before they get onto the elevator, we can design a program that seeks to better optimize trips on an elevator by trying to identify/group riders going to similar floors. By placing riders in these groups onto the same elevator (as opposed to the current system where riders are more or less randomly allocated to elevators based on the time they arrived at the elevator bank), we can achieve an efficiency equivalent to carpooling to work, school, etc.  

# Overview of Methods  

For this program to operate, we created 10 methods inside the ElevatorBay class:  
+ init(): Function that is called for initialization and resetting the program.
+ readFile(): Reads a file's contents and stores each line as a person struct in the people vector.
+ printInitialStats(): Displays initial information about number of total passengers and the distribution of those passengers.
+ allocatePeopleEfficient(): Using the people vector, allocates passengers into three queues -- each corresponding to an elevator -- based on their destination.
+ allocatePeopleInefficient(): Using the people vecotr, allocates passengers into a single queue, simulating the current elevator system.
+ processPeople(): Simulates the elevators once the passengers are in the correct queues. Adds to the floorsVisited variable of the elevator struct that was passed in.
+ processPeopleFloors(): Determines the number of floors visited by each person for the sake of obtaining the average floors visited per person. 
+ runElevators(): Public method that first allocatesPeople, then calls processPeople. In addition to processPeople, it also calls processPeopleFloors.
+ printResults(): Prints the difference in floors visited between the inefficient elevator and the efficient elevator. Less is obviously better. Also handles situations where some of the elevators haven't been processed.  

# How to run

1) Download ZIP   
2) Extract files into directory of your choice   
3) Type "make" into the terminal while in the correct directory.   
4) The "ele" executable should be created. To start the program, simply enter "./ele" into the console.   
5) Enter people1.txt as the filename when prompted.    

You may reset the program whenever you wish in order to test a custom .txt file. When using a different file, make sure to follow the same structure as people1.txt.     

# Contributors

David Crosswy and Landon Baxter
