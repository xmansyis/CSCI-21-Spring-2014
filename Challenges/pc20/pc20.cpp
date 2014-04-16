/*
 * Programming Challenge 20 - UNIT TEST
 */

#include "SList.h"

#include <cassert>
#include <cstdlib>
#include <iostream>
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
	
	SList list;
	
	try {
		btassert<bool>(list.getSize() == 0);
		cout << "Passed TEST 1: default constructor (size) \n";
	} catch (bool b) {
		cout << "# FAILED TEST 1: default constructor (size) #\n";
	}
	
	try {
		btassert<bool>(list.toString() == "");
		cout << "Passed TEST 2: toString \n";
	} catch (bool b) {
		cout << "# FAILED TEST 2: toString #\n";
	}
	
	list.insert(10);
	try {
		btassert<bool>(list.getSize() == 1 && list.toString() == "10");
		cout << "Passed TEST 3: insert(10)/getSize/toString \n";
	} catch (bool b) {
		cout << "# FAILED TEST 3: insert(10)/getSize/toString #\n";
	}
	
	list.insert(50);
	try {
		btassert<bool>(list.getSize() == 2 && list.toString() == "10,50");
		cout << "Passed TEST 4: insert(50)/getSize/toString \n";
	} catch (bool b) {
		cout << "# FAILED TEST 4: insert(50)/getSize/toString #\n";
	}
	
	list.insert(30);
	try {
		btassert<bool>(list.getSize() == 3 && list.toString() == "10,30,50");
		cout << "Passed TEST 5: insert(30)/getSize/toString \n";
	} catch (bool b) {
		cout << "# FAILED TEST 5: insert(30)/getSize/toString #\n";
	}
	
	list.insert(5);
	try {
		btassert<bool>(list.getSize() == 4 && list.toString() == "5,10,30,50");
		cout << "Passed TEST 6: insert(5)/getSize/toString \n";
	} catch (bool b) {
		cout << "# FAILED TEST 6: insert(5)/getSize/toString #\n";
	}
	
	list.insert(55);
	try {
		btassert<bool>(list.getSize() == 5 && list.toString() == "5,10,30,50,55");
		cout << "Passed TEST 7: insert(55)/getSize/toString \n";
	} catch (bool b) {
		cout << "# FAILED TEST 7: insert(55)/getSize/toString #\n";
	}
	
	list.insert(20);
	try {
		btassert<bool>(list.getSize() == 6 && list.toString() == "5,10,20,30,50,55");
		cout << "Passed TEST 8: insert(20)/getSize/toString \n";
	} catch (bool b) {
		cout << "# FAILED TEST 8: insert(20)/getSize/toString #\n";
	}
	
	list.insert(40);
	try {
		btassert<bool>(list.getSize() == 7 && list.toString() == "5,10,20,30,40,50,55");
		cout << "Passed TEST 9: insert(40)/getSize/toString \n";
	} catch (bool b) {
		cout << "# FAILED TEST 9: insert(40)/getSize/toString #\n";
	}
	
	list.insert(30);
	try {
		btassert<bool>(list.getSize() == 8 && list.toString() == "5,10,20,30,30,40,50,55");
		cout << "Passed TEST 10: insert(30)/getSize/toString \n";
	} catch (bool b) {
		cout << "# FAILED TEST 10: insert(30)/getSize/toString #\n";
	}
	
	list.insert(5);
	try {
		btassert<bool>(list.getSize() == 9 && list.toString() == "5,5,10,20,30,30,40,50,55");
		cout << "Passed TEST 11: insert(5)/getSize/toString \n";
	} catch (bool b) {
		cout << "# FAILED TEST 11: insert(5)/getSize/toString #\n";
	}
	
	try {
		btassert<bool>(list.removeFirst(1) == false);
		cout << "Passed TEST 12: removeFirst(1) \n";
	} catch (bool b) {
		cout << "# FAILED TEST 12: removeFirst(1) #\n";
	}
	
	try {
		btassert<bool>(list.removeFirst(5) == true && list.getSize() == 8 && list.toString() == "5,10,20,30,30,40,50,55");
		cout << "Passed TEST 13: removeFirst(5)/getSize/toString \n";
	} catch (bool b) {
		cout << "# FAILED TEST 13: removeFirst(5)/getSize/toString #\n";
	}
	
	try {
		btassert<bool>(list.removeFirst(30) == true && list.getSize() == 7 && list.toString() == "5,10,20,30,40,50,55");
		cout << "Passed TEST 14: removeFirst(30)/getSize/toString \n";
	} catch (bool b) {
		cout << "# FAILED TEST 14: removeFirst(30)/getSize/toString #\n";
	}
	
	try {
		btassert<bool>(list.removeFirst(30) == true && list.getSize() == 6 && list.toString() == "5,10,20,40,50,55");
		cout << "Passed TEST 15: removeFirst(30)/getSize/toString \n";
	} catch (bool b) {
		cout << "# FAILED TEST 15: removeFirst(30)/getSize/toString #\n";
	}
	
	try {
		btassert<bool>(list.removeFirst(55) == true && list.getSize() == 5 && list.toString() == "5,10,20,40,50");
		cout << "Passed TEST 16: removeFirst(55)/getSize/toString \n";
	} catch (bool b) {
		cout << "# FAILED TEST 16: removeFirst(55)/getSize/toString #\n";
	}
	
	try {
		btassert<bool>(list.removeFirst(10) == true && list.getSize() == 4 && list.toString() == "5,20,40,50");
		cout << "Passed TEST 17: removeFirst(10)/getSize/toString \n";
	} catch (bool b) {
		cout << "# FAILED TEST 17: removeFirst(10)/getSize/toString #\n";
	}
	
	list.removeHead();
	try {
		btassert<bool>(list.getSize() == 3 && list.toString() == "20,40,50");
		cout << "Passed TEST 18: removeHead/getSize/toString \n";
	} catch (bool b) {
		cout << "# FAILED TEST 18: removeHead/getSize/toString #\n";
	}
	
	list.removeTail();
	try {
		btassert<bool>(list.getSize() == 2 && list.toString() == "20,40");
		cout << "Passed TEST 19: removeTail/getSize/toString \n";
	} catch (bool b) {
		cout << "# FAILED TEST 19: removeTail/getSize/toString #\n";
	}
	
	list.clear();
	try {
		btassert<bool>(list.getSize() == 0 && list.toString() == "");
		cout << "Passed TEST 20: clear/getSize/toString \n";
	} catch (bool b) {
		cout << "# FAILED TEST 20: clear/getSize/toString #\n";
	}
	
	cout << "\nUNIT TEST COMPLETE\n\n";
}

template <typename X, typename A>
void btassert (A assertion)
{
    if (!assertion)
		throw X();
}