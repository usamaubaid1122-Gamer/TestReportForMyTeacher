#include<iostream>
using namespace std;
main ()
{
    int value;
    cout<<"Enter the positive value:";
    cin>>value;
    while (value <=0)
    {
        cout<<"Error "<<value<<" is not a positive number."<<endl;
        cout<<"Please enter a positive number.";
        cin>>value;
    }
    cout<<"Program end";
}