/*
 * Programming Challenge 28
 */

#include "Item.h"
#include "FoodItem.h"
#include "MagicItem.h"

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
	
	Item item;
	Item mItem("game", 25);
	FoodItem foodItem;
	FoodItem mFoodItem("coffee", 1, 10, "ounces", 10.25);
	MagicItem magicItem;
	MagicItem mMagicItem("staff", 999, "carved wood", 125);
	
	try {
		btassert<bool>(item.getName() == "item" && item.getValue() == 0 && item.toString() == "item, $0");
		cout << "Passed TEST 1: Item(), getName/getValue/toString \n";
	} catch (bool b) {
		cout << "# FAILED TEST 1: Item(), getName/getValue/toString #\n";
	}
	
	item.setName("car");
	item.setValue(35000);
	try {
		btassert<bool>(item.getName() == "car" && item.getValue() == 35000 && item.toString() == "car, $35000");
		cout << "Passed TEST 2: Item(), setName/setValue \n";
	} catch (bool b) {
		cout << "# FAILED TEST 2: Item(), setName/setValue #\n";
	}
	
	try {
		btassert<bool>(mItem.toString() == "game, $25");
		cout << "Passed TEST 3: Item(\"game\", 25), toString \n";
	} catch (bool b) {
		cout << "# FAILED TEST 3: Item(\"game\", 25), toString #\n";
	}
	
	try {
		btassert<bool>(foodItem.getName() == "fooditem" && foodItem.getValue() == 0 &&
							foodItem.toString() == "fooditem, $0, 0.00 nounits, 0 calories");
		cout << "Passed TEST 4: FoodItem(), getName/getValue/toString \n";
	} catch (bool b) {
		cout << "# FAILED TEST 4: FoodItem(), getName/getValue/toString #\n";
	}
	
	try {
		btassert<bool>(foodItem.getUnitOfMeasure() == "nounits" && foodItem.getCalories() == 0 &&
							(foodItem.getUnits() == 0));
		cout << "Passed TEST 5: FoodItem(), getUnitOfMeasure/getUnits/getCalories \n";
	} catch (bool b) {
		cout << "# FAILED TEST 5: FoodItem(), getUnitOfMeasure/getUnits/getCalories #\n";
	}
	
	foodItem.setName("cupcake");
	foodItem.setValue(5);
	foodItem.setUnitOfMeasure("cake(s)");
	foodItem.setUnits(1.5);
	foodItem.setCalories(200);
	try {
		btassert<bool>(foodItem.getName() == "cupcake" && foodItem.getValue() == 5 &&
							foodItem.getUnitOfMeasure() == "cake(s)" && foodItem.getCalories() == 200 &&
							foodItem.toString() == "cupcake, $5, 1.50 cake(s), 200 calories");
		cout << "Passed TEST 6: FoodItem(), set all \n";
	} catch (bool b) {
		cout << "# FAILED TEST 6: FoodItem(), set all #\n";
	}
	
	try {
		btassert<bool>(mFoodItem.toString() == "coffee, $1, 10.25 ounces, 10 calories");
		cout << "Passed TEST 7: FoodItem(\"coffee\", 1, 10, \"ounces\", 10.25), toString \n";
	} catch (bool b) {
		cout << "# FAILED TEST 7: FoodItem(\"coffee\", 1, 10, \"ounces\", 10.25), toString #\n";
	}
	
	try {
		btassert<bool>(magicItem.getDescription() == "no description" && magicItem.getManaRequired() == 0);
		cout << "Passed TEST 8: MagicItem(), getDescription/getManaRequired \n";
	} catch (bool b) {
		cout << "# FAILED TEST 8: MagicItem(), getDescription/getManaRequired #\n";
	}
	
	magicItem.setName("wand");
	magicItem.setValue(1000);
	magicItem.setDescription("jewel-encrusted");
	magicItem.setManaRequired(50);
	try {
		btassert<bool>(magicItem.getName() == "wand" && magicItem.getValue() == 1000 &&
							magicItem.getDescription() == "jewel-encrusted" && magicItem.getManaRequired() == 50 &&
							magicItem.toString() == "wand, $1000, jewel-encrusted, requires 50 mana");
		cout << "Passed TEST 9: MagicItem(), set all \n";
	} catch (bool b) {
		cout << "# FAILED TEST 9: MagicItem(), set all #\n";
	}
	
	try {
		btassert<bool>(mMagicItem.toString() == "staff, $999, carved wood, requires 125 mana");
		cout << "Passed TEST 10: MagicItem(\"staff\", 999, \"carved wood\", 125), toString \n";
	} catch (bool b) {
		cout << "# FAILED TEST 10: MagicItem(\"staff\", 999, \"carved wood\", 125), toString #\n";
	}

	cout << "\nUNIT TEST COMPLETE\n\n";
}

template <typename X, typename A>
void btassert (A assertion)
{
    if (!assertion)
		throw X();
}