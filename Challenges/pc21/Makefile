# Makefile for programming challenge 21
#
# CSCI 21, Spring 2014
#
# Programmer: Chee Yee Xiong

FLAGS = -Wall -Wextra -Werror -pedantic -Wno-newline-eof
# Target for programming challenge 21
# Date completed: 4-9-14

pc21: pc21.o
	g++ $(FLAGS) pc21.o -o pc21

pc21.o: pc21.cpp
	g++ -c $(FLAGS) pc21.cpp -o pc21.o

clean:
	-rm -f *.o pc21