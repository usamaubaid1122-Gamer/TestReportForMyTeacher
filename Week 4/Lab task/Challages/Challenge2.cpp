#include<iostream>
using namespace std;
main()
{
    int num_1, num_2;
    cout<<"Enter the number: ";
    cin>> num_1;
    cout<<"Enter the second number: ";
    cin>> num_2;
    if (num_1 < num_2)
    {
        cout<<num_2<<" is greater than "<<num_1;
    }
    else
    {
        cout<<num_1<<" is smaller than "<<num_2;
    }
    
}