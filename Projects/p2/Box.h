/*
 *Project 2, Box.h
 *
 *CHEE YEE XIONG
 *Date created: 3-15-14
 *Last date modified: 4-3-14
 */

#pragma once
#include "Prize.h"
#include <string>
#include <iostream>
using namespace std;

class Box{
    public:
        /*
         *The default constructor for class Box. This will initialize data members: boxNumber = 0,
         *boxColor = "NO COLOR", prizeCapacity = 5, prizeCount = 0.  The default constructor will
         *allocate dynamic memory for Prizes using prizeCapacity.
         */
        Box();

        /*
         *The overloaded constructor for class Box. This will initialize data members: boxNumber = newBoxNumber,
         *boxColor = newBoxColor, prizeCapacity = newPrizeCapacity. The overloaded constructor will
         *allocate dynamic memory for Prizes using prizeCapacity.
         */
        Box(unsigned int newBoxNumber, string newBoxColor, unsigned int newPrizeCapacity);

        /*
         *This is setBoxColor Function.  This function set box color.
         *@param newColor is the string that will be use to set the new color.
         */
        void setBoxColor(string newColor);
         
        /*
         *This is setBoxNumber Function.  This function set a box number.
         *@param newNumber is an unsigned int that will be use to set a box number.
         */
        void setBoxNumber(unsigned int newNumber);
    
        /*
         *This is getBoxNumber function.  This function get the box number and return it.
         *@return unsigned int is the return box number.
         */
        unsigned int getBoxNumber() const;
        
        /*
         *This is getBoxColor function.  This function get the box color and return it.
         *@return string is the return box color.
         */
        string getBoxColor() const;
        
        /*
         *This is getPrizeCapacity function.  This function get the prize capacity and return it.
         *@return unsigned int is the return prize capacity.
         */
        unsigned int getPrizeCapacity() const;
        
        /*
         *This is getPrizeCount function.  This function get the prize count and return it.
         *@return unsigned int is the return prize count.
         */
        unsigned int getPrizeCount() const;
         
        /*
         *This is addPrize function.  This function get a prize and return it.
         *@param prize is the prize that will get added.
         *@return bool if the prize can be added or not.
         */
        bool addPrize(Prize prize);
        
        /*
         *This is getPrize function.  This function get a prize and return it.
         *@param index is unsigned int that is the location of the prize.
         *@return Prize is the prize that will get return.
         */
        Prize& getPrize(unsigned int index);
        
        /*
         *This is removePrize function.  This function will remove a prize and sort the array contiguous.
         *@param index is unsigned int that is the location of the prize to be remove.
         *@return Prize is the remove prize and will get return.
         */
        Prize removePrize(unsigned int index);

    private:
        //data members.
        unsigned int boxNumber;
        string boxColor;
        Prize scratch;
        Prize *prizes;
        unsigned int prizeCapacity;
        unsigned int prizeCount;
};