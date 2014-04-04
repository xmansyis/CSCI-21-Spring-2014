/*
 *Project 2, Box.cpp
 *
 *CHEE YEE XIONG
 *Date created: 3-15-14
 *Last date modified: 4-4-14
 */

#include "Box.h"

Box::Box(){
    boxNumber = 0;
    boxColor = "NO COLOR";
    prizeCapacity = 5;
    prizeCount = 0;
    prizes = new Prize[prizeCapacity];
}

Box::Box(unsigned int newBoxNumber, string newBoxColor, unsigned int newCapacity){
    boxNumber = newBoxNumber;
    boxColor = newBoxColor;
    prizeCapacity = newCapacity;
    prizeCount = 0;
    prizes = new Prize[prizeCapacity];
}

void Box::setBoxColor(string newColor){
    boxColor = newColor;
}

void Box::setBoxNumber(unsigned int newBoxNumber){
    boxNumber = newBoxNumber;
}

string Box::getBoxColor() const{
    return boxColor;
}

unsigned int Box::getBoxNumber() const{
    return boxNumber;
}

unsigned int Box::getPrizeCapacity() const{
    return prizeCapacity;
}

unsigned int Box::getPrizeCount() const{ 
    return prizeCount;
}

bool Box::addPrize(Prize prize){
    if(prizeCount == prizeCapacity){
        return false;
    }
    
    prizes[prizeCount].setPrizeName(prize.getPrizeName());
    prizes[prizeCount].setPrizeValue(prize.getPrizeValue());

    prizeCount++;
    return true;
}

Prize& Box::getPrize(unsigned int index){
    if(prizeCount == index){
        prizes[index].setPrizeName("NO NAME");
        prizes[index].setPrizeValue(0);
        return prizes[index];
     }
     
    if(prizeCount == 0){
        return scratch;
    }
    else{
        return prizes[index];
    }
}

Prize Box::removePrize(unsigned int index){
    if(prizeCount >= 1 ){
        if(index < prizeCapacity ){
            if(prizeCount == index){
                prizes[index].setPrizeName("NO NAME");
                prizes[index].setPrizeValue(0);
                return prizes[index];
            }

            string tmpPrizeName = prizes[index].getPrizeName();
            unsigned int tmpPrizeValue = prizes[index].getPrizeValue();
            for(unsigned int i = index; i < (prizeCount-1); ++i){
                swap(prizes[i], prizes[i+1]);
            }

            prizeCount--;
            prizes[prizeCount].setPrizeName(tmpPrizeName);
            prizes[prizeCount].setPrizeValue(tmpPrizeValue);
            return prizes[prizeCount];
        }
        else{
            return scratch;
        }
    }

    return scratch;
}