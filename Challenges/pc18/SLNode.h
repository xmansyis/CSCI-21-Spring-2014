#pragma once

class SLNode{
    private:
        SLNode* next;
        int content;
        
    public:
        SLNode();
        SLNode(int contents);
        ~SLNode();
        void setContents (int newContent);
        int getContents () const;
        void setNextNode(SLNode* next);
        SLNode* getNextNode () const;
};