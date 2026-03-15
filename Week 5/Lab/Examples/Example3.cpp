#include <iostream>
using namespace std;
main()
{
    int n1 = 0 , n2 = 1, next;
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    cout<<n1<<", ";
    cout<<n2;

    for (int i = 1; i < n; i++)
    {
        next = n1 + n2 ;
        cout<<", "<<next;
        n1 = n2 ;
        n2 = next;
    }
    
}