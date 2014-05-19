#Makefile for programming challenge 28

# CSCI 21, Spring 2014
#
# Programmer: Chee Yee Xiong

FLAGS = -Wall -Wextra -Werror -pedantic -Wno-newline-eof

pc28: pc28.o Item.o FoodItem.o MagicItem.o
	g++ $(Flag) pc28.o MagicItem.o FoodItem.o Item.o -o pc28

pc28.o: pc28.cpp Item.h FoodItem.h MagicItem.h
	g++ $(Flag) -c pc28.cpp -o pc28.o

Item.o: Item.cpp Item.h
	g++ $(Flag) -c Item.cpp -o Item.o

FoodItem.o: FoodItem.cpp FoodItem.h
	g++ $(Flag) -c FoodItem.cpp -o FoodItem.o
	
MagicItem.o: MagicItem.cpp MagicItem.h
	g++ $(Flag) -c MagicItem.cpp -o MagicItem.o

clean:
	-rm -f *.o

cleanall:
	-rm -f *.o pc28