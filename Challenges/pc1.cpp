/*
 * Programming Challenge 1
 */
#include <cassert>
#include <iostream>
using namespace std;

string greet (string name);
string checkExperience (char hasExperience);

/* for unit testing -- do not alter */
template <typename X, typename A>
void btassert(A assertion);
void unittest (string s, char c);

int main (int argc, char* argv[])
{
    //declare string variable named userName.
    //a welcome message and ask for user name.
    //store user input in the variable userName.
    string userName;
    cout << "Welcome! What is your name?: ";
    getline(cin,userName);
    
    char programmedBefore = 'z';
    string userAnswer;
    //a while loop to ask the user again to enter a correct response to the question.
    while (programmedBefore == 'z')
    {
        cout << "Have you programmed in C++ before? (Y/N): ";
        getline(cin, userAnswer);
        
        //change userAnswer to uppercase letters with a for loop.
        for (int i = 0; i < userAnswer.size(); i++)
            userAnswer[i] = toupper(userAnswer[i]);
            
         //if statement to check for correct input from the user.
         if(userAnswer == "YES" || userAnswer =="Y" || userAnswer == "NO" || userAnswer == "N")
        {
            if(userAnswer == "YES" || userAnswer =="Y")
                programmedBefore = 'Y';
            else
                programmedBefore = 'N';
            
            //run the unittest function.
            unittest(userName, programmedBefore);
        }
        else
            cout << "Please enter either Y or N: ";
    }
	
	return 0;
}

/*
 * Create a string greeting that is the concatenation of a message 
 * and a name.
 * @param name a string containing a user name
 * @return the string "Nice to meet you, NAME" where NAME contains 
 *         the parameter value
 */
string greet (string name)
{
	string greet = "Nice to meet you, " + name;
	return greet;
}

/*
 * Create a string message based upon whether or not a user has C++ 
 * programming experience.
 * @param hasExperience a char ('Y'es or 'N'o) representing whether or 
 *        not a user has C++ programming experience
 * @return "Welcome back" when hasExperience is 'Y', else 'Get ready to 
 *         have some fun"
 */
string checkExperience (char hasExperience)
{
	string message1 = "Welcome back";
	string message2 = "Get ready to have some fun";
	
	if (hasExperience == 'Y')
	    return message1;
	else
	    return message2;
}

/*
 * Unit test. Do not alter this function.
 */
void unittest (string s, char c)
{
	if (s == "fez")
	{
		cout << "\nSTARTING UNIT TEST\n\n";
		
		try {
			btassert<bool>(greet(s) == "Nice to meet you, fez");
			cout << "Passed TEST 1: greet\n";
		} catch (bool b) {
			cout << "# FAILED TEST 1 greet #\n";
		}
		
		if (toupper(c) == 'Y')
		{
			try {
				btassert<bool>(checkExperience(c) == "Welcome back");
				cout << "Passed TEST 2: checkExperience\n";
			} catch (bool b) {
				cout << "# FAILED TEST 2 checkExperience #\n";
			}
		}
		else if (toupper(c) == 'N')
		{
			try {
				btassert<bool>(checkExperience(c) == "Get ready to have some fun");
				cout << "Passed TEST 2: checkExperience\n";
			} catch (bool b) {
				cout << "# FAILED TEST 2 checkExperience #\n";
			}
		}
		
		cout << "\nUNIT TEST COMPLETE\n\n";
	}
	else
	{
		cout << greet(s) << endl;
		cout << checkExperience(c) << endl;
		cout << "\nRun program with username \"fez\" to see unit test output.\n";
	}
}

template <typename X, typename A>
void btassert (A assertion)
{
    if (!assertion)
		throw X();
}
