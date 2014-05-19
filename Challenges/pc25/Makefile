
# CSCI 21, Spring 2014
#
# Programmer: Chee Yee Xiong

FLAGS = -Wall -Wextra -Werror -pedantic -Wno-newline-eof

pc25: pc25.o BSTNode.o
	g++ $(FLAGS) BSTNode.o pc25.o -o pc25

pc25.o: pc25.cpp
	g++ -c $(FLAGS) pc25.cpp -o pc25.o

BSTNode.o: BSTNode.h BSTNode.cpp
	g++ -c $(FLAGS) BSTNode.cpp -o BSTNode.o

clean:
	-rm -f *.o

cleanall:
	-rm -f *.o pc25