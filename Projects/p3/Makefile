# Makefile for project 3
#
# CSCI 21, Spring 2014
#
# Programmer: Chee Yee Xiong

FLAGS = -Wall -Wextra -Werror -pedantic -Wno-newline-eof
# Target for Project 3
# Date completed: 4-17-14

p3: p3.o DLList.o DLNode.o
	g++ $(FLAGS) DLNode.o DLList.o p3.o -o p3

p3.o: p3.cpp
	g++ -c $(FLAGS) p3.cpp -o p3.o

DLList.o: DLList.h DLList.cpp
	g++ -c $(FLAGS) DLList.cpp -o DLList.o

DLNode.o: DLNode.h DLNode.cpp
	g++ -c $(FLAGS) DLNode.cpp -o DLNode.o

clean:
	-rm -f *.o

cleanall:
	-rm -f *.o p3