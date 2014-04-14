#pragma once

#include "SLNode.h"

#include<cstdlib>
#include<sstream>
#include<iostream>

using namespace std;

class SList{
    public:
        /*
         *Default constructor.  Set head == NULL, count = 0;
         */
        SList();
        
        /*
         *Destructor.  delete the object when it's done.
         */
        virtual ~SList();
        
        /*
         *Function insertHead() insert a new content infront of the list.
         *@param int newHead is the content to be insert from the front.
         */
        void insertHead(int newContent);
        
        /*
         *Function insertTail() insert a new content in the back of the list.
         *@param int newContent is the content to be insert to the back of the list.
         */
        void insertTail(int newContent);
        
        /*
         *Function removeHead() remove the first content of the list.
         */
        void removeHead();
        
        /*
         *Function removeTail() remove the last content in the list.
         */
        void removeTail();
        
        /*
         *Function clear() called the function removeHead and delete the link list
         */
        void clear();
        
        /*
         *Function getSize() return the size of the list.
         */
        unsigned int getSize() const;
        
        /*
         *Function toString() return the content(s) in the list.
         */
        string toString() const;
    
    private:
        SLNode *head;
        unsigned int count;
};