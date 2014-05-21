#include "TreasureChest.h"

void TreasureChest::addItem (const Item& newItem){
    chest.push_back(newItem);
}

void TreasureChest::insertItem (const Item& newItem, unsigned int position){
    if(position >= chest.size()){
        chest.push_back(newItem);
    }
    else{
        chest.insert((chest.begin() + position), newItem);
    }
}

const Item* TreasureChest::getItem (unsigned int position){
    if(position >= chest.size()){
        return 0;
    }
    else{
        return &(chest.at(position));
    }
}

Item TreasureChest::removeItem (unsigned int position) throw (string){
    if(position >= chest.size()){
        throw string("ERROR: attempting remove at invalid position");
    }
    else{
        Item copyItem = chest.at(position);
        chest.erase(chest.begin() + position);

        return copyItem;
    }
}

bool TreasureChest::empty () const{
    return chest.empty();
}

void TreasureChest::clear (){
    chest.clear();
}

unsigned int TreasureChest::getSize () const{
    return chest.size();
}

void TreasureChest::sortByName (){
    sort(chest.begin(), chest.end(), compareItemsByName);
}

void TreasureChest::sortByValue (){
    sort(chest.begin(), chest.end(), compareItemsByValue);
}

void TreasureChest::sortByQuantity (){
    sort(chest.begin(), chest.end(), compareItemsByQuantity);
}

ostream& operator<< (ostream& outs, const TreasureChest& src){
    bool comma = false;
    
    for(vector<Item>::const_iterator i = src.chest.begin(); i != src.chest.end(); i++){
        if(comma == true){
            outs << ",";
        }
        outs << *i;
        comma = true;
    }

    return outs;
}

bool compareItemsByName (const Item& lsrc, const Item& rsrc){
    return lsrc.name < rsrc.name;
}

bool compareItemsByValue (const Item& lsrc, const Item& rsrc){
    return lsrc.value < rsrc.value;
}

bool compareItemsByQuantity (const Item& lsrc, const Item& rsrc){
    return lsrc.quantity < rsrc.quantity;
}