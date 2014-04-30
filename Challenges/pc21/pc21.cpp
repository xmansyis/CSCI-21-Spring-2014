/*
 * Programming Challenge 21 - UNIT TEST
 */

#include "box.h"

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

	stringstream ss;

	Box<int> intBox(99);

	try {
		btassert<bool>(intBox.getContents() == 99);
		cout << "Passed TEST 1: int Box: constructor/getContents \n";
	} catch (bool b) {
		cout << "# FAILED TEST 1: int Box: constructor/getContents #\n";
	}

	intBox.setContents(42);
	try {
		btassert<bool>(intBox.getContents() == 42);
		cout << "Passed TEST 2: int Box: setContents/getContents \n";
	} catch (bool b) {
		cout << "# FAILED TEST 2: int Box: setContents/getContents #\n";
	}

	ss << intBox;
	try {
		btassert<bool>(ss.str() == "42");
		cout << "Passed TEST 3: int Box: operator<< \n";
	} catch (bool b) {
		cout << "# FAILED TEST 3: int Box: operator<< #\n";
	}

	Box<bool> boolBox(false);

	try {
		btassert<bool>(boolBox.getContents() == false);
		cout << "Passed TEST 4: bool Box: constructor/getContents \n";
	} catch (bool b) {
		cout << "# FAILED TEST 4: bool Box: constructor/getContents #\n";
	}

	boolBox.setContents(true);
	try {
		btassert<bool>(boolBox.getContents() == true);
		cout << "Passed TEST 5: bool Box: setContents/getContents \n";
	} catch (bool b) {
		cout << "# FAILED TEST 5: bool Box: setContents/getContents #\n";
	}

	ss.str("");
	ss << boolBox;
	try {
		btassert<bool>(ss.str() == "1");
		cout << "Passed TEST 6: bool Box: operator<< \n";
	} catch (bool b) {
		cout << "# FAILED TEST 6: bool Box: operator<< #\n";
	}

	Box<float> floatBox(1.23f);

	try {
		btassert<bool>(floatBox.getContents() == 1.23f);
		cout << "Passed TEST 7: float Box: constructor/getContents \n";
	} catch (bool b) {
		cout << "# FAILED TEST 7: float Box: constructor/getContents #\n";
	}

	floatBox.setContents(3.21f);
	try {
		btassert<bool>(floatBox.getContents() == 3.21f);
		cout << "Passed TEST 8: float Box: setContents/getContents \n";
	} catch (bool b) {
		cout << "# FAILED TEST 8: float Box: setContents/getContents #\n";
	}

	ss.str("");
	ss << floatBox;
	try {
		btassert<bool>(ss.str() == "3.21");
		cout << "Passed TEST 9: float Box: operator<< \n";
	} catch (bool b) {
		cout << "# FAILED TEST 9: float Box: operator<< #\n";
	}

	Box<string> stringBox("hello");

	try {
		btassert<bool>(stringBox.getContents() == "hello");
		cout << "Passed TEST 10: string Box: constructor/getContents \n";
	} catch (bool b) {
		cout << "# FAILED TEST 10: string Box: constructor/getContents #\n";
	}

	stringBox.setContents("goodbye");
	try {
		btassert<bool>(stringBox.getContents() == "goodbye");
		cout << "Passed TEST 11: string Box: setContents/getContents \n";
	} catch (bool b) {
		cout << "# FAILED TEST 11: string Box: setContents/getContents #\n";
	}

	ss.str("");
	ss << stringBox;
	try {
		btassert<bool>(ss.str() == "goodbye");
		cout << "Passed TEST 12: string Box: operator<< \n";
	} catch (bool b) {
		cout << "# FAILED TEST 12: string Box: operator<< #\n";
	}

	cout << "\nUNIT TEST COMPLETE\n\n";
}

template <typename X, typename A>
void btassert (A assertion)
{
    if (!assertion)
		throw X();
}