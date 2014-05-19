#pragma once

#include<iostream>
#include<string>
#include<sstream>

using namespace std;

class Item{
    public:
        Item(string newName = "item", unsigned int newValue = 0);
        virtual ~Item();
        void setName(string newName);
        void setValue(int newValue);
        string getName();
        unsigned int getValue();
        string toString();

    private:
    string name;
    unsigned int value;
};