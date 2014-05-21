#Makefile for programming challenge 29

# CSCI 21, Spring 2014
#
# Programmer: Chee Yee Xiong

FLAGS = -Wall -Wextra -Werror -pedantic -Wno-newline-eof

pc29: pc29.cpp TreasureChest.h TreasureChest.cpp
	g++ $(FLAGS) TreasureChest.cpp pc29.cpp -o pc29

clean:
	-rm -f *.o

cleanall:
	-rm -f *.o pc29