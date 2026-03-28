#include <iostream>
using namespace std;
main ()
{
    int num[3];
    bool valid = true;
    for (int i = 0; i < 3; i++)
    {
        cout<<"Enter the number: ";
        cin>>num[i];
        if (num[i] < 0 )
        {
            cout<<"Invalid Input. Number of element must be greater than 0"<<endl;
            valid = false;
            break;
        }
    }
    if (valid == true)
    {
        for (int i = 3 - 1; i >= 0  ; i--)
    {
        cout<<num[i]<<" ";
    }
    }
}