#pragma once

#include <string>
#include <cstdlib>
#include<iostream>
#include<string>
using namespace std;

class Word{
    public:
        Word();
        Word(string newWord);
        virtual ~Word();
        string getWord() const;
        void setWord(string newWord);
        unsigned int getCount() const;
        void incrementCount();

        friend bool operator ==(const Word& word1, const Word& word2);
        friend bool operator <(const Word& word1, const Word& word2);
        friend bool operator >(const Word& word1, const Word& word2);
        friend ostream& operator <<(ostream& outs, const Word& src);
    
    private:
        string word;
        unsigned int count;
};