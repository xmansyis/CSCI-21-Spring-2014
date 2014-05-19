#include "MagicItem.h"

MagicItem::MagicItem(string newName, unsigned int newValue, string newDescription, unsigned int newManaRequired){
    description = newDescription;
    manaRequired = newManaRequired;
    setValue(newValue);
    setName(newName);
}

MagicItem::~MagicItem()
{}

void MagicItem::setDescription(string newDescription){
    description = newDescription;
}

void MagicItem::setManaRequired(unsigned int newManaRequired){
    manaRequired = newManaRequired;
}

string MagicItem::getDescription(){
    return description;
}

unsigned int MagicItem::getManaRequired(){
    return manaRequired;
}

string MagicItem::toString(){
    stringstream ss;

    ss << getName() << ", $" << getValue() << ", " << description << ", requires " << manaRequired << " mana";

    return ss.str();
}