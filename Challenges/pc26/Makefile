
# CSCI 21, Spring 2014
#
# Programmer: Chee Yee Xiong

FLAGS = -Wall -Wextra -Werror -pedantic -Wno-newline-eof

pc26: pc26.o BSTree.o BSTNode.o
	g++ $(FLAGS) BSTNode.o BSTree.o pc26.o -o pc26

pc26.o: pc26.cpp
	g++ -c $(FLAGS) pc26.cpp -o pc26.o

BSTree.o: BSTree.h BSTree.cpp
	g++ -c $(FLAGS) BSTree.cpp -o BSTree.o

BSTNode.o: BSTNode.h BSTNode.cpp
	g++ -c $(FLAGS) BSTNode.cpp -o BSTNode.o

clean:
	-rm -f *.o

cleanall:
	-rm -f *.o pc26