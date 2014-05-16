#pragma once

#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;

template <typename T>
class BSTNode{
    public:
        BSTNode(T newData){
            leftChild = NULL;
            rightChild = NULL;
            data = newData;
        }

        virtual ~BSTNode()
        {/*nothing to be done*/}
        
        void setData(T newData){
            data = newData;
        }

        void setLeftChild(BSTNode *newLeftChild){
            leftChild = newLeftChild;
        }

        void setRightChild(BSTNode *newRightChild){
            rightChild = newRightChild;
        }

        BSTNode* getLeftChild() const{
            return leftChild;
        }

        BSTNode* getRightChild() const{
            return rightChild;
        }

        T getData() const{
            return data;
        }

        T& getData(){
            return data;
        }

        BSTNode*& getLeftChild(){
            return leftChild;
        }

        BSTNode*& getRightChild(){
            return rightChild;
        }

    private:
        BSTNode *leftChild;
        BSTNode *rightChild;
        T data;
};