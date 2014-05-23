/*
 * Programming Challenge 29
 */

#include "TreasureChest.h"

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <vector>
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
	
	const Item* ptrItem = NULL;
	
	Item testItems[5] = {
		Item("ruby", 100, 1), 
		Item("gold", 5, 100), 
		Item("emerald", 50, 2), 
		Item("silver", 2, 200), 
		Item()
	};
	TreasureChest chest;
	
	try {
		btassert<bool>(chest.getSize() == 0 && chest.empty());
		cout << "Passed TEST 1: empty chest/getSize/empty \n";
	} catch (bool b) {
		cout << "# FAILED TEST 1: empty chest/getSize/empty #\n";
	}
	
	try {
		btassert<bool>(chest.getItem(0) == NULL);
		cout << "Passed TEST 2: getItem \n";
	} catch (bool b) {
		cout << "# FAILED TEST 2: getItem #\n";
	}
	
	try {
		chest.removeItem(0);
		cout << "# FAILED TEST 3: remove from empty chest #\n";
	} catch (string s) {
		if (s == "ERROR: attempting remove at invalid position")
			cout << "Passed TEST 3: remove from empty chest\n";
		else
			cout << "# FAILED TEST 3: remove from empty chest #\n";
	}
	
	chest.addItem(testItems[0]);
	ss << chest;
	try {
		btassert<bool>(!chest.empty() && chest.getSize() == 1 && ss.str() == "ruby");
		cout << "Passed TEST 4: addItem/empty/getSize/operator<< \n";
	} catch (bool b) {
		cout << "# FAILED TEST 4: addItem/empty/getSize/operator<< #\n";
	}
	
	ss.str("");
	chest.addItem(testItems[1]);
	ss << chest;
	try {
		btassert<bool>(!chest.empty() && chest.getSize() == 2 && ss.str() == "ruby,gold");
		cout << "Passed TEST 5: addItem/empty/getSize/operator<< \n";
	} catch (bool b) {
		cout << "# FAILED TEST 5: addItem/empty/getSize/operator<< #\n";
	}
	
	ss.str("");
	chest.insertItem(testItems[2], 1);
	ss << chest;
	try {
		btassert<bool>(!chest.empty() && chest.getSize() == 3 && ss.str() == "ruby,emerald,gold");
		cout << "Passed TEST 6: insertItem/empty/getSize/operator<< \n";
	} catch (bool b) {
		cout << "# FAILED TEST 6: insertItem/empty/getSize/operator<< #\n";
	}
	
	ss.str("");
	chest.insertItem(testItems[3], 2);
	ss << chest;
	try {
		btassert<bool>(!chest.empty() && chest.getSize() == 4 && ss.str() == "ruby,emerald,silver,gold");
		cout << "Passed TEST 7: insertItem/empty/getSize/operator<< \n";
	} catch (bool b) {
		cout << "# FAILED TEST 7: insertItem/empty/getSize/operator<< #\n";
	}
	
	ss.str("");
	chest.insertItem(testItems[4], 0);
	ss << chest;
	try {
		btassert<bool>(!chest.empty() && chest.getSize() == 5 && ss.str() == "noname,ruby,emerald,silver,gold");
		cout << "Passed TEST 8: insertItem/empty/getSize/operator<< \n";
	} catch (bool b) {
		cout << "# FAILED TEST 8: insertItem/empty/getSize/operator<< #\n";
	}
	
	ss.str("");
	chest.removeItem(0);
	ss << chest;
	try {
		btassert<bool>(!chest.empty() && chest.getSize() == 4 && ss.str() == "ruby,emerald,silver,gold");
		cout << "Passed TEST 9: removeItem/empty/getSize/operator<< \n";
	} catch (bool b) {
		cout << "# FAILED TEST 9: removeItem/empty/getSize/operator<< #\n";
	}
	
	ss.str("");
	chest.removeItem(3);
	ss << chest;
	try {
		btassert<bool>(!chest.empty() && chest.getSize() == 3 && ss.str() == "ruby,emerald,silver");
		cout << "Passed TEST 10: removeItem/empty/getSize/operator<< \n";
	} catch (bool b) {
		cout << "# FAILED TEST 10: removeItem/empty/getSize/operator<< #\n";
	}
	
	try {
		chest.removeItem(3);
		cout << "# FAILED TEST 11: remove from invalid position #\n";
	} catch (string s) {
		if (s == "ERROR: attempting remove at invalid position")
			cout << "Passed TEST 11: remove from invalid position\n";
		else
			cout << "# FAILED TEST 11: remove from invalid position #\n";
	}
	
	ss.str("");
	chest.clear();
	ss << chest;
	try {
		btassert<bool>(chest.empty() && chest.getSize() == 0 && ss.str() == "");
		cout << "Passed TEST 12: clear/empty/getSize/operator<< \n";
	} catch (bool b) {
		cout << "# FAILED TEST 12: clear/empty/getSize/operator<< #\n";
	}
	
	for (unsigned int i=0; i<5; i++)
		chest.addItem(testItems[i]);
		
	ss.str("");
	ss << chest;
	try {
		btassert<bool>(!chest.empty() && chest.getSize() == 5 && ss.str() == "ruby,gold,emerald,silver,noname");
		cout << "Passed TEST 13: addItem/empty/getSize/operator<< \n";
	} catch (bool b) {
		cout << "# FAILED TEST 13: addItem/empty/getSize/operator<< #\n";
	}	
	
	chest.sortByName();
	ss.str("");
	ss << chest;
	try {
		btassert<bool>(ss.str() == "emerald,gold,noname,ruby,silver");
		cout << "Passed TEST 14: sortByName/operator<< \n";
	} catch (bool b) {
		cout << "# FAILED TEST 14: sortByName/operator<< #\n";
	}
	
	ptrItem = chest.getItem(0);
	try {
		btassert<bool>(ptrItem->name == "emerald" && ptrItem->value == 50 && ptrItem->quantity == 2);
		cout << "Passed TEST 15: getItem \n";
	} catch (bool b) {
		cout << "# FAILED TEST 15: getItem #\n";
	}
	
	chest.sortByValue();
	ss.str("");
	ss << chest;
	try {
		btassert<bool>(ss.str() == "noname,silver,gold,emerald,ruby");
		cout << "Passed TEST 16: sortByValue/operator<< \n";
	} catch (bool b) {
		cout << "# FAILED TEST 16: sortByValue/operator<< #\n";
	}
	
	ptrItem = chest.getItem(0);
	try {
		btassert<bool>(ptrItem->name == "noname" && ptrItem->value == 0 && ptrItem->quantity == 0);
		cout << "Passed TEST 17: getItem \n";
	} catch (bool b) {
		cout << "# FAILED TEST 17: getItem #\n";
	}
	
	chest.sortByQuantity();
	ss.str("");
	ss << chest;
	try {
		btassert<bool>(ss.str() == "noname,ruby,emerald,gold,silver");
		cout << "Passed TEST 18: sortByQuantity/operator<< \n";
	} catch (bool b) {
		cout << "# FAILED TEST 18: sortByQuantity/operator<< #\n";
	}
	
	ptrItem = chest.getItem(4);
	try {
		btassert<bool>(ptrItem->name == "silver" && ptrItem->value == 2 && ptrItem->quantity == 200);
		cout << "Passed TEST 19: getItem \n";
	} catch (bool b) {
		cout << "# FAILED TEST 19: getItem #\n";
	}
	
	ptrItem = chest.getItem(5);
	try {
		btassert<bool>(ptrItem == NULL);
		cout << "Passed TEST 20: getItem at invalid position \n";
	} catch (bool b) {
		cout << "# FAILED TEST 20: getItem at invalid position #\n";
	}
	
	cout << "\nUNIT TEST COMPLETE\n\n";
}

template <typename X, typename A>
void btassert (A assertion)
{
    if (!assertion)
		throw X();
}
