#pragma once

#include "SLNode.h"

#include<cstdlib>
#include<sstream>
#include<iostream>

using namespace std;

class SList{
    public:
        SList();
        virtual ~SList();
        void insertHead(int newHead);
        void removeHead();
        void clear();
        unsigned int getSize() const;
        string toString() const;
    
    private:
        SLNode *head;
        unsigned int count;
};