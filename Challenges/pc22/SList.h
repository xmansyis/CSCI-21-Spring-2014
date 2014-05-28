#pragma once

#include "SLNode.h"

#include<cstdlib>
#include<sstream>
#include<iostream>
#include<string>

using namespace std;

template<class T>
class SList{
    public:
        /*
         *Default constructor.  Set head == NULL, count = 0;
         */
        SList()
        :head(NULL), count(0)
        {}
        
        /*
         *Destructor.  delete the object when it's done.
         */
        ~SList(){
            clear();
        }
        
        /*
         *Function insertHead() insert a new content infront of the list.
         *@param int newHead is the content to be insert from the front.
         */
        void insertHead(T newContent){
            SLNode<T>* aNode = new SLNode<T>(newContent); 
            aNode->setNextNode(head); 
            head = aNode;
            count++;
        }
        
        /*
         *Function insertTail() insert a new content in the back of the list.
         *@param int newContent is the content to be insert to the back of the list.
         */
        void insertTail(T newContent){
            if(head != NULL){
                SLNode<T>* temp = new SLNode<T>(newContent);
                SLNode<T>* ptr = head;
                while(ptr->getNextNode() != NULL){
                    ptr = ptr->getNextNode();
                }
        
                ptr->setNextNode(temp);
                count++;
            }
            else{
                insertHead(newContent);
            }
        }
        /*
         *Function removeHead() remove the first content of the list.
         */
        void removeHead(){
            if(head != NULL){
                SLNode<T>* temp = head;
                head = head->getNextNode();
                delete temp;
                count--;
            }
        }
        
        /*
         *Function removeTail() remove the last content in the list.
         */
        void removeTail(){
            if(head != NULL){
                SLNode<T>* ptr = head;
                SLNode<T>* trailerPtr = NULL;
        
                while(ptr->getNextNode() != NULL){
                    trailerPtr = ptr;
                    ptr = ptr->getNextNode();
                }
        
                delete ptr;
                if(trailerPtr == NULL){
                    head = NULL;
                }
                else{
                    trailerPtr->setNextNode(NULL);
                }
            count--;
            }       
        }
        
        /*
         *Function clear() called the function removeHead and delete the link list
         */
        void clear(){
            while(head !=NULL)
               removeHead();
        }

        
        /*
         *Function getSize() return the size of the list.
         */
        unsigned int getSize() const{
            return count;
        }
        
        /*
         *Function toString() return the content(s) in the list.
         */
        string toString() const{
            stringstream ss;
    
            for(SLNode<T>* i = head; i != NULL; i = i->getNextNode()){
                ss << i->getContents();
                if(i->getNextNode() != NULL)
                    ss << ",";
             }
            return ss.str();
        }
        
        /*
         *Function insert().  Create a new SLnode and isert it in the oreect position
         *in the list so the values in the nodes are in ascending order.
         *@param int newContent is the number to be put in the list.
         */
        void insert(T newContent){
            SLNode<T>* newNode = new SLNode<T>(newContent);
    	    if(head == NULL){
        		insertHead(newContent);
        	}
        	else if(head->getNextNode() == NULL){
        		if(head->getContents() >= newContent){
        			insertHead(newContent);
        		}
        		else{
        			insertTail(newContent);
        		}
        	}
        	else{
        		SLNode<T>* ptr = head;
        		SLNode<T>* trailerPtr = NULL;
        	
        		while(ptr->getNextNode() != NULL && newContent >= ptr->getContents()){
        			trailerPtr = ptr;
        			ptr = ptr->getNextNode();
        		}
        
        		if(ptr->getNextNode() == NULL && newContent >= ptr->getContents()){
        				insertTail(newContent);
        				
        	
        		}
        		else if(ptr->getNextNode() == NULL && newContent <= ptr->getContents()){
        	
        				newNode->setNextNode(ptr);
        				
        				trailerPtr->setNextNode(newNode);
        				
        				count++;
        		}
        		else if(trailerPtr == NULL){
        			insertHead(newContent);
        		}
        		else{
        			newNode->setNextNode(ptr);
        			trailerPtr->setNextNode(newNode);
        			count++;
        		}
        	}
        }
        
        /*
         *Function removeFirst().  Remove the first match content in the link list and 
         *return true, else return false.
         *@param int removeContent is the content to be remove.
         */
        bool removeFirst(T removeContent){
            if(head == NULL){
                return false;
            }
            else{
                SLNode<T>* trailer = NULL;
                SLNode<T>* spot = head;
                
                while(spot!= NULL && spot->getContents() != removeContent){
                    trailer = spot;
                    spot = spot->getNextNode();
                }
                if(spot == NULL){
                    return false;
                }
                else if(spot == head){
                    removeHead();
                    return true;
                }
                else{
                    trailer->setNextNode(spot->getNextNode());
                    delete spot;
                    count--;
                    return true;
                }
            }
        }
        
        bool removeAll(T target)
		{
			bool removeValue = false;
			for(unsigned int i = 0; i < count; i++){
				if(removeFirst(target)){
					removeValue = true;
				}
			}
			return removeValue;
		}
    
    private:
        SLNode<T>* head;
        unsigned int count;
};