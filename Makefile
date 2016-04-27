OBJS = ElevatorBay.o main.o
CPPFLAGS = -Wall -std=c++11
PROG = elevator
CC = g++

$(PROG): $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

ElevatorBay.o: include/ElevatorBay.h src/ElevatorBay.cpp
	$(CC) $(CPPFLAGS) -c src/ElevatorBay.cpp

main.o: main.cpp
	$(CC) $(CPPFLAGS) -c main.cpp

clean:
	$(RM) $(PROG) $(OBJS)
