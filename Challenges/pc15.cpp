/*
 * Programming Challenge 15
 */
#include <cassert>
#include <iostream>
#include <string>
using namespace std;

class ShoppingList
{
    public:
	
        /*
         * Default constructor.
         * Initializes maxItems to 10 and itemCount to 0.
         */
        ShoppingList ();

        /*
         * Get the maximum number of items in this ShoppingList.
         * @return an unsigned integer containing the maximum number of items
         *         in this ShoppingList
         */
        unsigned int getMaxItems () const;

        /*
         * Get the count of the number of items in this ShoppingList.
         * @return an unsigned integer containing the count of number of items
         *         in this ShoppingList
         */
        unsigned int getItemCount () const;
        
        /*
         * Place an item at a specified index in the array and increment the count of items in 
         * the array.
         * @param theItem a string containing the item to be added to the array
         * @return true if the item can be added, otherwise return false
         */
        bool addItem (string theItem);

        /*
         * Retrieve the value of the item at a specified index in the array.
         * @param index an unsigned integer containing the zero-based index
         *        of the item to be retrieved
         * @return if index is valid, a string containing the value of the item
         *         at the specified index
         * @throw ArrayException with the message "INVALID ARRAY INDEX" if index is invalid
         */
        string getItem (unsigned int index) const;

        /*
         * Retrieve a reference to the item at a specified index in the array.
         * @param index an unsigned integer containing the zero-based index
         *        of the item to be retrieved
         * @return if index is valid, a reference to the string at the specified index
         * @throw ArrayException with the message "INVALID ARRAY INDEX" if index is invalid
         */
        string& getItem (unsigned int index);

        /*
         * Remove the item at a specified index in the array. Decrement item count a "pack" 
         * the array so that all valid items are contiguous in the array.
         * @param index an unsigned integer containing the zero-based index
         *        of the item to be removed
         * @return the value of the string at the specified index
         * @throw ArrayException with the message "INVALID ARRAY SIZE" if newSize is less than 1
         */
        string removeItem (unsigned int index);

    private:

        string items[10];
        unsigned int maxItems;
        unsigned int itemCount;
};

/* for unit testing -- do not alter */
struct ArrayException
{
    ArrayException (string newMessage="error")
    : message(newMessage)
    {
    }

    string message;
};

template <typename X, typename A>
void btassert(A assertion);
void unittest ();

int main ()
{

    unittest();

    return 0;
}

ShoppingList::ShoppingList()
{
    maxItems = 10;
    itemCount = 0;
}

unsigned int ShoppingList::getMaxItems() const
{
        return maxItems;
}

unsigned int ShoppingList::getItemCount() const
{
    return itemCount;
}

bool ShoppingList::addItem (string theItem)
{
    if(itemCount == maxItems)
        return false;
    else
    {
        items[itemCount] = theItem;
        itemCount++;
        return true;
    }
}

string ShoppingList::getItem(unsigned int index) const
{
    if(index >= maxItems)
        throw ArrayException("INVALID ARRAY INDEX");
    
    return items[index];
}

string& ShoppingList::getItem(unsigned int index)
{
    if(index >= maxItems)
        throw ArrayException("INVALID ARRAY INDEX");
        
    return items[index];
}

string ShoppingList::removeItem (unsigned int index)
{
    if(index >= maxItems)
        throw ArrayException("INVALID ARRAY INDEX");
   
    string deleteItem = items[index];
    items[index] = "";
    for(unsigned int i = index; i < maxItems; ++i)
    {
        items[index] = items[index+1];
    }
    --itemCount;
   
   return deleteItem;
}

/*
 * Unit testing functions. Do not alter.
 */

void unittest ()
{
    cout << "\nSTARTING UNIT TEST\n\n";

    ShoppingList myList;

    try {
        btassert<bool>(myList.getMaxItems() == 10);
        cout << "Passed TEST 1: ShoppingList::getMaxItems () \n";
    } catch (bool b) {
        cout << "# FAILED TEST 1: ShoppingList::getMaxItems () #\n";
    }

    try {
        btassert<bool>(myList.getItemCount() == 0);
        cout << "Passed TEST 2: ShoppingList::getItemCount () \n";
    } catch (bool b) {
        cout << "# FAILED TEST 2: ShoppingList::getItemCount () #\n";
    }

    try {
        myList.getItem(0);
    } catch (ArrayException e) {
        try {
            btassert<bool>(e.message == "INVALID ARRAY INDEX");
            cout << "Passed TEST 3: ShoppingList::getItem(0) EXCEPTION HANDLING \n";
        } catch (bool b) {
            cout << "# FAILED TEST 3: ShoppingList::getItem(0) EXCEPTION HANDLING #\n";
        }
    }

    try {
        btassert<bool>(myList.addItem("apples") == true);
        cout << "Passed TEST 4: ShoppingList::addItem(\"apples\") \n";
    } catch (bool b) {
        cout << "# FAILED TEST 4: ShoppingList::addItem(\"apples\") #\n";
    }

    try {
        btassert<bool>(myList.getItemCount() == 1);
        cout << "Passed TEST 5: ShoppingList::getItemCount () \n";
    } catch (bool b) {
        cout << "# FAILED TEST 5: ShoppingList::getItemCount () #\n";
    }

    try {
        btassert<bool>(myList.getItem(0) == "apples");
        cout << "Passed TEST 6: ShoppingList::getItem(0) \n";
    } catch (bool b) {
        cout << "# FAILED TEST 6: ShoppingList::getItem(0) #\n";
    }

    myList.getItem(0) = "oranges";
    try {
        btassert<bool>(myList.getItem(0) == "oranges");
        cout << "Passed TEST 7: string& ShoppingList::getItem(0) \n";
    } catch (bool b) {
        cout << "# FAILED TEST 7: string& ShoppingList::getItem(0) #\n";
    }

    try {
        btassert<bool>(myList.removeItem(0) == "oranges");
        cout << "Passed TEST 8: ShoppingList::removeItem(0) \n";
    } catch (bool b) {
        cout << "# FAILED TEST 8: ShoppingList::removeItem(0) #\n";
    }
    
    try {
        btassert<bool>(myList.getItemCount() == 0);
        cout << "Passed TEST 9: ShoppingList::getItemCount () \n";
    } catch (bool b) {
        cout << "# FAILED TEST 9: ShoppingList::getItemCount () #\n";
    }

    for (unsigned int i=0; i<myList.getMaxItems(); i++)
        myList.addItem("grapes");

    try {
        btassert<bool>(myList.getItemCount() == 10);
        cout << "Passed TEST 10: ShoppingList::getItemCount () \n";
    } catch (bool b) {
        cout << "# FAILED TEST 10: ShoppingList::getItemCount () #\n";
    }

    try {
        myList.getItem(11);
    } catch (ArrayException e) {
        try {
            btassert<bool>(e.message == "INVALID ARRAY INDEX");
            cout << "Passed TEST 11: ShoppingList::getItem(11) EXCEPTION HANDLING \n";
        } catch (bool b) {
            cout << "# FAILED TEST 11: ShoppingList::setItem(11) EXCEPTION HANDLING #\n";
        }
    }

    try {
        btassert<bool>(myList.addItem("bananas") == false);
        cout << "Passed TEST 12: ShoppingList::addItem(\"bananas\") \n";
    } catch (bool b) {
        cout << "# FAILED TEST 12: ShoppingList::getItem(\"bananas\") #\n";
    }

    unsigned int itemsToRemove = myList.getItemCount();
    for (unsigned int i=0; i<itemsToRemove; i++)
        myList.removeItem(0);

    try {
        btassert<bool>(myList.getItemCount() == 0);
        cout << "Passed TEST 13: ShoppingList::getItemCount () \n";
    } catch (bool b) {
        cout << "# FAILED TEST 13: ShoppingList::getItemCount () #\n";
    }

    try {
        myList.getItem(0) = "oranges";
    } catch (ArrayException e) {
        try {
            btassert<bool>(e.message == "INVALID ARRAY INDEX");
            cout << "Passed TEST 14: string& ShoppingList::getItem(0) EXCEPTION HANDLING \n";
        } catch (bool b) {
            cout << "# FAILED TEST 14: string& ShoppingList::setItem(0) EXCEPTION HANDLING #\n";
        }
    }

    try {
        btassert<bool>(myList.getMaxItems() == 10);
        cout << "Passed TEST 15: ShoppingList::getMaxItems () \n";
    } catch (bool b) {
        cout << "# FAILED TEST 15: ShoppingList::getMaxItems () #\n";
    }

    cout << "\nUNIT TEST COMPLETE\n\n";
}

template <typename X, typename A>
void btassert (A assertion)
{
    if (!assertion)
        throw X();
}
