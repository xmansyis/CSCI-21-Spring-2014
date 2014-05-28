# Makefile for programming challenge 22
#
# CSCI 21, Spring 2014
#
# Programmer: Chee Yee Xiong

FLAGS = -Wall -Wextra -Werror -pedantic -Wno-newline-eof
# Target for programming challenge 22
# Date completed: 4-11-14

pc22: pc22.o
	g++ $(FLAGS) pc22.o -o pc22

pc22.o: pc22.cpp
	g++ -c $(FLAGS) pc22.cpp -o pc22.o

clean:
	-rm -f *.o pc22