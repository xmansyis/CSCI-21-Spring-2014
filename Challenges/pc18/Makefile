# Makefile for programming challenge 18
#
# CSCI 21, Spring 2014
#
# Programmer: Chee Yee Xiong

FLAGS = -Wall -Wextra -Werror -pedantic
# Target for programming challenge 18
# Date completed: 4-9-14

pc18: pc18.o SList.o SLNode.o
	g++ $(FLAGS) SLNode.o SList.o pc18.o -o pc18

pc18.o: pc18.cpp
	g++ -c $(FLAGS) pc18.cpp -o pc18.o

SList.o: SList.h SList.cpp
	g++ -c $(FLAGS) SList.cpp -o SList.o

SLNode.o: SLNode.h SLNode.cpp
	g++ -c $(FLAGS) SLNode.cpp -o SLNode.o

clean:
	-rm -f *.o pc18