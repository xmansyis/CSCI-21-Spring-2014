# Makefile for programming project 2
#
# CSCI 21, Spring 2014
#
# Programmer: Chee Yee Xiong
# Target for project 2
# Date completed: 4-3-14

FLAGS = -Wall -Wextra -Werror -pedantic

p2: p2.o Prize.o Box.o
	g++ $(FLAGS) Prize.o Box.o p2.o -o p2

p2.o: p2.cpp
	g++ -c $(FLAGS) p2.cpp -o p2.o

Prize.o: Prize.h Prize.cpp
	g++ -c $(FLAGS) Prize.cpp -o Prize.o

Box.o: Box.h Box.cpp
	g++ -c $(FLAGS) Box.cpp -o Box.o
    
clean:
	rm -f *.o



