/*
 * Programming Challenge 26 - UNIT TEST
 */

#include "BSTree.h"

#include <cassert>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <streambuf>
using namespace std;

/* for unit testing -- do not alter */
template <typename X, typename A>
void btassert(A assertion);
void unittest ();

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

	BSTree tree;

	try {
		btassert<bool>(tree.getSize() == 0);
		cout << "Passed TEST 1: default constructor/getSize \n";
	} catch (bool b) {
		cout << "# FAILED TEST 1: default constructor/getSize #\n";
	}

	streambuf* oldCout = cout.rdbuf();
	ostringstream captureCout;
	cout.rdbuf(captureCout.rdbuf());

	tree.insert(50);
	tree.inOrder();
	cout.rdbuf(oldCout);
	try {
		btassert<bool>(tree.getSize() == 1 && captureCout.str() == "50 ");
		cout << "Passed TEST 2: insert(50)/getSize/inOrder \n";
	} catch (bool b) {
		cout << "# FAILED TEST 2: insert(50)/getSize/inOrder #\n";
	}

	captureCout.str("");
	cout.rdbuf(captureCout.rdbuf());
	tree.insert(20);
	tree.inOrder();
	cout.rdbuf(oldCout);
	try {
		btassert<bool>(tree.getSize() == 2 && captureCout.str() == "20 50 ");
		cout << "Passed TEST 3: insert(20)/getSize/inOrder \n";
	} catch (bool b) {
		cout << "# FAILED TEST 3: insert(20)/getSize/inOrder #\n";
	}

	captureCout.str("");
	cout.rdbuf(captureCout.rdbuf());
	tree.insert(80);
	tree.inOrder();
	cout.rdbuf(oldCout);
	try {
		btassert<bool>(tree.getSize() == 3 && captureCout.str() == "20 50 80 ");
		cout << "Passed TEST 4: insert(80)/getSize/inOrder \n";
	} catch (bool b) {
		cout << "# FAILED TEST 4: insert(80)/getSize/inOrder #\n";
	}

	captureCout.str("");
	cout.rdbuf(captureCout.rdbuf());
	tree.insert(30);
	tree.inOrder();
	cout.rdbuf(oldCout);
	try {
		btassert<bool>(tree.getSize() == 4 && captureCout.str() == "20 30 50 80 ");
		cout << "Passed TEST 5: insert(30)/getSize/inOrder \n";
	} catch (bool b) {
		cout << "# FAILED TEST 5: insert(30)/getSize/inOrder #\n";
	}

	captureCout.str("");
	cout.rdbuf(captureCout.rdbuf());
	tree.insert(70);
	tree.inOrder();
	cout.rdbuf(oldCout);
	try {
		btassert<bool>(tree.getSize() == 5 && captureCout.str() == "20 30 50 70 80 ");
		cout << "Passed TEST 6: insert(70)/getSize/inOrder \n";
	} catch (bool b) {
		cout << "# FAILED TEST 6: insert(70)/getSize/inOrder #\n";
	}

	captureCout.str("");
	cout.rdbuf(captureCout.rdbuf());
	tree.insert(0);
	tree.inOrder();
	cout.rdbuf(oldCout);
	try {
		btassert<bool>(tree.getSize() == 6 && captureCout.str() == "0 20 30 50 70 80 ");
		cout << "Passed TEST 7: insert(0)/getSize/inOrder \n";
	} catch (bool b) {
		cout << "# FAILED TEST 7: insert(0)/getSize/inOrder #\n";
	}

	captureCout.str("");
	cout.rdbuf(captureCout.rdbuf());
	tree.insert(100);
	tree.inOrder();
	cout.rdbuf(oldCout);
	try {
		btassert<bool>(tree.getSize() == 7 && captureCout.str() == "0 20 30 50 70 80 100 ");
		cout << "Passed TEST 8: insert(100)/getSize/inOrder \n";
	} catch (bool b) {
		cout << "# FAILED TEST 8: insert(100)/getSize/inOrder #\n";
	}

	try {
		btassert<bool>(tree.insert(50) == false);
		cout << "Passed TEST 9: insert(50) \n";
	} catch (bool b) {
		cout << "# FAILED TEST 9: insert(50) #\n";
	}

	tree.clear();
	try {
		btassert<bool>(tree.getSize() == 0);
		cout << "Passed TEST 10: clear/getSize \n";
	} catch (bool b) {
		cout << "# FAILED TEST 10: clear/getSize #\n";
	}
	
	cout << "\nINSERT STRESS TEST\n\n";
	try {
		btassert<bool>(tree.insert(50) == true && tree.insert(50) == false && 
			tree.insert(25) == true && tree.insert(25) == false && 
			tree.insert(75) == true && tree.insert(75) == false && 
			tree.insert(30) == true && tree.insert(30) == false && 
			tree.insert(29) == true && tree.insert(29) == false && 
			tree.insert(31) == true && tree.insert(31) == false && 
			tree.insert(32) == true && tree.insert(32) == false && 
			tree.insert(33) == true && tree.insert(33) == false && 
			tree.insert(34) == true && tree.insert(34) == false);
		cout << "Passed TEST 11: insert stress test \n";
	} catch (bool b) {
		cout << "# FAILED TEST 11: insert stress test #\n";
	}

	cout << "\nUNIT TEST COMPLETE\n\n";
}
	
template <typename X, typename A>
void btassert (A assertion)
{
    if (!assertion)
		throw X();
}