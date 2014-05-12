#pragma once

#include<iostream>
#include<cstdlib>
using namespace std;

class BSTNode{
    public:
        BSTNode();
        BSTNode(int newContents);
        ~BSTNode();
        void setContents(int newContents);
        void setLeftChild(BSTNode* left);
        void setRightChild(BSTNode* right);
        int getContents() const;
        int& getContents();
        BSTNode* getLeftChild() const;
        BSTNode* getRightChild() const;
        BSTNode*& getLeftChild();
        BSTNode*& getRightChild();
    
    private:
        BSTNode* leftChild;
        BSTNode* rightChild;
        int contents;
};