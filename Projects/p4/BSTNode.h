/*
 *Project 4, BSTNode.h
 *
 *CHEE YEE XIONG
 *Date created: 4-29-14
 *Last date modified: 5-16-14
 */

#pragma once

#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;

template <typename T>
class BSTNode{
    public:
        /*
         *overloaded constructor, leftChild = NULL, rightChild = NULL, data = newData.
         *@param template T is the new data.
         */
        BSTNode(T newData){
            leftChild = NULL;
            rightChild = NULL;
            data = newData;
        }

        /*
         *destructor.
         */
        virtual ~BSTNode()
        {/*nothing to be done*/}

        /*
         *function setData(T newData), set data = newData.
         *@param template T is the new data.
         */
        void setData(T newData){
            data = newData;
        }

        /*
         *function setLeftChild(BSTNode * newLeftChild), set leftChild = newLeftChild.
         *@param BSTNode* is the new leftChild.
         */
        void setLeftChild(BSTNode *newLeftChild){
            leftChild = newLeftChild;
        }

        /*
         *function setRightChild(BSTNode * newRightChild), set rightChild = newRightChild.
         *@param BSTNode* is the new rightChild.
         */
        void setRightChild(BSTNode *newRightChild){
            rightChild = newRightChild;
        }

        /*
         *function getLeftChild() const, return leftChild.
         *@return BSTNode* leftChild.
         */
        BSTNode* getLeftChild() const{
            return leftChild;
        }

        /*
         *function getRightChild() const, return rightChild.
         *@return BSTNode* rightChild.
         */
        BSTNode* getRightChild() const{
            return rightChild;
        }

        /*
         *function getData() const, return the data.
         *@return template T is the data to be return.
         */
        T getData() const{
            return data;
        }

         /*
         *function getData(), return the data.
         *@return &template T is the data to be return.
         */
        T& getData(){
            return data;
        }

        /*
         *function getLeftChild(), return leftChild.
         *@return BSTNode*& leftChild.
         */
        BSTNode*& getLeftChild(){
            return leftChild;
        }

        /*
         *function getRightChild(), return rightChild.
         *@return BSTNode*& rightChild.
         */
        BSTNode*& getRightChild(){
            return rightChild;
        }

    private:
        //data members.
        BSTNode *leftChild;
        BSTNode *rightChild;
        T data;
};