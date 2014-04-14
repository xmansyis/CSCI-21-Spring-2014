# Makefile for programming challenge 19
#
# CSCI 21, Spring 2014
#
# Programmer: Chee Yee Xiong

FLAGS = -Wall -Wextra -Werror -pedantic -Wno-newline-eof
# Target for programming challenge 19
# Date completed: 4-9-14

pc19: pc19.o SList.o SLNode.o
	g++ $(FLAGS) SLNode.o SList.o pc19.o -o pc19

pc19.o: pc19.cpp
	g++ -c $(FLAGS) pc19.cpp -o pc19.o

SList.o: SList.h SList.cpp
	g++ -c $(FLAGS) SList.cpp -o SList.o

SLNode.o: SLNode.h SLNode.cpp
	g++ -c $(FLAGS) SLNode.cpp -o SLNode.o

clean:
	-rm -f *.o pc19