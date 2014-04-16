#include "SList.h"

SList::~SList(){
    clear();
}

SList::SList(){
    head = NULL;
    count = 0;
}

void SList::insertHead(int newHead){
    SLNode* aNode = new SLNode(newHead); //create a new node
    aNode->setNextNode(head);   //aNode point to NULL
    head = aNode;   //head point to aNode
    
    count++;
}

void SList::removeHead(){
    if(head != NULL){
        SLNode* temp = head;
        head = head->getNextNode();
        delete temp;
        count--;
    }
}

void SList::removeTail(){
    if(head != NULL){
        SLNode* ptr = head;
        SLNode* trailerPtr = NULL;
        
        while(ptr->getNextNode() != NULL){
            trailerPtr = ptr;
            ptr = ptr->getNextNode();
        }
        
        delete ptr;
        if(trailerPtr == NULL){
            head = NULL;
        }
        else{
            trailerPtr->setNextNode(NULL);
        }
        count--;
    }
}

void SList::clear(){
    while(head !=NULL)
        removeHead();

}

unsigned int SList::getSize() const{
    return count;
}

void SList::insertTail(int newContent){
    if(head != NULL){
        SLNode* temp = new SLNode(newContent);
        SLNode* ptr = head;
        while(ptr->getNextNode() != NULL){
            ptr = ptr->getNextNode();
        }
        
        ptr->setNextNode(temp);
        count++;
    }
    else{
        insertHead(newContent);
    }
        
}
string SList::toString () const{
    stringstream ss;
    
    for(SLNode* i = head; i != NULL; i = i->getNextNode()){
        ss << i->getContents();
        if(i->getNextNode() != NULL)
            ss << ",";
    }
    return ss.str();
}
