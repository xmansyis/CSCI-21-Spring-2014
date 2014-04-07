/*
 *Project 2, Prize.h 
 *
 *CHEE YEE XIONG
 *Date created: 3-15-14
 *Last date modified: 4-4-14
 */

#pragma once
#include <string>
using namespace std;

class Prize{
    public:
        /*
         *The default constructor for class Prize.  Initialize data members: prizeName ="NO NAME", prizeValue = 0.
         */
        Prize();
        
        /*
         *Overloaded constructor for class Prize.  Overwrite the default constructor data members prizeName and prizeValue.
         @param newPrizeName is a string that will initialize prizeName.
         @param newPrizeValue is an unsigned int that will initialize prizeValue.
         */
        Prize(string newPrizeName, unsigned int newPrizeValue);
        
        /*
         *Prize Destructor: empty
         */
        ~Prize();
        
        /*
         *This is setPrizeName function.  This function set a new prize name.
         *@param newPrizeName is the string that will be use to set the new prize name.
         */
        void setPrizeName(string newPrizeName);
        
        /*
         *This is setPrizeValue function.  This function set a new prize value.
         *@param newPrizeValue is the unsigned int that will be use to set the new prize value.
         */
        void setPrizeValue(unsigned int newPrizeValue);
        
        /*
         *This is getPrizeName function.  This function will return a prize name.
         *@return string which is the name of a prize.
         */
        string getPrizeName() const;
        
        /*
         *This is getPrizeValue function.  This function will return a prize value.
         *@return unsigned int which is the value of a prize.
         */
        unsigned int getPrizeValue() const;
        
        /*
         *overloaded operator== function compare two prizes.
         *@param prize_a will be the first prize.
         *@param prize_b will be the second prize.
         *@return bool after comparing two prizes.
         */
        friend bool operator== (Prize prize_a, Prize prize_b);
        
    private:
        //data members
       string prizeName;
       unsigned int prizeValue;
};