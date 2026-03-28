#include<iostream>
using namespace std;
main ()
{
    int size = 5;
    int num[size];
    for (int i = 0; i < size; i++)
    {
        cout<<"Enter the "<< i + 1 <<" number: ";
        cin>>num[i];
    }
    int largest = num[0];
    for (int i = 1; i < size; i++)
    {
        if (num[i] > largest)
        {
            largest = num[i];
        }
        
    }
    cout <<"Largest number is: "<<largest<<endl;
}