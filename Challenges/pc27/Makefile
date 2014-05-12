
# CSCI 21, Spring 2014
#
# Programmer: Chee Yee Xiong

FLAGS = -Wall -Wextra -Werror -pedantic -Wno-newline-eof

pc27: pc27.o BSTree.o BSTNode.o
	g++ $(FLAGS) BSTNode.o BSTree.o pc27.o -o pc27

pc27.o: pc27.cpp
	g++ -c $(FLAGS) pc27.cpp -o pc27.o

BSTree.o: BSTree.h BSTree.cpp
	g++ -c $(FLAGS) BSTree.cpp -o BSTree.o

BSTNode.o: BSTNode.h BSTNode.cpp
	g++ -c $(FLAGS) BSTNode.cpp -o BSTNode.o

clean:
	-rm -f *.o

cleanall:
	-rm -f *.o pc27