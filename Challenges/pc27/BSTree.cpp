#include "BSTree.h"

BSTree::BSTree(){
    root = NULL;
    size = 0;
}

BSTree::~BSTree(){
    clear();
}

void BSTree::clear (){
    clear(root);
}

void BSTree::clear (BSTNode*& ROOT){
    if(ROOT != NULL){
        clear(ROOT->getLeftChild());
        clear(ROOT->getRightChild());
        delete ROOT;
        ROOT = NULL;
        size--;
    }
}

bool BSTree::insert (int newContent){
    return insert(newContent, root);
}

bool BSTree::insert (int newContent, BSTNode*& ROOT){
    if(ROOT == NULL){
        ROOT = new BSTNode(newContent);
        size++;
        return true;
    }
    else if(newContent < ROOT->getContents()){
            return insert(newContent, ROOT->getLeftChild());
    }
    else if(newContent > ROOT->getContents()){
            return insert(newContent,ROOT->getRightChild());
    }
    else{
            return false;
    }
}

unsigned int BSTree::getSize () const{
    return size;
}

void BSTree::inOrder (){
    inOrder(root);
}

void BSTree::inOrder (BSTNode* ROOT){
     if(ROOT != NULL){
        inOrder(ROOT->getLeftChild());
        cout << ROOT->getContents() << " ";
        inOrder(ROOT->getRightChild());
    }
}

bool BSTree::remove(int content){
    return remove(content, root);
}

void BSTree::removeMax(int& content, BSTNode*& ROOT){
    if(ROOT->getLeftChild() == NULL){
        BSTNode* aNode = ROOT;
        ROOT = aNode->getRightChild();
        content = aNode->getContents();
        delete aNode;
        size--;
    }
    else{
        removeMax(content, ROOT->getLeftChild());
    }
}

bool BSTree::remove(int content, BSTNode*& ROOT){
    if(ROOT == NULL){
        return false;
    }
    else if(content > ROOT->getContents()){
        return remove(content, ROOT->getRightChild());
    }
    else if(content < ROOT->getContents()){
        return remove(content, ROOT->getLeftChild());
    }
    else{
        if(ROOT->getLeftChild() == NULL){
            BSTNode* aNode = ROOT;
            ROOT = ROOT->getRightChild();
            delete aNode;
            size--;
        }
        else{
            removeMax(ROOT->getContents(), ROOT->getLeftChild());
        }
        
        return true;
    }
}