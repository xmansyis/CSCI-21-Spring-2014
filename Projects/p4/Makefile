# Makefile for project 4
#
# CSCI 21, Spring 2014
#
# Programmer: Chee Yee Xiong
# Date completed: 5-10-14

FLAGS = -Wall -Wextra -Werror -pedantic -Wno-newline-eof

p4: p4.o Word.o
	g++ $(FLAGS) p4.o Word.o -o p4

p4.o: p4.cpp Word.h BSTNode.h BSTree.h
	g++ $(FLAGS) -c p4.cpp -o p4.o

Word.o: Word.h Word.cpp
	g++ $(FLAGS) -c Word.cpp -o Word.o

clean:
	-rm -f *.o

cleanall:
	-rm -f *.o p4