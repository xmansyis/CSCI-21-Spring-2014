#include "BSTNode.h"

BSTNode::BSTNode(){
    leftChild = NULL;
    rightChild = NULL;
    contents = 0;
}

BSTNode::~BSTNode(){
    leftChild = NULL;
    rightChild = NULL;
}

BSTNode::BSTNode(int newContents){
    leftChild = NULL;
    rightChild = NULL;
    contents = newContents;
}

void BSTNode::setContents(int newContents){
    contents = newContents;
}

void BSTNode::setLeftChild(BSTNode* left){
    leftChild = left;
}

void BSTNode::setRightChild(BSTNode* right){
    rightChild = right;
}

int BSTNode::getContents () const{
    return contents;
}

int& BSTNode::getContents(){
    return contents;
}

BSTNode* BSTNode::getLeftChild() const{
    return leftChild;
}

BSTNode* BSTNode::getRightChild() const{
    return rightChild;
}
        
BSTNode*& BSTNode::getLeftChild(){
    return leftChild;
}

BSTNode*& BSTNode::getRightChild(){
    return rightChild;
}