/*
 * Programming Challenge 25 - UNIT TEST
 */

#include "BSTNode.h"

#include <cassert>
#include <cstdlib>
#include <iostream>
using namespace std;

/* for unit testing -- do not alter */
template <typename X, typename A>
void btassert(A assertion);
void unittest ();

void updateContents (int& contents, int newContents);
void updateLink (BSTNode*& link, BSTNode* newLink);

int main ()
{
	unittest();
	
	return 0;
}

/*
 * Unit testing functions. Do not alter.
 */
void unittest ()
{
	cout << "\nSTARTING UNIT TEST\n\n";

	BSTNode node1;
	BSTNode node2(99);
	BSTNode node3(-1);

	try {
		btassert<bool>(node1.getContents() == 0);
		cout << "Passed TEST 1: default constructor (contents) \n";
	} catch (bool b) {
		cout << "# FAILED TEST 1: default constructor (contents) #\n";
	}

	try {
		btassert<bool>(node1.getLeftChild() == NULL && node1.getRightChild() == NULL);
		cout << "Passed TEST 2: default constructor (leftChild/rightChild) \n";
	} catch (bool b) {
		cout << "# FAILED TEST 2: default constructor (leftChild/rightChild) #\n";
	}

	try {
		btassert<bool>(node2.getContents() == 99);
		cout << "Passed TEST 3: overloaded constructor (contents) \n";
	} catch (bool b) {
		cout << "# FAILED TEST 3: overloaded constructor (contents) #\n";
	}

	try {
		btassert<bool>(node2.getLeftChild() == NULL && node2.getRightChild() == NULL);
		cout << "Passed TEST 4: overloaded constructor (leftChild/rightChild) \n";
	} catch (bool b) {
		cout << "# FAILED TEST 4: overloaded constructor (leftChild/rightChild) #\n";
	}

	node1.setLeftChild(&node2);

	try {
		btassert<bool>(node1.getLeftChild() == &node2);
		cout << "Passed TEST 5: setLeftChild/getLeftChild \n";
	} catch (bool b) {
		cout << "# FAILED TEST 5: setLeftChild/getLeftChild #\n";
	}

	node1.setRightChild(&node3);
	// node 2 is leftChild, node 3 is rightChild

	try {
		btassert<bool>(node1.getRightChild() == &node3);
		cout << "Passed TEST 6: setRightChild/getRightChild \n";
	} catch (bool b) {
		cout << "# FAILED TEST 6: setRightChild/getRightChild #\n";
	}

	// swap children -- node3 leftChild, node2 rightChild
	updateLink(node1.getLeftChild(), &node3);
	updateLink(node1.getRightChild(), &node2);

	try {
		btassert<bool>(node1.getLeftChild() == &node3 && node1.getRightChild() == &node2);
		cout << "Passed TEST 7: getLeftChild&/getRightChild& \n";
	} catch (bool b) {
		cout << "# FAILED TEST 7: getLeftChild&/getRightChild& #\n";
	}

	node1.setContents(42);

	try {
		btassert<bool>(node1.getContents() == 42);
		cout << "Passed TEST 8: setContents/getContents \n";
	} catch (bool b) {
		cout << "# FAILED TEST 8: setContents/getContents #\n";
	}

	updateContents(node1.getContents(), 24);

	try {
		btassert<bool>(node1.getContents() == 24);
		cout << "Passed TEST 9: getContents& \n";
	} catch (bool b) {
		cout << "# FAILED TEST 9: getContents& #\n";
	}

	cout << "\nUNIT TEST COMPLETE\n\n";
}

template <typename X, typename A>
void btassert (A assertion)
{
    if (!assertion)
		throw X();
}

void updateContents (int& contents, int newContents)
{
	contents = newContents;
}

void updateLink (BSTNode*& link, BSTNode* newLink)
{
	link = newLink;
}