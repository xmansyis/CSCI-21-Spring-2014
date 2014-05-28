#include<iostream>
using namespace std;

template<class T>
class Box{
    
    public:
        Box(T newContent)
            :contents(newContent){}
        
        void setContents(T newContent){
            contents = newContent;            
        }
    
        T getContents() const{
            return contents;
        }

        friend ostream& operator << (ostream& outs, Box<T> e){
            outs << e.contents;
            return outs;
        }
  
  private:
    T contents;
};