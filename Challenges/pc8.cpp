/*
 * Programming Challenge 8
 */
#include <cassert>
#include <cstring>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <stdlib.h>
using namespace std;

/*
 * Process the argv array (command-line arguments to the program). Ignore 
 * argv[0] as that is the program name. Perform the following operations on 
 * the input values:
 * <ul>
 * <li>10 -- invoke the function onTen</li>
 * <li>20 -- invoke the function onTwenty</li>
 * <li>30 -- invoke the function onThirty</li>
 * <li>40 -- invoke the function onForty</li>
 * <li>50 -- invoke the function onFifty</li>
 * <li>any other value -- invoke the function onError</li>
 * </ul>
 * @param argc an integer containing the number of arguments passed to the program
 *        on the command-line
 * @param argv an array containing the command-line arguments
 */
void processArguments (int argc, char* argv[]);

/* for unit testing -- do not alter */
map<int,int> counters;
bool checkArgs (int argc, char* argv[]);
void onTen ();
void onTwenty ();
void onThirty ();
void onForty ();
void onFifty ();
void onError ();

template <typename X, typename A>
void btassert(A assertion);
void unittest (int argc, char* argv[]);

int main (int argc, char* argv[])
{
   
   unittest(argc, argv);
	
	return 0;
}

void processArguments (int argc, char* argv[])
{
    int argvNumber = 0;

    for(int i = 0; i < argc; i++)
    {
        argvNumber = atoi(argv[i]);
    
        if(argvNumber == 10)
            onTen();
        
        else if(argvNumber == 20)
            onTwenty();
          
        else if(argvNumber == 30)
            onThirty();

        else if(argvNumber == 40)
            onForty();
    
        else if(argvNumber == 50)
            onFifty();

        else if(isalpha(argv[i][i]))
            onError();
    }
}

/*
 * Unit testing functions. Do not alter.
 */

void unittest (int argc, char* argv[])
{
	if (argc > 1 && strcmp(argv[1], "teacher") == 0 && checkArgs(argc, argv))
	{
		cout << "\nSTARTING UNIT TEST\n\n";
		
		counters[10] = 0, counters[20] = 0, counters[20] = 0, counters[40] = 0, counters[50] = 0;
		counters[99] = 0; // errors
	
		processArguments(argc, argv);
	
		try {
			btassert<bool>(counters[10] == 1);
			cout << "Passed TEST 1: counters[10]\n";
		} catch (bool b) {
			cout << "# FAILED TEST 1 counters[10] #\n";
		}
	
		try {
			btassert<bool>(counters[20] == 1);
			cout << "Passed TEST 2: counters[20]\n";
		} catch (bool b) {
			cout << "# FAILED TEST 2 counters[20] #\n";
		}
	
		try {
			btassert<bool>(counters[30] == 1);
			cout << "Passed TEST 3: counters[30]\n";
		} catch (bool b) {
			cout << "# FAILED TEST 3 counters[30] #\n";
		}
	
		try {
			btassert<bool>(counters[40] == 1);
			cout << "Passed TEST 4: counters[40]\n";
		} catch (bool b) {
			cout << "# FAILED TEST 4 counters[40] #\n";
		}
	
		try {
			btassert<bool>(counters[50] == 1);
			cout << "Passed TEST 5: counters[50]\n";
		} catch (bool b) {
			cout << "# FAILED TEST 5 counters[50] #\n";
		}
	
		try {
			btassert<bool>(counters[99] == 2); // teacher and 60 should be errors
			cout << "Passed TEST 6: counters[99]\n";
		} catch (bool b) {
			cout << "# FAILED TEST 6 counters[99] #\n";
		}
		
		cout << "\nUNIT TEST COMPLETE\n\n";
	}
	else
	{
		cout << "\nRun program with the following argument list:\n";
		cout << "\n\t\"teacher 10 20 30 40 50 60\"\n";
	 	cout << "\nto run the UNIT TEST.\n\n";
	}
}

void onTen ()
{
	counters[10]++;
}

void onTwenty ()
{
	counters[20]++;
}

void onThirty ()
{
	counters[30]++;
}

void onForty ()
{
	counters[40]++;
}

void onFifty ()
{
	counters[50]++;
}

void onError ()
{
	counters[99]++;
}

bool checkArgs (int argc, char* argv[])
{
	if (argc == 8)
	{
		// convert the argv[2] to argv[7] contents to integers
		int* temps = new int[6];
		stringstream ss;
		for (int i=0, j=2; i<6; i++,j++)
		{
			ss.str(argv[j]);
			ss >> temps[i];
			ss.clear();
		}
		
		// check to see that argv[2] to argv[7] match the expected launch UNIT TEST values
		for (int i=0,j=10; i<6; i++,j+=10)
		{
			if (temps[i] != j)
				return false;
		}
		
		delete [] temps;
		
		return true;
	}
	return false;
}

template <typename X, typename A>
void btassert (A assertion)
{
    if (!assertion)
		throw X();
}