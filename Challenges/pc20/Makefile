# Makefile for programming challenge 20
#
# CSCI 21, Spring 2014
#
# Programmer: Chee Yee Xiong

FLAGS = -Wall -Wextra -Werror -pedantic -Wno-newline-eof
# Target for programming challenge 20
# Date completed: 4-16-14

pc20: pc20.o SList.o SLNode.o
	g++ $(FLAGS) SLNode.o SList.o pc20.o -o pc20

pc20.o: pc20.cpp
	g++ -c $(FLAGS) pc20.cpp -o pc20.o

SList.o: SList.h SList.cpp
	g++ -c $(FLAGS) SList.cpp -o SList.o

SLNode.o: SLNode.h SLNode.cpp
	g++ -c $(FLAGS) SLNode.cpp -o SLNode.o

clean:
	-rm -f *.o pc20