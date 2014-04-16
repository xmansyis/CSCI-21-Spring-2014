#pragma once

class SLNode{
    private:
        SLNode* next;
        int content;
        
    public:
        /*
         *Default constructor. Initializes content = 0, and next = NULL.
         */
        SLNode();
        
        /*
         *Overloaded constructor. 
         *@param int contents will be use to set content.
         */
        SLNode(int contents);
        
        /*
         *Destructor. set next to NULL
         */
        ~SLNode();
        
        /*
         *Function setContents.  Take in an int to set new content.
         *@param int newContent use to set a new content value.
         */
        void setContents (int newContent);
        
        /*
         *Function getContents.  This function return the content.
         */
        int getContents () const;
        
        /*
         *Function setNextNode(SLNode).  This function set a newNode;
         *@param SLNode* next is the variable for newNode;
         */
        void setNextNode(SLNode* next);
        
        /*
         *Function getNextNode.  Return the next Node.
         */
        SLNode* getNextNode () const;
};