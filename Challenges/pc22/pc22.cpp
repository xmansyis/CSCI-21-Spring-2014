/*
 * Programming Challenge 22 - UNIT TEST
 */

#include "SList.h"

#include <cassert>
#include <cstdlib>
#include <iostream>
#include <sstream>
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
	
	SList<int> intList;
	
	cout << "INTEGER LIST TEST\n\n";
	
	try {
		btassert<bool>(intList.getSize() == 0);
		cout << "Passed TEST 1: default constructor (size) \n";
	} catch (bool b) {
		cout << "# FAILED TEST 1: default constructor (size) #\n";
	}
	
	try {
		btassert<bool>(intList.toString() == "");
		cout << "Passed TEST 2: toString \n";
	} catch (bool b) {
		cout << "# FAILED TEST 2: toString #\n";
	}
	
	intList.insert(10);
	try {
		btassert<bool>(intList.getSize() == 1 && intList.toString() == "10");
		cout << "Passed TEST 3: insert(10)/getSize/toString \n";
	} catch (bool b) {
		cout << "# FAILED TEST 3: insert(10)/getSize/toString #\n";
	}
	
	intList.insert(10);
	try {
		btassert<bool>(intList.getSize() == 2 && intList.toString() == "10,10");
		cout << "Passed TEST 4: insert(10)/getSize/toString \n";
	} catch (bool b) {
		cout << "# FAILED TEST 4: insert(10)/getSize/toString #\n";
	}
	
	intList.insert(30);
	try {
		btassert<bool>(intList.getSize() == 3 && intList.toString() == "10,10,30");
		cout << "Passed TEST 5: insert(30)/getSize/toString \n";
	} catch (bool b) {
		cout << "# FAILED TEST 5: insert(30)/getSize/toString #\n";
	}
	
	intList.insert(30);
	try {
		btassert<bool>(intList.getSize() == 4 && intList.toString() == "10,10,30,30");
		cout << "Passed TEST 6: insert(30)/getSize/toString \n";
	} catch (bool b) {
		cout << "# FAILED TEST 6: insert(30)/getSize/toString #\n";
	}
	
	intList.insert(15);
	try {
		btassert<bool>(intList.getSize() == 5 && intList.toString() == "10,10,15,30,30");
		cout << "Passed TEST 7: insert(15)/getSize/toString \n";
	} catch (bool b) {
		cout << "# FAILED TEST 7: insert(15)/getSize/toString #\n";
	}
	
	intList.insertHead(5);
	try {
		btassert<bool>(intList.getSize() == 6 && intList.toString() == "5,10,10,15,30,30");
		cout << "Passed TEST 8: insertHead(5)/getSize/toString \n";
	} catch (bool b) {
		cout << "# FAILED TEST 8: insertHead(5)/getSize/toString #\n";
	}
	
	intList.insertTail(50);
	try {
		btassert<bool>(intList.getSize() == 7 && intList.toString() == "5,10,10,15,30,30,50");
		cout << "Passed TEST 9: insertTail(50)/getSize/toString \n";
	} catch (bool b) {
		cout << "# FAILED TEST 9: insertTail(50)/getSize/toString #\n";
	}
	
	try {
		btassert<bool>(intList.removeFirst(1) == false);
		cout << "Passed TEST 10: removeFirst(1) \n";
	} catch (bool b) {
		cout << "# FAILED TEST 10: removeFirst(1) #\n";
	}
	
	try {
		btassert<bool>(intList.removeAll(100) == false);
		cout << "Passed TEST 11: removeAll(1) \n";
	} catch (bool b) {
		cout << "# FAILED TEST 11: removeAll(1) #\n";
	}
	
	try {
		btassert<bool>(intList.removeFirst(10) == true && intList.getSize() == 6 && intList.toString() == "5,10,15,30,30,50");
		cout << "Passed TEST 12: removeFirst(10)/getSize/toString \n";
	} catch (bool b) {
		cout << "# FAILED TEST 12: removeFirst(10)/getSize/toString #\n";
	}
	
	try {
		btassert<bool>(intList.removeAll(30) == true && intList.getSize() == 4 && intList.toString() == "5,10,15,50");
		cout << "Passed TEST 13: removeAll(30)/getSize/toString \n";
	} catch (bool b) {
		cout << "# FAILED TEST 13: removeAll(30)/getSize/toString #\n";
	}
	
	intList.removeHead();
	try {
		btassert<bool>(intList.getSize() == 3 && intList.toString() == "10,15,50");
		cout << "Passed TEST 14: removeHead/getSize/toString \n";
	} catch (bool b) {
		cout << "# FAILED TEST 14: removeHead/getSize/toString #\n";
	}
	
	intList.removeTail();
	try {
		btassert<bool>(intList.getSize() == 2 && intList.toString() == "10,15");
		cout << "Passed TEST 15: removeTail/getSize/toString \n";
	} catch (bool b) {
		cout << "# FAILED TEST 15: removeTail/getSize/toString #\n";
	}
	
	intList.clear();
	try {
		btassert<bool>(intList.getSize() == 0 && intList.toString() == "");
		cout << "Passed TEST 16: clear/getSize/toString \n";
	} catch (bool b) {
		cout << "# FAILED TEST 16: clear/getSize/toString #\n";
	}
	
	cout << "\nSTRING LIST TEST\n\n";
	
	SList<string> stringList;
	
	try {
		btassert<bool>(stringList.getSize() == 0);
		cout << "Passed TEST 17: default constructor (size) \n";
	} catch (bool b) {
		cout << "# FAILED TEST 17: default constructor (size) #\n";
	}
	
	try {
		btassert<bool>(stringList.toString() == "");
		cout << "Passed TEST 18: toString \n";
	} catch (bool b) {
		cout << "# FAILED TEST 18: toString #\n";
	}
	
	stringList.insert("hello");
	try {
		btassert<bool>(stringList.getSize() == 1 && stringList.toString() == "hello");
		cout << "Passed TEST 19: insert(\"hello\")/getSize/toString \n";
	} catch (bool b) {
		cout << "# FAILED TEST 19: insert(\"hello\")/getSize/toString #\n";
	}
	
	stringList.insert("hello");
	try {
		btassert<bool>(stringList.getSize() == 2 && stringList.toString() == "hello,hello");
		cout << "Passed TEST 20: insert(\"hello\")/getSize/toString \n";
	} catch (bool b) {
		cout << "# FAILED TEST 20: insert(\"hello\")/getSize/toString #\n";
	}
	
	stringList.insert("mellow");
	try {
		btassert<bool>(stringList.getSize() == 3 && stringList.toString() == "hello,hello,mellow");
		cout << "Passed TEST 21: insert(\"mellow\")/getSize/toString \n";
	} catch (bool b) {
		cout << "# FAILED TEST 21: insert(\"mellow\")/getSize/toString #\n";
	}
	
	stringList.insert("mellow");
	try {
		btassert<bool>(stringList.getSize() == 4 && stringList.toString() == "hello,hello,mellow,mellow");
		cout << "Passed TEST 22: insert(\"mellow\")/getSize/toString \n";
	} catch (bool b) {
		cout << "# FAILED TEST 22: insert(\"mellow\")/getSize/toString #\n";
	}
	
	stringList.insert("jello");
	try {
		btassert<bool>(stringList.getSize() == 5 && stringList.toString() == "hello,hello,jello,mellow,mellow");
		cout << "Passed TEST 23: insert(\"jello\")/getSize/toString \n";
	} catch (bool b) {
		cout << "# FAILED TEST 23: insert(\"jello\")/getSize/toString #\n";
	}
	
	stringList.insertHead("cello");
	try {
		btassert<bool>(stringList.getSize() == 6 && stringList.toString() == "cello,hello,hello,jello,mellow,mellow");
		cout << "Passed TEST 24: insertHead(\"cello\")/getSize/toString \n";
	} catch (bool b) {
		cout << "# FAILED TEST 24: insertHead(\"cello\")/getSize/toString #\n";
	}
	
	stringList.insertTail("yellow");
	try {
		btassert<bool>(stringList.getSize() == 7 && stringList.toString() == "cello,hello,hello,jello,mellow,mellow,yellow");
		cout << "Passed TEST 25: insertTail(\"yellow\")/getSize/toString \n";
	} catch (bool b) {
		cout << "# FAILED TEST 25: insertTail(\"yellow\")/getSize/toString #\n";
	}
	
	try {
		btassert<bool>(stringList.removeFirst("fellow") == false);
		cout << "Passed TEST 26: removeFirst(\"fellow\") \n";
	} catch (bool b) {
		cout << "# FAILED TEST 26: removeFirst(\"fellow\") #\n";
	}
	
	try {
		btassert<bool>(stringList.removeAll("bellow") == false);
		cout << "Passed TEST 27: removeAll(\"bellow\") \n";
	} catch (bool b) {
		cout << "# FAILED TEST 27: removeAll(\"bellow\") #\n";
	}
	
	try {
		btassert<bool>(stringList.removeFirst("hello") == true && stringList.getSize() == 6 && stringList.toString() == "cello,hello,jello,mellow,mellow,yellow");
		cout << "Passed TEST 28: removeFirst(\"hello\")/getSize/toString \n";
	} catch (bool b) {
		cout << "# FAILED TEST 28: removeFirst(\"hello\")/getSize/toString #\n";
	}
	
	try {
		btassert<bool>(stringList.removeAll("mellow") == true && stringList.getSize() == 4 && stringList.toString() == "cello,hello,jello,yellow");
		cout << "Passed TEST 29: removeAll(30)/getSize/toString \n";
	} catch (bool b) {
		cout << "# FAILED TEST 29: removeAll(30)/getSize/toString #\n";
	}
	
	stringList.removeHead();
	try {
		btassert<bool>(stringList.getSize() == 3 && stringList.toString() == "hello,jello,yellow");
		cout << "Passed TEST 30: removeHead/getSize/toString \n";
	} catch (bool b) {
		cout << "# FAILED TEST 30: removeHead/getSize/toString #\n";
	}
	
	stringList.removeTail();
	try {
		btassert<bool>(stringList.getSize() == 2 && stringList.toString() == "hello,jello");
		cout << "Passed TEST 31: removeTail/getSize/toString \n";
	} catch (bool b) {
		cout << "# FAILED TEST 31: removeTail/getSize/toString #\n";
	}
	
	stringList.clear();
	try {
		btassert<bool>(stringList.getSize() == 0 && stringList.toString() == "");
		cout << "Passed TEST 32: clear/getSize/toString \n";
	} catch (bool b) {
		cout << "# FAILED TEST 32: clear/getSize/toString #\n";
	}
	
	cout << "\nUNIT TEST COMPLETE\n\n";
}

template <typename X, typename A>
void btassert (A assertion)
{
    if (!assertion)
		throw X();
}