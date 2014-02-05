/*
 * Programming Project 1
 * This is a program that will count characters in a string input, changes alphabit letters to 
 * either uppercase or lowercase in a string, and count how many words that are in the string.
 * This program also find the minimum number, maximum number, and calculate the average number in an array.
 *
 * Chee Yee Xiong
 * Date created: 01-29-14
 * Date modified: 02-05-14
 *
 * source: cplusplus.com
 */
#include <cassert>
#include <climits>
#include <iostream>
#include <string>
using namespace std;

void countCharacters (string theString, int& alpha, int& num);
string upAndDown (string theString);
int countWords (string theString);
int computeAverage (int values [], int arraySize);
int findMinValue (int values [], int arraySize);
int findMaxValue (int values [], int arraySize);

/* for unit testing -- do not alter */
template <typename X, typename A>
void btassert(A assertion);
void unittest ();

int main (int argc, char* argv[])
{
	unittest();
	
	return 0;
}

/*
* This is the function countCharacters.  This function count how many
* integer and letter are in the parameter theString.
* @param theString is a string input that will be use to look for integer or letter.
* @param alpha is a reference parameter that will update the total alphabit counted.
* @param num is a reference parameter that will update the total integer counted.
*/
void countCharacters (string theString, int& alpha, int& num)
{
    num = 0;
    alpha = 0;
    
    //this loop search through theString for integers and alphabit letters
    //and store the total of each kind in num or alpha.
    for (int i = 0; i < theString.size(); i++)
    {
        if(isdigit(theString[i]))
            num++;
            
        if(isalpha(theString[i]))
            alpha++;    
    }
}

/*
* This is the function upAndDown.  This function will find the first letter of a string and
* change it to uppercase.  The second letter of the string will be lowercase.  The third character
* will be uppercase again and so on, etc., and will return the new modify string.
* @param theString is a copy of a string that will be use to modify its character to either uppercase or
* lowercase letters.
* @return a string which hold the new modify string.
*/
string upAndDown (string theString)
{
    //a loop to go through theString characters.
    for(int i = 0; i < theString.size(); i++)
    {
        //if it's not a space, then it's a character and modify the character.
        if(!isspace(theString[i]))
        {
            //modify the character to either upper or lowercase.
            if(( i % 2) == 0)
                theString[i] = toupper(theString[i]);
            else
                theString[i] = tolower(theString[i]);
        }
    }
    return theString;
}

/*
* This is the function countWords.  This function will count how many words
* are in theString and return the number of words.
* @param theString is the string that will be use to count the words in.
* @return an int which is the number of words that was found in theString.
*/
int countWords (string theString)
{
    int numberOfWords = 0;
    
    //if theString is not empty.
    if(!theString.empty())
    { 
        numberOfWords++;
        
        //check for spaces to determine additional words.
        for(int i = 0; i <theString.size(); i++)
            if(isspace(theString[i]))
                numberOfWords++;
    }
    return numberOfWords;
}

/*
* This is the function computeAverage.  This function will compute the average
* number using the numbers in the array values and return the average value.
* @param values is the array parameter that holds the number values.
* @param arraySize is an int that describe how many number are in the array values.
* @return will return the average value.
*/
int computeAverage (int values [], int arraySize)
{
    int averageValue = 0;
    
    //loop to add all the values in the array (values)
    for (int i = 0; i < arraySize; i++)
        averageValue =+ values[i]+averageValue;
    
    //calculating the average.
    averageValue = averageValue/arraySize;
        
    return averageValue;
}

/*
* This is the function findMinValue.  This function will go through all the numbers
* in the array and find the lowest number and return the lowest number.
* @param values is the array parameter that will have all the number values.
* @param arraySize is an int that describe how many number are in the array.
* @return will return the lowest number found.
*/
int findMinValue (int values [], int arraySize)
{
    int minimumValue = values[0];
    
    //loop to find the smallest number in the array(values).
    for(int i =0; i < arraySize; i++)
        if(values[i] <= minimumValue)
            minimumValue = values[i];
            
    return minimumValue;
}

/*
* This is the function findMaxValue.  This function will go through all the numbers
* in an array and find the largest number.
* @param values is the array parameter that will have all the number values.
* @param arraySize is an int that describe how many number are in the array values.
* @return will return the largest number found.
*/
int findMaxValue (int values [], int arraySize)
{
    int maxValue = values[0];
    
    //loop to find the largest number in the array(values).
    for(int i =0; i < arraySize; i++)
        if(values[i] >= maxValue)
            maxValue = values[i];
            
    return maxValue;
}
/*
 * Unit testing functions. Do not alter.
 */
void unittest ()
{
	cout << "\nSTARTING UNIT TEST\n\n";

	int n1=0, n2=0;

	try {
		countCharacters("", n1, n2);
		btassert<bool>((n1 == 0) && (n2 == 0));
		cout << "Passed TEST 1: countCharacters(empty string)\n";
	} catch (bool b) {
		cout << "# FAILED TEST 1 #\n";
	}

	try {
		countCharacters("hello", n1, n2);
		btassert<bool>((n1 == 5) && (n2 == 0));
		cout << "Passed TEST 2: countCharacters(\"hello\")\n";
	} catch (bool b) {
		cout << "# FAILED TEST 2 #\n";
	}

	try {
		countCharacters("12345", n1, n2);
		btassert<bool>((n1 == 0) && (n2 == 5));
		cout << "Passed TEST 3: countCharacters(\"12345\")\n";
	} catch (bool b) {
		cout << "# FAILED TEST 3 #\n";
	}

	try {
		countCharacters("hello 12345", n1, n2);
		btassert<bool>((n1 == 5) && (n2 == 5));
		cout << "Passed TEST 4: countCharacters(\"hello 12345\")\n";
	} catch (bool b) {
		cout << "# FAILED TEST 4 #\n";
	}

	try {
		countCharacters("&,.", n1, n2);
		btassert<bool>((n1 == 0) && (n2 == 0));
		cout << "Passed TEST 5: countCharacters(\"&,.\")\n";
	} catch (bool b) {
		cout << "# FAILED TEST 5 #\n";
	}

	string s;

	try {
		s = upAndDown("hello");
		btassert<bool>(s == "HeLlO");
		cout << "Passed TEST 6: upAndDown(\"hello\")\n";
	} catch (bool b) {
		cout << "# FAILED TEST 6 #\n";
	}

	try {
		s = upAndDown("HeLlO");
		btassert<bool>(s == "HeLlO");
		cout << "Passed TEST 7: upAndDown(\"HeLlO\")\n";
	} catch (bool b) {
		cout << "# FAILED TEST 7 #\n";
	}

	try {
		s = upAndDown("hElLo");
		btassert<bool>(s == "HeLlO");
		cout << "Passed TEST 8: upAndDown(\"hElLo\")\n";
	} catch (bool b) {
		cout << "# FAILED TEST 8 #\n";
	}

	try {
		s = upAndDown("");
		btassert<bool>(s == "");
		cout << "Passed TEST 9: upAndDown(empty string)\n";
	} catch (bool b) {
		cout << "# FAILED TEST 9 #\n";
	}

	try {
		s = upAndDown("a");
		btassert<bool>(s == "A");
		cout << "Passed TEST 10: upAndDown(\"a\")\n";
	} catch (bool b) {
		cout << "# FAILED TEST 10 #\n";
	}

	try {
		btassert<bool>(countWords("") == 0);
		cout << "Passed TEST 11: countWords(empty string)\n";
	} catch (bool b) {
		cout << "# FAILED TEST 11 #\n";
	}

	try {
		btassert<bool>(countWords("hello") == 1);
		cout << "Passed TEST 12: countWords(\"hello\")\n";
	} catch (bool b) {
		cout << "# FAILED TEST 12 #\n";
	}

	try {
		btassert<bool>(countWords("hello,world") == 1);
		cout << "Passed TEST 13: countWords(\"hello world\")\n";
	} catch (bool b) {
		cout << "# FAILED TEST 13 #\n";
	}

	try {
		btassert<bool>(countWords("hello world") == 2);
		cout << "Passed TEST 14: countWords(\"hello world\")\n";
	} catch (bool b) {
		cout << "# FAILED TEST 14 #\n";
	}

	try {
		btassert<bool>(countWords("hello, world") == 2);
		cout << "Passed TEST 15: countWords(\"hello, world\")\n";
	} catch (bool b) {
		cout << "# FAILED TEST 15 #\n";
	}

	int values [] = {10, 20, 30};
	try {
		btassert<bool>(computeAverage(values, 3) == 20);
		cout << "Passed TEST 16: computeAverage([10,20,30])\n";
	} catch (bool b) {
		cout << "# FAILED TEST 16 #\n";
	}

	values[0] = 0, values[1] = 0, values[2] = 0;
	try {
		btassert<bool>(computeAverage(values, 3) == 0);
		cout << "Passed TEST 17: computeAverage([0,0,0])\n";
	} catch (bool b) {
		cout << "# FAILED TEST 17 #\n";
	}

	values[0] = 5, values[1] = 7, values[2] = 11;
	try {
		btassert<bool>(computeAverage(values, 3) == 7);
		cout << "Passed TEST 18: computeAverages([5,7,11])\n";
	} catch (bool b) {
		cout << "# FAILED TEST 18 #\n";
	}

	values[0] = -10, values[1] = -20, values[2] = -30;
	try {
		btassert<bool>(computeAverage(values, 3) == -20);
		cout << "Passed TEST 19: computeAverages([-10,-20,-30])\n";
	} catch (bool b) {
		cout << "# FAILED TEST 19 #\n";
	}

	values[0] = -5, values[1] = 0, values[2] = 5;
	try {
		btassert<bool>(computeAverage(values, 3) == 0);
		cout << "Passed TEST 20: computeAverages([-5,0,5])\n";
	} catch (bool b) {
		cout << "# FAILED TEST 20 #\n";
	}

	values[0] = -1, values[1] = 0, values[2] = 1;
	try {
		btassert<bool>(findMinValue(values, 3) == -1);
		cout << "Passed TEST 21: findMinValue([-1,0,1])\n";
	} catch (bool b) {
		cout << "# FAILED TEST 21 #\n";
	}

	values[0] = -3, values[1] = -2, values[2] = -1;
	try {
		btassert<bool>(findMinValue(values, 3) == -3);
		cout << "Passed TEST 22: findMinValue([-3,-2,-1])\n";
	} catch (bool b) {
		cout << "# FAILED TEST 22 #\n";
	}

	values[0] = 0, values[1] = 1, values[2] = 2;
	try {
		btassert<bool>(findMinValue(values, 3) == 0);
		cout << "Passed TEST 23: findMinValue([0,1,2])\n";
	} catch (bool b) {
		cout << "# FAILED TEST 23 #\n";
	}

	values[0] = 1, values[1] = 1, values[2] = 1;
	try {
		btassert<bool>(findMinValue(values, 3) == 1);
		cout << "Passed TEST 24: findMinValue([1,1,1])\n";
	} catch (bool b) {
		cout << "# FAILED TEST 24 #\n";

	}
	
	values[0] = INT_MAX, values[1] = INT_MAX, values[2] = INT_MAX;
	try {
		btassert<bool>(findMinValue(values, 3) == INT_MAX);
		cout << "Passed TEST 25: findMinValue([INT_MAX,INT_MAX,INT_MAX])\n";
	} catch (bool b) {
		cout << "# FAILED TEST 25 #\n";
	}

	values[0] = -1, values[1] = 0, values[2] = 1;
	try {
		btassert<bool>(findMaxValue(values, 3) == 1);
		cout << "Passed TEST 26: findMaxValue([-1,0,1])\n";
	} catch (bool b) {
		cout << "# FAILED TEST 26 #\n";
	}

	values[0] = -3, values[1] = -2, values[2] = -1;
	try {
		btassert<bool>(findMaxValue(values, 3) == -1);
		cout << "Passed TEST 27: findMaxValue([-3,-2,-1])\n";
	} catch (bool b) {
		cout << "# FAILED TEST 27 #\n";
	}

	values[0] = 0, values[1] = 1, values[2] = 2;
	try {
		btassert<bool>(findMaxValue(values, 3) == 2);
		cout << "Passed TEST 28: findMaxValue([0,1,2])\n";
	} catch (bool b) {
		cout << "# FAILED TEST 28 #\n";
	}

	values[0] = 1, values[1] = 1, values[2] = 1;
	try {
		btassert<bool>(findMaxValue(values, 3) == 1);
		cout << "Passed TEST 29: findMaxValue([1,1,1])\n";
	} catch (bool b) {
		cout << "# FAILED TEST 29 #\n";
	}

	values[0] = INT_MIN, values[1] = INT_MIN, values[2] = INT_MIN;
	try {
		btassert<bool>(findMaxValue(values, 3) == INT_MIN);
		cout << "Passed TEST 30: findMaxValue([INT_MIN,INT_MIN,INT_MIN])\n";
	} catch (bool b) {
		cout << "# FAILED TEST 30 #\n";
	}

	cout << "\nUNIT TEST COMPLETE\n\n";
}

template <typename X, typename A>
void btassert (A assertion)
{
	if (!assertion)
		throw X();
}