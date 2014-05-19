#include "Item.h"

Item::Item(string newName, unsigned int newValue){
    name = newName;
    value = newValue;
}

Item::~Item(){
    //nothing
}

void Item::setName(string newName){
    name = newName;
}

void Item::setValue(int newValue){
    value = newValue;
  
}

string Item::getName(){
    return name;
}

unsigned int Item::getValue(){
    return value;
}

string Item::toString(){
    stringstream ss;
    ss << name << ", $" << value;

    return ss.str();
}