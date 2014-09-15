//
// Grader comments 2014.05.23
// -30 points total
//
/*
 *Project 4, BSTree.h
 *
 *CHEE YEE XIONG
 *Date created: 4-29-14
 *Last date modified: 5-16-14
 */

#pragma once

#include "BSTNode.h"
#include<iostream>

using namespace std;

template <typename T>
class BSTree{
    public:
        /*
         *default constructor, root = NULL, size = 0.
         */
        BSTree(){
            root = NULL;
            size = 0;
        }

        /*
         *destructor, call clear function.
         */
         ~BSTree(){
            clear();
        }
 
        /*
         *function unsigned int getSize() const, return the size.
         *@return unsigned int is the size to be return.
         */
        unsigned int getSize() const{
            return size;
        }

        /*
         *function void clear(), call the private clear function.
         */
        void clear(){
            clear(root);
        }

        /*
         *function insert(T newContents), insert new data and return a bool
         *by calling private insert function.
         *@param template T newContents, is the new data to be insert.
         *@return bool.
         */
        bool insert(T newContents){
            return insert(newContents, root);
        }

        /*
         *function remove(T targetData), search for data to be remove and return a bool 
         *by calling private remove function.
         *@param template T targetData, is the data to be remove.
         *@return bool.
         */
        bool remove(T targetData){
            return remove(targetData, root);
        }

        /*
         *function get(T targetData), get the targetData by calling the private get function.
         *@param template T targetData is the data to get.
         *@return template T* data.
         */
        T* get(T targetData){
            return get(targetData, root);
        }

        /*
         *function find(T targetData), find the targetData and return a bool by calling private find function.
         *@param template T targetData is the data to find.
         *@return bool.
         */
        bool find(T targetData){
            return find(targetData, root);
        }
 
        /*
         *function inOrder().  Print the tree in order by calling private inOrder function.
         */
        void inOrder(){
            inOrder(root);
        }

        /*
         *function reverseOrder().  Print the tree in reverse order by calling private reserveOrder function.
         */
        void reverseOrder(){
            reverseOrder(root);
        }

    private:
        //data members
        BSTNode<T> *root;
        int size;

        /*
         *private function clear(BSTNode<T>*& tempRoot).  Helper for public clear function.
         *@param BSTNode<T>*& tempRoot the root of the tree.
         */
        void clear(BSTNode<T>*& tempRoot){
            if(tempRoot != NULL){
                clear(tempRoot->getLeftChild());
                clear(tempRoot->getRightChild());
                delete tempRoot;
                tempRoot = NULL;
                size--;
            }
        }

        /*
         *private function insert(T newContents, BSTNode<T>*& tempRoot. Helper for the public insert function.
         *@param T newContents, the data to be insert.
         *@param BSTNode<T>*& tempRoot the root of the tree.
         *@return bool, true if inserted or else return false.
         */
        bool insert(T newContents, BSTNode<T>*& tempRoot){
            if(tempRoot == NULL){
                tempRoot = new BSTNode<T>(newContents);
                size++;
                return true;
            }
            else if(newContents < tempRoot->getData()){
                return insert(newContents, tempRoot->getLeftChild());
            }
            else if(newContents > tempRoot->getData()){
                return insert(newContents, tempRoot->getRightChild());
            }
            else{
                return false;
            }
        }

        /*
         *private function find(T targetData, BSTNode<T>*& tempRoot). Helper for the public find function.
         *@param T targetData the data to find.
         *@param BSTNode<T>*& tempRoot the root of the tree.
         *@return bool, true if found or else return false.
         */
        bool find(T targetData, BSTNode<T>*& tempRoot){
            if(tempRoot == NULL){
                return false;
            }
            else if(targetData < tempRoot->getData()){
                return find(targetData, tempRoot->getLeftChild());
            }
            else if(targetData > tempRoot->getData()){
                return find(targetData, tempRoot->getRightChild());
            }
            else{
                if(tempRoot->getData() == targetData)
                    return true;
                else
                    return false;
            }
        }

        /*
         *private function remove(T targetData, BSTNode<T>*& tempRoot). Helper for the public remove function.
         *@param T targetData the data to be remove.
         *@param BSTNode<T>*& tempRoot the root of the tree.
         *@return bool, true if targetData remove, or else return false.
         */
        bool remove(T targetData, BSTNode<T>*& tempRoot){
            if(tempRoot == NULL){
                return false;
            }
            else if(targetData < tempRoot->getData()){
                return remove(targetData, tempRoot->getLeftChild());
            }
            else if(targetData > tempRoot->getData()){
                return remove(targetData, tempRoot->getRightChild());
            }
            else{
                if(tempRoot->getLeftChild() == NULL){
                    BSTNode<T>* rootToRemoved = tempRoot;
                    tempRoot = tempRoot->getRightChild();
                    delete rootToRemoved;
                }
                else{
                    removeMax(tempRoot->getData(), tempRoot->getLeftChild());
                }

                size--;
                return true;
            }
        }

				
		//
		// Grader comments 2014.05.23
		// right/left child handling is backward. Breaks the tree
		// when removing nodes. Also, don't decrement size here,
		// because you're doing so in your main remove() function.
		// -30 points
		//

        /*
         *private function removeMax(T removed, BSTNode<T>*& tempRoot), use with recursive remove.
         *@param T removed the data to be remove.
         *@param BSTNode<T>*& tempRoot the root of the tree.
         *@return bool, true if remove, or else return false.
         */
        void removeMax(T& removed, BSTNode<T>*& tempRoot){
            if(tempRoot->getRightChild() == NULL){
                BSTNode<T>* rootToRemoved = tempRoot;
                removed = tempRoot->getData();
                tempRoot = tempRoot->getLeftChild();
                delete rootToRemoved;
                //size--;		// Rob: make the unit test work
            }
            else{
                removeMax(removed, tempRoot->getRightChild());
            }
        }

        /*
         *private function get(T targetData, BSTNode<T>*& tempRoot), return a pointer to targetData.
         *@param T targetData the data to get.
         *@param BSTNode<T>*& tempRoot the root of the tree.
         *@return T* return a pointer to targetData.
         */
        T* get(T targetData, BSTNode<T>*& tempRoot){
            if(tempRoot == NULL){
                //return false;	// Rob fixed
				return NULL;
            }
            else{
                if(targetData < tempRoot->getData()){
                    return get(targetData, tempRoot->getLeftChild());
                }
                else if(targetData > tempRoot->getData()){
                    return get(targetData, tempRoot->getRightChild());
                }
                else{
                    return &tempRoot->getData();
                }
            }
        }

        /*
         *private function inOrder(BSTNode<T>*& tempRoot), display contents of nodes in tree ascending order.
         *@param BSTNode<T>*& tempRoot the root of the tree.
         */
        void inOrder(BSTNode<T>*& tempRoot){
            if(tempRoot != NULL){
                inOrder(tempRoot->getLeftChild());
                cout << tempRoot->getData() << endl;
                inOrder(tempRoot->getRightChild());
            }
        }

        /*
         *private function reverseOrder(BSTNode<T>*& tempRoot), display contents of nodes in tree descending order.
         *@param BSTNode<T>*& tempRoot the root of the tree.
         */
        void reverseOrder(BSTNode<T>*& tempRoot){
            if(tempRoot != NULL){
                reverseOrder(tempRoot->getRightChild());
                cout << tempRoot->getData() << endl;
                reverseOrder(tempRoot->getLeftChild());
            }
        }
};