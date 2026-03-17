#include<iostream>
using namespace std;
main()
{
    int n = 1,n1 = 0,n2 = 1,next;
    cout<<"Enter the number: ";
    cin>>n;
    cout<<n1<<" , "<<n2;
    for (int i = 2; i < n; i++)
    {
        next = n1 + n2;
        cout<<" , "<<next;
        n1 = n2;
        n2 = next; 
    }
    
}