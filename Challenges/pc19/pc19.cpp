/*
 * Programming Challenge 19 - UNIT TEST
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
	
	list.removeTail();
	try {
		btassert<bool>(list.getSize() == 0);
		cout << "Passed TEST 4: removeTail \n";
	} catch (bool b) {
		cout << "# FAILED TEST 4: removeTail #\n";
	}
	
	list.insertHead(1);
	try {
		btassert<bool>(list.getSize() == 1);
		cout << "Passed TEST 5: insertHead \n";
	} catch (bool b) {
		cout << "# FAILED TEST 5: insertHead #\n";
	}
	
	try {
		btassert<bool>(list.toString() == "1");
		cout << "Passed TEST 6: toString \n";
	} catch (bool b) {
		cout << "# FAILED TEST 6: toString #\n";
	}
	
	list.removeHead();
	try {
		btassert<bool>(list.getSize() == 0);
		cout << "Passed TEST 7: removeHead \n";
	} catch (bool b) {
		cout << "# FAILED TEST 7: removeHead #\n";
	}
	
	list.insertTail(1);
	try {
		btassert<bool>(list.getSize() == 1);
		cout << "Passed TEST 8: insertTail \n";
	} catch (bool b) {
		cout << "# FAILED TEST 8: insertTail #\n";
	}
	
	try {
		btassert<bool>(list.toString() == "1");
		cout << "Passed TEST 9: toString \n";
	} catch (bool b) {
		cout << "# FAILED TEST 9: toString #\n";
	}
	
	list.removeTail();
	try {
		btassert<bool>(list.getSize() == 0);
		cout << "Passed TEST 10: removeTail \n";
	} catch (bool b) {
		cout << "# FAILED TEST 10: removeTail #\n";
	}
	
	list.insertHead(10);
	list.insertTail(20);
	try {
		btassert<bool>(list.toString() == "10,20" && list.getSize() == 2);
		cout << "Passed TEST 11: insertHead,insertTail,toString,getSize \n";
	} catch (bool b) {
		cout << "# FAILED TEST 11: insertHead,insertTail,toString,getSize #\n";
	}
	
	list.removeHead();
	try {
		btassert<bool>(list.toString() == "20" && list.getSize() == 1);
		cout << "Passed TEST 12: removeHead,toString,getSize \n";
	} catch (bool b) {
		cout << "# FAILED TEST 12: removeHead,toString,getSize #\n";
	}
	
	list.insertHead(10);
	list.removeTail();
	try {
		btassert<bool>(list.toString() == "10" && list.getSize() == 1);
		cout << "Passed TEST 13: insertHead,removeTail,toString,getSize \n";
	} catch (bool b) {
		cout << "# FAILED TEST 13: insertHead,removeTail,toString,getSize #\n";
	}
	
	list.clear();
	try {
		btassert<bool>(list.toString() == "" && list.getSize() == 0);
		cout << "Passed TEST 13: clear,toString,getSize \n";
	} catch (bool b) {
		cout << "# FAILED TEST 13: clear,toString,getSize #\n";
	}
	
	list.insertHead(10);
	list.insertHead(5);
	list.insertTail(20);
	list.insertTail(25);
	try {
		btassert<bool>(list.toString() == "5,10,20,25" && list.getSize() == 4);
		cout << "Passed TEST 14: insertHeadx2,insertTailx2,toString,getSize \n";
	} catch (bool b) {
		cout << "# FAILED TEST 14: insertHeadx2,insertTailx2,toString,getSize #\n";
	}
	
	list.removeHead();
	list.removeTail();
	list.removeHead();
	list.removeTail();
	list.clear();
	try {
		btassert<bool>(list.toString() == "" && list.getSize() == 0);
		cout << "Passed TEST 15: removeHeadx2,removeTailx2,toString,getSize \n";
	} catch (bool b) {
		cout << "# FAILED TEST 15: removeHeadx2,removeTailx2,toString,getSize #\n";
	}
	
	for (unsigned int i=0; i<1000; i++)
		list.insertHead(i);
	try {
		btassert<bool>(list.getSize() == 1000);
		cout << "Passed TEST 16: insertHead high load \n";
	} catch (bool b) {
		cout << "# FAILED TEST 16: insertHead high load #\n";
	}
	
	for (unsigned int i=0; i<1000; i++)
		list.removeHead();
	try {
		btassert<bool>(list.getSize() == 0);
		cout << "Passed TEST 17: removeHead high load \n";
	} catch (bool b) {
		cout << "# FAILED TEST 17: removeHead high load #\n";
	}
	
	for (unsigned int i=0; i<1000; i++)
		list.insertTail(i);
	try {
		btassert<bool>(list.getSize() == 1000);
		cout << "Passed TEST 18: insertTail high load \n";
	} catch (bool b) {
		cout << "# FAILED TEST 18: insertTail high load #\n";
	}
	
	for (unsigned int i=0; i<1000; i++)
		list.removeTail();
	try {
		btassert<bool>(list.getSize() == 0);
		cout << "Passed TEST 19: removeTail high load \n";
	} catch (bool b) {
		cout << "# FAILED TEST 19: removeTail high load #\n";
	}
	
	for (unsigned int i=0; i<1000; i++)
	{
		if (i%2)
			list.insertHead(i);
		else
			list.insertTail(i);
	}
	try {
		btassert<bool>(list.getSize() == 1000);
		cout << "Passed TEST 20: insertHead/insertTail high load \n";
	} catch (bool b) {
		cout << "# FAILED TEST 20: insertHead/insertTail high load #\n";
	}
	
	cout << "\nUNIT TEST COMPLETE\n\n";
}

template <typename X, typename A>
void btassert (A assertion)
{
    if (!assertion)
		throw X();
}