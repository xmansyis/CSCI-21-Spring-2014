#pragma once
#include<iostream>
#include<cstdlib>
using namespace std;

template<class T>
class SLNode{
    private:
        SLNode<T>* next;
        T contents;
        
    public:
        /*
         *Default constructor. Initializes content = 0, and next = NULL.
         */
        SLNode(){
            next = NULL;
            contents = 0;
        }
        
        /*
         *Overloaded constructor. 
         *@param int contents will be use to set content.
         */
        SLNode(T newContents){
            next = NULL;
            contents = newContents;
            
        }

        
        /*
         *Destructor. set next to NULL
         */
        ~SLNode(){
            next = NULL;
        }
        
        /*
         *Function setContents.  Take in an int to set new content.
         *@param int newContent use to set a new content value.
         */
        void setContents (T newContents){
            contents = newContents;
        }

        
        /*
         *Function getContents.  This function return the content.
         */
        T getContents () const{
            return contents;
        }
        
        /*
         *Function setNextNode(SLNode).  This function set a newNode;
         *@param SLNode* next is the variable for newNode;
         */
        void setNextNode(SLNode<T>* newNode){
            next = newNode;
        }
        
        /*
         *Function getNextNode.  Return the next Node.
         */
        SLNode<T>* getNextNode () const{
            return next;
        }
};