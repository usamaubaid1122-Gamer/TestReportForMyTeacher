#include <iostream>
using namespace std;
main ()
{
    cout<<"Multiplication Table of 24: "<<endl;
    for (int i = 1 ; i <= 10 ;i++) 
    {
        int n = 24,total ;
        total = n*i;
        cout<<n<<" x "<<i<<" = "<<total<<endl;
    }
    cout<<endl;
    cout<<"Multiplication Table of 50: "<<endl;
    for ( int i = 1; i <= 10; i++)
    {
        int n=50,total;
        total = n*i;
        cout<<n<<" x "<<i<<" = "<<total<<endl;
    }
    cout<<endl;
    cout<<"Multiplication Table of 29: "<<endl;
    for (int i = 1; i <= 10; i++)
    {
        int n=29,total;
        total = n * i ;
        cout<<n<<" x "<<i<<" = "<<total<<endl;
    }
    
    
}