#include<iostream>
using namespace std;

int main()
{
    int array[5]={1,2,3,4,5};
    
    for(int i = 0; i < 5; i++)
        cout << array[i] << ", ";
        
    cout << "\n\n\n\nRemoving 2....\n\n\n\n\n";
    
    for(int i = 0; i < 5; i++)
        cout << array[i] << ", ";
    return 0;
}