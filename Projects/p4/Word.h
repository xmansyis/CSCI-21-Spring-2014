/*
 *Project 4, Word.h
 *
 *CHEE YEE XIONG
 *Date created: 5-02-14
 *Last date modified: 5-16-14
 */

#pragma once

#include <string>
#include <cstdlib>
#include<iostream>
#include<string>
using namespace std;

class Word{
    public:
        /*
         *default constructor. count = 1.
         */
        Word();

        /*
         *Overloaded constructor. word = newWord. count = 1.
         *@param string newWord is the new word.
         */
        Word(string newWord);

        /*
         *destructor. nothing to be done.
         */
        virtual ~Word();

        /*
         *function getWord() const;. return the word.
         *@return string is the word to be return.
         */
        string getWord() const;

        /*
         *function setWord(string newWord). set word = newWord.
         */
        void setWord(string newWord);

        /*
         *function getCount() const;. return the word count.
         *@return unsigned int is the word count to be return.
         */
        unsigned int getCount() const;

        /*
         *function incrementCount().  increment the word count.
         */
        void incrementCount();

        /*
         *friend overloaded operator ==
         *@param const Word& word1 is the first word.
         *@param const Word& word1 is the second word.
         *@return bool.
         */
        friend bool operator ==(const Word& word1, const Word& word2);

        /*
         *friend overloaded operator <
         *@param const Word& word1 is the first word.
         *@param const Word& word1 is the second word.
         *@return bool.
         */
        friend bool operator <(const Word& word1, const Word& word2);

        /*
         *friend overloaded operator >
         *@param const Word& word1 is the first word.
         *@param const Word& word1 is the second word.
         *@return bool.
         */
        friend bool operator >(const Word& word1, const Word& word2);

        /*
         *friend overloaded operator <<
         *@param ostream& object type ostream& outs.
         *@param const Word&, object type Word& src.
         *@return ostream& outs
         */
        friend ostream& operator <<(ostream& outs, const Word& src);

    private:
        //data members.
        string word;
        unsigned int count;
};