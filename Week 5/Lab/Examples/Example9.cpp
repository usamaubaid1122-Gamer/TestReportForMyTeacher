#include<iostream>
using namespace std;
main ()
{
    int n = 1,sum = 0,sums = 0;
    
    for (int i = 1; i <= 5; i = i + 1)
    {
        sum = sum +i;
    }
    cout<<sum<<endl;
    cout<<"____________________________________________"<<endl;
    while (n <= 5)
    {
        sums = sums + n;
        n = n + 1;
    }
    cout<<sums<<endl;
    
}