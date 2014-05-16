/*
 *Project 4, Word.cpp
 *
 *CHEE YEE XIONG
 *Date created: 5-02-14
 *Last date modified: 5-16-14
 */

#include "Word.h"

Word::Word(){
    count = 1;
}

Word::Word(string newWord){
    word = newWord;
    count = 1;
    for(int i = 0; i < word.size(); i++){
        word[i] = tolower(word[i]);
    }
}

Word::~Word()
{}

string Word::getWord() const{
    return word;
}

void Word::setWord(string newWord){
    word = newWord;

    for(int i = 0; i < word.size(); i++){
        word[i] = tolower(word[i]);
    }
}

unsigned int Word::getCount() const{
    return count;
}

void Word::incrementCount(){
    count++;
}

bool operator <(const Word& word1, const Word& word2){
    return (word1.getWord() < word2.getWord());
}

bool operator ==(const Word& word1, const Word& word2){
    return (word1.getWord() == word2.getWord());
}

bool operator >(const Word& word1, const Word& word2){
    return (word1.getWord() > word2.getWord());
}

ostream& operator <<(ostream& outs, const Word& src){
    outs << src.getWord() << " " << src.getCount();
    return outs;
}