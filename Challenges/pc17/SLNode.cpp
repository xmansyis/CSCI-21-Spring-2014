
#include "SLNode.h"
#include <cstddef>

SLNode::~SLNode(){
    next = NULL;
}

SLNode::SLNode(){
    content = 0;
    next = NULL;
}

SLNode::SLNode(int newContent){
    content = newContent;
    next = NULL;
}

void SLNode::setContents(int newContent){
    content = newContent;
}

int SLNode::getContents() const{
    return content;
}

void SLNode::setNextNode(SLNode* newNode){
    next = newNode;
}

SLNode* SLNode::getNextNode () const{
    return next;
}