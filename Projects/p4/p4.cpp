//
// Grader comments 2014.05.23
// -15 points total
//
/*PROJECT 4
 *The purpose of project 4 is to implement and test the functionality of a binary search tree.
 *In this project, the program will read data(s) from a file and performed the correct command(s).
 *This project will be creating a tree, deleting a tree, clear a tree, insert a string(a word),
 *find a string(a word), removed a string(a word), get a string(a word), show number of nodes, print
 *the tree ascending and descending.
 
 *CHEE YEE XIONG
 *Date created: 4-29-14
 *Last date modified: 5-16-14
 
 *sources: cplusplus.com, programming challenges, Youtube.com (binary search trees).
 */
 
#include "BSTree.h"
#include "Word.h"

#include <fstream>
#include <sstream>
#include <cstdlib>
#include <iostream>

using namespace std;

/*
 *This is function run_project4(string filename).  This function take in a string argument
 *and use the string as the input filename to start project 4 simulation.
 *@param string filename is the string of the input filename.
 */
void run_project4(string filename);

/*Project 4 entry point*/
int main(int argc, char* argv[]){
	if(argc >= 2){
		if(argc == 2){
			run_project4(argv[1]);
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

void run_project4(string filename){
    ifstream myfile(filename.c_str());

    if (myfile.is_open()){
        string line;
        string operationChar;
        bool treeExist = false;
        
        BSTree<Word>* wordTree;

        while (getline(myfile,line)){
            operationChar = toupper(line.at(0));
            line.erase(0,2);
			
			// Rob added to get unit test to work
            if(treeExist == false && operationChar != "#" && operationChar != "C"){
                cout << "MUST CREATE TREE INSTANCE" << endl;
				continue;
            }

            //creating a tree
            if(operationChar == "C"){
                if(treeExist == false){
                    wordTree = new BSTree<Word>;
                    treeExist = true;
                }
                else{
                    delete wordTree;
                    wordTree = new BSTree<Word>;
                }
                cout << "TREE CREATED" << endl;
            }

            //clear the tree if there is a list.
            if(operationChar == "X" && treeExist == true){
                wordTree->clear();
                cout << "TREE CLEARED" << endl;
            }

            //deleting the tree
            if(operationChar == "D" && treeExist == true){
                delete wordTree;
                wordTree = NULL;
                treeExist = false;
                cout << "TREE DELETED" << endl;
            }

            //inserting data into the tree
            if(operationChar == "I" && treeExist == true){
                Word word(line);

                if(wordTree->insert(word)){
                    cout << "WORD " << line << " INSERTED" << endl;
                }
                else{
                    Word *wordExist = wordTree->get(word);
                    wordExist->incrementCount();
                    cout << "WORD " << line << " INCREMENTED" << endl;
                }
            }

            //find a data in the tree
            if(operationChar == "F" && treeExist == true){
                Word word(line);

                if(wordTree->find(word)){
                    cout << "FOUND " << line << endl;
                }
                else{
                    if(wordTree == NULL){
                        cout << "TREE EMPTY" << endl;
                    }
                    else{
                        cout << line << " NOT FOUND" << endl;
                    }
                }
            }

            //removing data
            if(operationChar == "R" && treeExist == true){
                Word word(line);

                if(wordTree->remove(word)){
                    cout << "REMOVED " << line << endl;
                }
                else{
					//
					// Grader comments 2014.05.23
					// Shouldn't check wordTree for null, but rather
					// check whether wordTree has any nodes in it.
					// -5 points
					//
                    //if(wordTree == NULL){
					if(wordTree->getSize() == 0){
                        cout << "TREE EMPTY" << endl;
                    }
                    else{
                        cout << line << " NOT FOUND" << endl;
                    }
                }
            }

            //getting data
            if(operationChar == "G" && treeExist == true){
                Word word(line);
                Word* getWord = wordTree->get(word);

                if(getWord != NULL){
                    cout << "GOT " << line << " " << getWord->getCount() << endl;
                }
                else{
                    if(getWord == NULL){
                        cout << "TREE EMPTY" << endl;
                    }
                    else{
                        cout << line << " NOT FOUND" << endl;
                    }
                }
            }

            //get size of the tree
            if(operationChar == "N" && treeExist == true){
                cout << "TREE SIZE IS " << wordTree->getSize() << endl;
            }

            //print tree in order
            if(operationChar == "O" && treeExist == true){
                if(wordTree->getSize() != 0){
                    wordTree->inOrder();
                }
                else{
                    cout << "TREE EMPTY" << endl;
                }
            }

            //print tree in reverse order.
            if(operationChar == "E" && treeExist == true){
                if(wordTree->getSize() != 0){
                    wordTree->reverseOrder();
                }
                else{
                    cout << "TREE EMPTY" << endl;
                }
            }

			//
			// Grader comments 2014.05.23
			// Should show this message even if line is blank. Also erroneously
			// shows this message after deleting the tree legitimately. Commented
			// this out and added logic at top of this while loop to get the
			// unit test to run.
			// -10 points
			//
#if 0
            //display message if there is no tree for an operation.
            if(treeExist == false && operationChar != "#" && line != ""){
                cout << "MUST CREATE TREE INSTANCE" << endl;
            }
#endif
        }
		myfile.close();

        //delete the tree if there is a tree before exiting. NULL tree pointer.
        if(treeExist == true){
            delete wordTree;
            wordTree = NULL;
        }
    }
    else{
        cout << "Cannot open file: " << filename << endl;
    }
}