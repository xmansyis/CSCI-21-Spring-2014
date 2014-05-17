//
// Grader comments 2014.05.15
// + 50: naming conventions good
// + 50: header documentation good
// + 50: formatting good
// +142: driver -- see comments below; look for "grader comments" and "Rob"
// +150: DLNode good
// +280: DLList -- see comments DLList.cpp
// 
/*
 *PROJECT 3
 *This project will take in an input file and process the input file with a series of commands.  Each
 *line in the input file will contain a command and the program will perform that operation using a link list.
 *The series of commands will be to create list, clear list, delete list, insert element, add element to head,
 *add element to tail, get head content, get tail content, remove last element, remove first element,
 *eliminate element from the list, remove one element from the list, get list size, and print the list contents.
 *
 *CHEE YEE XIONG
 *Date created: 4-17-14
 *Last date modified: 4-25-14
 *
 *sources: cplusplus.com, programming challenges.
 */

#include "DLList.h"

#include<cassert>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<string>
#include<fstream>

using namespace std;

/*
 *Function run_project3().  This function will take in an input file name and perform a series of commands.
 *The function will display a message for every operations it had performed.
 *@param string, is the input file name.
 */
void run_project3(string filename);
template <typename X, typename A>
void btassert(A assertion);

//project 3 entry point.
int main(int argc, char* argv[]){
	
	if(argc >= 2){
		if(argc == 2){
			run_project3(argv[1]);
		}
		else{
			string filename;
			for(int i = 1; i < argc; i++){
				if(argc == i){
					filename = filename + argv[i];
				}
				else{
					filename = filename + argv[i] + " ";
				}
			}
	
			cout << "Cannot open file: " << filename << endl;
		}	
	}
	else{
		cout << "Missing input file name in command line! Re-run with an input file name at command line. " << endl;
	}
	
	return 0;
}

//
// Grader comments 2014.05.15
// -8: X, D, A, Z, T, K, N, P should report "MUST CREATE LIST INSTANCE" when there is no list
//
void run_project3(string filename){

	ifstream myfile(filename.c_str());
    
	if (myfile.is_open()){
		string line;
		string charLetter;
		bool doesListExist = false;
		
		DLList* list;
        
		while (getline(myfile,line)){
			
			charLetter = line.at(0);
			line.erase(0,1);
			int newNumber = 0;
			stringstream converter(line);
			converter >> newNumber;
			
			//creating a list.
			if(charLetter == "C"){
				if(doesListExist == false){
					list = new DLList;
				}
				else if (doesListExist == true){
					delete list;
					list = new DLList;
				}
					
				cout << "LIST CREATED" << endl;
				doesListExist = true;
			}
	
	        //clear the list if there is a list.
			if(charLetter == "X" && doesListExist == true){
				list->clear();
				cout << "LIST CLEARED" << endl;
			}
			
			//delete the list if there is a list.
			if(charLetter == "D" && doesListExist == true){
				delete list;
				list = NULL;
				cout << "LIST DELETED" << endl;
				doesListExist = false;
			}
			
			//insert a newNumber into the list if there is list.
			if(charLetter == "I" && doesListExist == true){
				list->insert(newNumber);
				cout << "VALUE " << newNumber << " INSERTED" << endl;
			}
			
			//add a newNumber into the front of the list if there is list.
			if(charLetter == "F" && doesListExist == true){
				list->pushFront(newNumber);
				cout << "VALUE " << newNumber << " ADDED TO HEAD" << endl;
			}
			
			//insert a newNumber into the back of the list if there is list.
			if(charLetter == "B" && doesListExist == true){
				list->pushBack(newNumber);
				cout << "VALUE " << newNumber << " ADDED TO TAIL" << endl;
			}
			
			//get the first element in the list if there is list.
			if(charLetter == "A" && doesListExist == true){
				try{
					btassert<bool>(list->getSize() != 0);
					cout << "VALUE " << list->getFront() << " AT HEAD" << endl;
				}
				catch (bool b){
					cout << "LIST EMPTY" << endl;
				}
			}
			
			//get the last element in the list if there is list.
			if(charLetter == "Z" && doesListExist == true){
				try{
					btassert<bool>(list->getSize() != 0);
					cout << "VALUE " << list->getBack() << " AT TAIL" << endl;
				}
				catch (bool b){
					cout << "LIST EMPTY" << endl;
				}
			}
	
	        //remove element from front of the list if there is a list.
			if(charLetter == "T" && doesListExist == true){
				if(list->getSize() == 0){
					cout << "LIST EMPTY" << endl;
				}
				else{
					list->popFront();
					cout << "REMOVED HEAD" << endl;
				}	
			}
			
			//remove element from back of the list if there is a list.
			if(charLetter == "K" && doesListExist == true){
				if(list->getSize() == 0){
					cout << "LIST EMPTY" << endl;
				}
				else{
					list->popBack();
					cout << "REMOVED TAIL" << endl;
				}
			}
			
			//get an element from the list if there is a list.
			if(charLetter == "G" && doesListExist == true){
				if(list->get(newNumber) == true){
					cout << "VALUE " << newNumber << " FOUND" << endl;
				}
				else{
					cout << "VALUE " << newNumber << " NOT FOUND" << endl;
				}
			}
			
			//eliminate all the same element, the element to be eliminate will be newNumber.
			if(charLetter == "E" && doesListExist == true){
				if(list->removeAll(newNumber) == true){
					cout <<"VALUE " << newNumber << " ELIMINATED" << endl;
				}
				else{
					cout << "VALUE " << newNumber << " NOT FOUND" << endl;
				}
			}

            //remove an element from the list, the element to be remove will be newNumber.
			if(charLetter == "R" && doesListExist == true){
				if(list->removeFirst(newNumber) == true){
					cout << "VALUE " << newNumber << " REMOVED" << endl;
				}
				else{
					cout << "VALUE " << newNumber << " NOT FOUND" << endl;
				}
			}

            //show number of element in the list.
			if(charLetter == "N" && doesListExist == true){
						cout << "LIST SIZE IS " << list->getSize() << endl;
			}

            //print the element(s) in the list.
			if(charLetter == "P" && doesListExist == true){
				if(list->getSize() == 0){
					cout << "LIST EMPTY" << endl;
				}
				else{
					cout << *list << endl;
				}
			}
			
			//display message if there is no list for an operation.
			if(doesListExist == false && charLetter != "#" && line != ""){
				cout << "The letter is '" << charLetter << "'" << endl;
				cout << "MUST CREATE LIST INSTANCE" << endl;
			}
		}
		myfile.close();
		
		//delete the list if there is a list before exiting. NULL list pointer.
		if(doesListExist == true){
			delete list;
			list = NULL;
		}
	}
		
	else
		cout << "Cannot open file: " << filename << endl;
}

template <typename X, typename A>
void btassert (A assertion)
{
    if (!assertion)
		throw X();
}