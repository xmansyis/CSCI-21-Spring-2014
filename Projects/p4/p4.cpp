
#include "BSTree.h"
#include "Word.h"

#include <fstream>
#include <sstream>
#include <cstdlib>
#include <iostream>

using namespace std;

void run_project4(string filename);

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
			
	        //clear the list if there is a list.
		    if(operationChar == "X" && treeExist == true){
		        wordTree->clear();
		        cout << "TREE CLEARED" << endl;
		    }
		    
		    if(operationChar == "D" && treeExist == true){
		        delete wordTree;
		        wordTree = NULL;
		        treeExist = false;
		        cout << "TREE DELETED" << endl;
		    }
	    
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
	    
		    if(operationChar == "F" && treeExist == true){
		        Word word(line);
	        
		        if(wordTree->find(word)){
		            cout << "FOUND " << line << endl;
		        }
		        else{
		            cout << line << " NOT FOUND" << endl;
		        }
		    }
	    
		    if(operationChar == "R" && treeExist == true){
		        Word word(line);
		        
		        if(wordTree->remove(word)){
		            cout << "REMOVED " << line << endl;
		        }
		        else{
		            cout << line << " NOT FOUND" << endl;
		        }
		    }
	    
		    if(operationChar == "G" && treeExist == true){
		        Word word(line);
		        Word* getWord = wordTree->get(word);

		        if(getWord != NULL){
		            cout << "GOT " << line << " " << getWord->getCount() << endl;
		        }
		        else{
		            cout << line << " NOT FOUND" << endl;
		        }
		    }
		    
		    if(operationChar == "N" && treeExist == true){
		        cout << "TREE SIZE IS " << wordTree->getSize() << endl;
		    }

		    if(operationChar == "O" && treeExist == true){
		        if(wordTree->getSize() != 0){
		        wordTree->inOrder();
		        }
		        else{
		            cout << "TREE EMPTY" << endl;
		         }
		    }
		    
		    if(operationChar == "E" && treeExist == true){
                if(wordTree->getSize() != 0){
		            wordTree->reverseOrder();
                }
		        else{
		            cout << "TREE EMPTY" << endl;
		        }
		    }
			
			//display message if there is no list for an operation.
			if(treeExist == false && operationChar != "#" && line != ""){
				cout << "MUST CREATE TREE INSTANCE" << endl;
			}
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