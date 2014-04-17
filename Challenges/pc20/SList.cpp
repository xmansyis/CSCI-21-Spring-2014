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

void SList::insert(int newContent){
    if(head == NULL){
         insertHead(newContent);
    }
     else if(head->getNextNode() == NULL){
        if(newContent < head->getContents()){
            insertHead(newContent);
        }
        else{
            insertTail(newContent);
        }
    }
    else{
        SLNode* Trailer = NULL;
        SLNode* spot = head;
    
        while(spot->getNextNode() != NULL && newContent > spot->getContents()){
            Trailer = spot;
            spot = spot->getNextNode();
        }
       
        if(spot->getNextNode() == NULL && newContent > spot->getContents()){

            insertTail(newContent);
        }
        else{
            
            SLNode* node = new SLNode(newContent);
            node->setNextNode(spot);
 
            if(Trailer == NULL ){
                //???
            }
            else{
                Trailer->setNextNode(node);
            }
            
            count++;
        }
    }
}

bool SList::removeFirst(int removeContent){
    if(head == NULL){
        return false;
    }
    else{
        SLNode* trailer = NULL;
        SLNode* spot = head;
        
        while(spot!= NULL && spot->getContents() != removeContent){
            trailer = spot;
            spot = spot->getNextNode();
        }
        if(spot == NULL){
            return false;
        }
        else if(spot == head){
            removeHead();
            return true;
        }
        else{
            trailer->setNextNode(spot->getNextNode());
            delete spot;
            count--;
            return true;
        }
    }
    
}
