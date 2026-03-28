#include<iostream>
using namespace std;
main ()
{
    int size;
    cout<<"Enter the number of element: ";
    cin>>size;
    int arr[size];

    for (int i = 0; i < size; i++)
    {
        cout<<"Enter the numbers: ";
        cin>>arr[i];
    }

    cout<<"Even numbers are: ";
    
    for (int i = 0; i < size; i++)
    {
        if (arr[i] % 2 == 0)
        {
            cout<<arr[i]<<" ";
        }
    }
    return 0 ;
}