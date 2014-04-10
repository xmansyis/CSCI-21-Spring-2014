/*
 * Programming Challenge 18 - UNIT TEST
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

	list.removeHead();
	try {
		btassert<bool>(list.getSize() == 0);
		cout << "Passed TEST 3: removeHead \n";
	} catch (bool b) {
		cout << "# FAILED TEST 3: removeHead #\n";
	}

	list.insertHead(1);
	try {
		btassert<bool>(list.getSize() == 1);
		cout << "Passed TEST 4: insertHead \n";
	} catch (bool b) {
		cout << "# FAILED TEST 4: insertHead #\n";
	}

	try {
		btassert<bool>(list.toString() == "1");
		cout << "Passed TEST 5: toString \n";
	} catch (bool b) {
		cout << "# FAILED TEST 5: toString #\n";
	}

	list.removeHead();
	try {
		btassert<bool>(list.getSize() == 0);
		cout << "Passed TEST 6: removeHead \n";
	} catch (bool b) {
		cout << "# FAILED TEST 6: removeHead #\n";
	}

	try {
		btassert<bool>(list.toString() == "");
		cout << "Passed TEST 7: toString \n";
	} catch (bool b) {
		cout << "# FAILED TEST 7: toString #\n";
	}

	list.insertHead(10);
	list.insertHead(20);
	try {
		btassert<bool>(list.toString() == "20,10" && list.getSize() == 2);
		cout << "Passed TEST 8: insertHead,insertHead,toString,getSize \n";
	} catch (bool b) {
		cout << "# FAILED TEST 8: insertHead,insertHead,toString,getSize #\n";
	}

	list.removeHead();
	try {
		btassert<bool>(list.toString() == "10" && list.getSize() == 1);
		cout << "Passed TEST 9: removeHead,toString,getSize \n";
	} catch (bool b) {
		cout << "# FAILED TEST 9: removeHead,toString,getSize #\n";
	}

	list.insertHead(5);
	try {
		btassert<bool>(list.toString() == "5,10" && list.getSize() == 2);
		cout << "Passed TEST 10: insertHead,toString,getSize \n";
	} catch (bool b) {
		cout << "# FAILED TEST 10: insertHead,toString,getSize #\n";
	}

	list.clear();
	try {
		btassert<bool>(list.toString() == "" && list.getSize() == 0);
		cout << "Passed TEST 11: clear,toString,getSize \n";
	} catch (bool b) {
		cout << "# FAILED TEST 11: clear,toString,getSize #\n";
	}

	for (unsigned int i=0; i<1000; i++)
		list.insertHead(i);
	try {
		btassert<bool>(list.getSize() == 1000);
		cout << "Passed TEST 12: insertHead high load \n";
	} catch (bool b) {
		cout << "# FAILED TEST 12: insertHead high load #\n";
	}

	for (unsigned int i=0; i<1000; i++)
		list.removeHead();
	try {
		btassert<bool>(list.getSize() == 0);
		cout << "Passed TEST 13: removeHead high load \n";
	} catch (bool b) {
		cout << "# FAILED TEST 13: removeHead high load #\n";
	}
    
	cout << "\nUNIT TEST COMPLETE\n\n";
}

template <typename X, typename A>
void btassert (A assertion)
{
    if (!assertion)
		throw X();
}