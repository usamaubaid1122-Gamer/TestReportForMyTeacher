#include<iostream>
using namespace std;
main ()
{
    int size;
    cout<<"Enter number of elements: ";
    cin>>size;
    int arr[size];
    int sum = 0;

    for (int i = 0; i < size; i++)
    {
        cout<<"Enter "<<i+1<<"element: ";
        cin>>arr[i];
        sum = sum+ arr[i];
    }
    cout<<"Total Sum: "<<sum;
    

}