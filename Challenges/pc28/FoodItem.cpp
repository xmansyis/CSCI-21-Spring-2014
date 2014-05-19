#include "FoodItem.h"

FoodItem::FoodItem(string newName, unsigned newValue, unsigned newCalories, string newUnitOfMeasure, float newUnits){
   calories = newCalories;
   unitOfMeasure = newUnitOfMeasure;
   units = newUnits;
   setName(newName);
   setValue(newValue);
}

FoodItem::~FoodItem(){}

void FoodItem::setCalories(unsigned int newCalories){
    calories = newCalories;
}

void FoodItem::setUnitOfMeasure(string newUnitOfMeasure){
    unitOfMeasure = newUnitOfMeasure;
}

void FoodItem::setUnits(float newUnit){
    units = newUnit;
}

unsigned int FoodItem::getCalories(){
    return calories;
}

string FoodItem::getUnitOfMeasure(){
    return unitOfMeasure;
}

float FoodItem::getUnits(){
    return units;
}


string FoodItem::toString(){
    stringstream ss;
    
    ss.setf(ios::fixed);
    ss.setf(ios::showpoint);
    ss << getName() << ", $" << getValue() << ", " << setprecision(2) << units << " " << unitOfMeasure << ", " << calories << " calories";
   
    return ss.str();
    
}