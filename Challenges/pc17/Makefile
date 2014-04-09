# Makefile for programming challenge 17
#
# CSCI 21, Spring 2014
#
# Programmer: Chee Yee Xiong

FLAGS = -Wall -Wextra -Werror -pedantic
# Target for programming challenge 17
# Date completed: 4-6-14

pc17: pc17.o SLNode.o
	g++ $(FLAGS) SLNode.o pc17.o -o pc17

pc17.o: pc17.cpp
	g++ -c $(FLAGS) pc17.cpp -o pc17.o

SLNode.o: SLNode.h SLNode.cpp
	g++ -c $(FLAGS) SLNode.cpp -o SLNode.o
