/*
 * Programming Challenge 27 - UNIT TEST
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
	
	streambuf* oldCout = cout.rdbuf();
	ostringstream captureCout;
	
	try {
		btassert<bool>(!tree.remove(1));
		cout << "Passed TEST 1: empty tree/remove \n";
	} catch (bool b) {
		cout << "# FAILED TEST 1: empty tree/remove #\n";
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
		cout << "Passed TEST 2: insert stress test \n";
	} catch (bool b) {
		cout << "# FAILED TEST 2: insert stress test #\n";
	}
	
	tree.clear();
	
	cout << "\nREGULAR TESTS\n\n";
	
	cout.rdbuf(captureCout.rdbuf());
	tree.insert(10);
	tree.inOrder();
	cout.rdbuf(oldCout);
	try {
		btassert<bool>(captureCout.str() == "10 " && tree.getSize() == 1 && tree.remove(10) && tree.getSize() == 0);
		cout << "Passed TEST 3: single node/remove/getSize \n";
	} catch (bool b) {
		cout << "# FAILED TEST 3: single node/remove/getSize #\n";
	}
	
	captureCout.str("");
	cout.rdbuf(captureCout.rdbuf());
	tree.insert(10);
	tree.insert(5);
	tree.insert(15);
	tree.inOrder();
	cout.rdbuf(oldCout);
	try {
		btassert<bool>(captureCout.str() == "5 10 15 " && tree.getSize() == 3 && !tree.remove(1));
		cout << "Passed TEST 4: remove non-existent target \n";
	} catch (bool b) {
		cout << "# FAILED TEST 4: remove non-existent target #\n";
	}
	
	try {
		btassert<bool>(tree.remove(5) && tree.getSize() == 2);
		cout << "Passed TEST 5: remove left child \n";
	} catch (bool b) {
		cout << "# FAILED TEST 5: remove left child #\n";
	}
	
	captureCout.str("");
	cout.rdbuf(captureCout.rdbuf());
	tree.inOrder();
	cout.rdbuf(oldCout);
	tree.insert(5);
	try {
		btassert<bool>(captureCout.str() == "10 15 " && tree.getSize() == 3 && tree.remove(15) && tree.getSize() == 2);
		cout << "Passed TEST 6: remove right child \n";
	} catch (bool b) {
		cout << "# FAILED TEST 6: remove right child #\n";
	}
	
	captureCout.str("");
	cout.rdbuf(captureCout.rdbuf());
	tree.inOrder();
	cout.rdbuf(oldCout);
	tree.insert(15);
	try {
		btassert<bool>(captureCout.str() == "5 10 " && tree.getSize() == 3 && tree.remove(10) && tree.getSize() == 2);
		cout << "Passed TEST 7: remove root (has left child) \n";
	} catch (bool b) {
		cout << "# FAILED TEST 7: remove root (has left child) #\n";
	}
	
	captureCout.str("");
	cout.rdbuf(captureCout.rdbuf());
	tree.inOrder();
	cout.rdbuf(oldCout);
	tree.insert(20);
	try {
		btassert<bool>(captureCout.str() == "5 15 " && tree.getSize() == 3 && tree.remove(5) && tree.getSize() == 2);
		cout << "Passed TEST 8: remove root (no left child) \n";
	} catch (bool b) {
		cout << "# FAILED TEST 8: remove root (no left child) #\n";
	}
	
	captureCout.str("");
	cout.rdbuf(captureCout.rdbuf());
	tree.insert(10);
	tree.inOrder();
	cout.rdbuf(oldCout);
	try {
		btassert<bool>(captureCout.str() == "10 15 20 " && tree.getSize() == 3);
		cout << "Passed TEST 9: size and in order output \n";
	} catch (bool b) {
		cout << "# FAILED TEST 9: size and in order output #\n";
	}
	
	try {
		btassert<bool>(!tree.remove(1));
		cout << "Passed TEST 10: remove non existent value \n";
	} catch (bool b) {
		cout << "# FAILED TEST 10: remove non existent value #\n";
	}
	
	try {
		btassert<bool>(!tree.remove(100));
		cout << "Passed TEST 11: remove non existent value \n";
	} catch (bool b) {
		cout << "# FAILED TEST 11: remove non existent value #\n";
	}
	
	try {
		btassert<bool>(!tree.remove(11));
		cout << "Passed TEST 12: remove non existent value \n";
	} catch (bool b) {
		cout << "# FAILED TEST 12: remove non existent value #\n";
	}
	
	try {
		btassert<bool>(!tree.remove(19));
		cout << "Passed TEST 13: remove non existent value \n";
	} catch (bool b) {
		cout << "# FAILED TEST 13: remove non existent value #\n";
	}
	
	bool removed = tree.remove(15);
	captureCout.str("");
	cout.rdbuf(captureCout.rdbuf());
	tree.inOrder();
	cout.rdbuf(oldCout);
	try {
		btassert<bool>(removed && captureCout.str() == "10 20 " && tree.getSize() == 2);
		cout << "Passed TEST 14: remove \n";
	} catch (bool b) {
		cout << "# FAILED TEST 14: remove #\n";
	}
	
	removed = tree.remove(10);
	captureCout.str("");
	cout.rdbuf(captureCout.rdbuf());
	tree.inOrder();
	cout.rdbuf(oldCout);
	try {
		btassert<bool>(removed && captureCout.str() == "20 " && tree.getSize() == 1);
		cout << "Passed TEST 15: remove \n";
	} catch (bool b) {
		cout << "# FAILED TEST 15: remove #\n";
	}
	
	removed = tree.remove(20);
	captureCout.str("");
	cout.rdbuf(captureCout.rdbuf());
	tree.inOrder();
	cout.rdbuf(oldCout);
	try {
		btassert<bool>(removed && captureCout.str() == "" && tree.getSize() == 0);
		cout << "Passed TEST 16: remove \n";
	} catch (bool b) {
		cout << "# FAILED TEST 16: remove #\n";
	}
	
	cout << "\nUNIT TEST COMPLETE\n\n";
}
	
template <typename X, typename A>
void btassert (A assertion)
{
    if (!assertion)
		throw X();
}
