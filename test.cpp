#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    
    ifstream myfile("testin.txt");
    string line;
    
    ofstream myfileOut("testout.txt");
    
    if(myfileOut.is_open())
    {
        if (myfile.is_open())
        {
             while ( getline (myfile,line) )
            {
                if(line != "")
                    myfileOut << line << '\n';
                
                cout << "this ----> " << line << endl;
            }

        myfile.close();
        }
        else
            cout << "cannot open file" << endl;
        
        myfileOut.close();
    }
    myfileOut.close();
    
    return 0;
}