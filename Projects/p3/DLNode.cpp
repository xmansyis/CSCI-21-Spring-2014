/*
 *Project 3, DLNode.cpp
 *
 *CHEE YEE XIONG
 *Date created: 4-17-14
 *Last date modified: 4-25-14
 */

#include "DLNode.h"
#include<iostream>

DLNode::DLNode(){
	contents = 0;
	next = NULL;
	previous = NULL;
}

DLNode::DLNode(int newContents){
	contents = newContents;
	next = NULL;
	previous = NULL;
}

DLNode::~DLNode(){}

void DLNode::setContents(int newContents){
	contents = newContents;
}

void DLNode::setPrevious(DLNode* newPrevious){
	previous = newPrevious;
}

void DLNode::setNext(DLNode* newNext){
	next = newNext;
}

int DLNode::getContents() const{
	return contents;
}

DLNode* DLNode::getNext() const{
	return next;
}

DLNode* DLNode::getPrevious() const{
	return previous;
}