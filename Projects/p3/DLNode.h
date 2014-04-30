/*
 *Project 3, DLNode.h
 *
 *CHEE YEE XIONG
 *Date created: 4-17-14
 *Last date modified: 4-25-14
 */

#pragma once

class DLNode{
	public:
		/*
         *Default constructor. Initializes contents = 0, previous = NULL, next = NULL.
         */
		DLNode();
		
		/*
         *Overloaded constructor. Initialize contents with newContents, next and previous to NULL.
         *@param int newContents will be use to set content.
         */
		DLNode(int newContents);
		
		/*
         *Destructor. Nothing to be done.
         */
		virtual ~DLNode();
		
		/*
         *Function setContents().  Take in an int to set new contents.
         *@param int newContent use to set a new content value.
         */
		void setContents(int newContents);
		
		/*
         *Function setPrevious(DLNode*).  This function set a previous new node;
         *@param DLNode* newPrevious is the variable for previous new node;
         */
		void setPrevious(DLNode* newPrevious);
		
		/*
         *Function setNext(DLNode*).  This function set a next node;
         *@param DLNode* newNext is the variable for next node;
         */
		void setNext(DLNode* newNext);
		
		/*
         *Function getContents().  This function return the contents.
		 @return int is the return content.
         */
		int getContents() const;
		
		/*
         *Function getNext().  Return the next node.
		 @return DLNode* return the next node.
         */
		DLNode* getNext() const;
		
		/*
         *Function getPrevious().  Return the previous node.
		 @return DLNode* return the previous node.
         */
		DLNode* getPrevious() const;

	private:
		//data members
		int contents;
		DLNode* next;
		DLNode* previous;
};