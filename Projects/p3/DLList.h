/*
 *Project 3, DLList.h
 *
 *CHEE YEE XIONG
 *Date created: 4-17-14
 *Last date modified: 4-25-14
 */

#pragma once

#include "DLNode.h"
#include<cstdlib>
#include<iostream>
#include<sstream>
using namespace std;

class DLList{
	public:
		/*
         *Default constructor.  Set head = NULL, tail = NULL, size = 0;
         */
		DLList();
		
		/*
         *Destructor, call the clear function.
         */
		~DLList();
		
		/*
         *Function pushFront(). Create new DLNode with newContents and attach at head.
		 *@param int newContents is the newContents inside the new DLNode.
         */
		void pushFront(int newContents);
		
		/*
         *Function pushBack(). Create new DLNode with newContents and attach at tail.
		 *@param int newContents is the newContents inside the new DLNode.
         */
		void pushBack(int newContents);
		
		/*
         *Function insert(). Create new DLNode with newContents and insert in ascending order.
		 *@param int newContents is the newContents that will be use to insert in the list.
         */
		void insert(int newContents);
		
		/*
         *Function popFront(). Remove first node if the list is not empty.
         */
		void popFront();
		
		/*
         *Function popBack(). Remove last node if the list is not empty.
         */
		void popBack();
		
		/*
         *Function clear(). Remove all the node(s) in the list.
         */
		void clear();
		
		/*
         *Function removeFirst().  Remove the first instance of a DLNode containing target if target exist.
		 *@return bool, return true if target exist, else return false.
         */
		bool removeFirst(int target);
		
		/*
         *Function removeAll().  Remove all instances of DLNode containing target if target exist.
		 *@return bool, return true if target exist, else return false.
         */
		bool removeAll(int target);
		
		/*
         *Function getSize(). Return the size of the list.
		 *return unsigned int, return size of the list.
         */
		unsigned int getSize() const;
		
		/*
         *Function getFront().  Return the first content in the list.
		 *@return int, return the first content.
         */
		int getFront() const;
		
		/*
         *Function getBack().  Return the last content in the list.
		 *@return int, return the last content in the list.
         */
		int getBack() const;
		
		/*
         *Function popFront(). Remove first node if the list is not empty.
		 *return bool, return true if target exist, else return false.
         */
		bool get(int target) const;
		
		/*
		 *friend overloaded operator << to print all the element in the list.
		 @param ostream& object type ostream& outs.
		 @param const DLList&, object type DLList& src.
		 */
		friend ostream& operator<< (ostream& outs, const DLList& src);
		
	private:
	    //data members
		unsigned int size;
		DLNode* head;
		DLNode* tail;
};