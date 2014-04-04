/*
 *Project 2, Prize.cpp
 *
 *CHEE YEE XIONG
 *Date created: 3-15-14
 *Last date modified: 4-3-14
 */

#include "Prize.h"

Prize::Prize(){
    prizeName = "NO NAME";
    prizeValue = 0;
}

Prize::Prize(string newPrizeName, unsigned int newPrizeValue){
    prizeName = newPrizeName;
    prizeValue = newPrizeValue;
}

void Prize::setPrizeName(string newPrizeName){
    prizeName = newPrizeName;
}

string Prize::getPrizeName() const{
    return prizeName;
}

void Prize::setPrizeValue(unsigned int newPrizeValue){
    prizeValue = newPrizeValue;
}

unsigned int Prize::getPrizeValue() const{
    return prizeValue;
}

Prize::~Prize()
{}

bool operator== (Prize prize_a, Prize prize_b){
    if(prize_a.prizeName == prize_b.prizeName){
        if(prize_a.prizeValue == prize_b.prizeValue){
            return true;
        }
        return false;
    }
    return false;
}