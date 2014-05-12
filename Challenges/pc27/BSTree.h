#pragma once

#include "BSTNode.h"
#include <iostream>
#include <cstdlib>
#include <sstream>

using namespace std;

class BSTree{
    public:
        BSTree();
        ~BSTree();
        bool insert (int newContent);
        void clear ();
        unsigned int getSize () const;
        void inOrder ();
        bool remove(int value);

    private:
        BSTNode* root;
        unsigned int size;

        bool insert (int, BSTNode*&);
        void clear (BSTNode*&);
        void inOrder (BSTNode*);
        bool remove(int value, BSTNode*& tmpRoot);
     	void removeMax(int& value, BSTNode*& tmpRoot);
};