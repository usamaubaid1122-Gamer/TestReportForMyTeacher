#include<iostream>
using namespace std;
main ()
{
    float bill;
    cout<<"Enter the bill: ";
    cin>>bill;
    float discout_5 = bill * 0.05;
    float discout_10 = bill * 0.10;
    if (bill >= 5000)
    {
        bill = bill - discout_10;
        cout<<bill<<" dicounted price";
    }
    else
    {
        bill = bill - discout_5;
        cout<<bill<<" discounted price";
    }
    
}