#include<iostream>
using namespace std;
int main()
{
    int number,even;
    cout<<"Enter the number: ";
    cin>> number;
    even = number%2;
    if (even == 0)
    {
        cout<<"Even";
    }
    else
    {
        cout<<"odd";
    }
    
}
