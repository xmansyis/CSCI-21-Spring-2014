/*
 *Project 3, DLList.cpp
 *
 *CHEE YEE XIONG
 *Date created: 4-17-14
 *Last date modified: 4-25-14
 */
 
#include "DLList.h"
#include <iostream>

DLList::DLList(){
	size = 0;
	head = NULL;
	tail = NULL;
}

DLList::~DLList(){
	clear();
}

void DLList::pushFront(int newContents){
	DLNode* newNode = new DLNode(newContents);
	
	if(head == NULL){		
		head = newNode;
		tail = newNode;
	}
	else if(head->getNext() == NULL){
		newNode->setNext(head);
		tail->setPrevious(newNode);
		head = newNode;
	}
	else{
		newNode->setNext(head);
		DLNode* ptr = tail;
		
		while(ptr->getPrevious() != NULL){
			ptr = ptr->getPrevious();
		}
		
		ptr->setPrevious(newNode);
		head = newNode;
	}
	size++;
}

void DLList::pushBack(int newContents){
	if(head != NULL){
        DLNode* newNode = new DLNode(newContents);
        DLNode* ptr = head;
		
        while(ptr->getNext() != NULL){
            ptr = ptr->getNext();
        }
		
        newNode->setPrevious(tail);
        ptr->setNext(newNode);
		tail = newNode;
        size++;
    }
    else{
        pushFront(newContents);
    }	
}

void DLList::insert(int newContents){
	DLNode* newNode = new DLNode(newContents);
	
	if(head == NULL){
		pushFront(newContents);
	}
	else if(head->getNext() == NULL){
		if(head->getContents() >= newContents){
			pushFront(newContents);
		}
		else{
			pushBack(newContents);
		}
	}
	else{
		DLNode* ptr = head;
		DLNode* trailerPtr = NULL;
	
		while(ptr->getNext() != NULL && newContents >= ptr->getContents()){
			trailerPtr = ptr;
			ptr = ptr->getNext();
		}

		if(ptr->getNext() == NULL && newContents >= ptr->getContents()){
			pushBack(newContents);
		}
		else if(ptr->getNext() == NULL && newContents <= ptr->getContents()){
			newNode->setNext(ptr);
			newNode->setPrevious(trailerPtr);
			trailerPtr->setNext(newNode);
			tail->setPrevious(newNode);
			size++;
		}
		else if(trailerPtr == NULL){
			pushFront(newContents);
		}
		else{
			newNode->setNext(ptr);
			newNode->setPrevious(trailerPtr);
			trailerPtr->setNext(newNode);
			ptr->setPrevious(newNode);
			size++;
		}
	}	
}

void DLList::popFront(){
	if(head != NULL){
		if(head->getNext() == NULL){
			delete head;
			head = NULL;
			size--;
		}
		else{
			DLNode* temp = head;
			head = head->getNext();
			head->setPrevious(NULL);
			delete temp;
			temp = NULL;
			size--;
		}
	}	
}

void DLList::popBack(){
	if(head !=NULL){
		if(head->getNext() == NULL){
			delete head;
			head = NULL;
			size--;
		}
		else{
			DLNode* temp = tail;
			tail = tail->getPrevious();
			tail->setNext(NULL);
			delete temp;
			temp = NULL;
			size--;
		}
	}
}

void DLList::clear(){
	if(head != NULL){
		if(head->getNext() == NULL){
			delete head;
			head = NULL;
			tail = NULL;
			size--;
		}
		else{
			DLNode* temp = NULL;
			while(head->getNext() != NULL){
				temp = head;
				head = head->getNext();
				delete temp;
				size--;
			}
			size--;
			delete head;
			head = NULL;
			tail = NULL;
			temp = NULL;
		}
	}
}

int DLList::getFront() const{
	if(head == NULL){
		throw string("LIST EMPTY");
	}
	else
		return head->getContents();
}

int DLList::getBack() const{
	if(head == NULL){
		throw string("LIST EMPTY");
	}
	else
		return tail->getContents();
}

bool DLList::get(int target) const{
	bool integerFound = false;
	DLNode* ptr = head;
	
	while(ptr != NULL){
		if(ptr->getContents() == target){
			integerFound = true;
		}
		
		ptr = ptr->getNext();
	}
	return integerFound;
}

bool DLList::removeFirst(int target){
	bool integerFound = false;
	
	if(head == NULL){
		integerFound = false;
	}
	else if(head->getContents() == target){
		popFront();
		integerFound = true;
	}
	else{
        DLNode* trailerPtr = NULL;
        DLNode* ptr = head;
                
        while(ptr->getNext() != NULL && ptr->getContents() != target){
            trailerPtr = ptr;
            ptr = ptr->getNext();
        }
      
		if(ptr->getNext() == NULL && ptr->getContents() != target){
            integerFound = false;
        }
		else if(ptr->getNext() == NULL && ptr->getContents() == target){
			popBack();
			integerFound = true;
		}
        else if(ptr == head){
            popFront();
            integerFound = true;
        }
        else{
			DLNode* temp = ptr;
            trailerPtr->setNext(ptr->getNext());
			ptr = ptr->getNext();
			ptr->setPrevious(trailerPtr);
			
            delete temp;
            size--;
            integerFound = true;
        }
    }
	return integerFound;
}

bool DLList::removeAll(int target){
	bool integerFound = false;
	
	if(head == NULL){
		integerFound = false;
	}
	else{
		for(unsigned int i = 0; i < size; i++){
			if(removeFirst(target))
				integerFound = true;
		}
	}
	
	return integerFound;
}

unsigned int DLList::getSize() const{
	return size;
}

ostream& operator<< (ostream& outs, const DLList& src){
	DLNode* ptr = src.head;
	
	while(ptr !=NULL){
		outs << ptr->getContents();
		if(ptr->getNext() != NULL)
			outs << ", ";
		
		ptr = ptr->getNext();
	}
	
    return outs;
}