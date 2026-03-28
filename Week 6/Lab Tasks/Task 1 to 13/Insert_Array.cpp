#include <iostream>
using namespace std;
main()
{
    int first [2];
    cout<<"how many number you want to enter in the array: ";
    int secondarraysize ;
    cin>> secondarraysize;
    int second[secondarraysize];

    int thidarraysize = secondarraysize + 2;
    int third[thidarraysize];

    for (int i = 0; i < 2; i++)
    {
        cout<<"Enter the "<<i + 1<<" numbers in first array ";
        cin>>first[i];
    }
    for (int  i = 0; i < secondarraysize; i++)
    {
        cout<<"Enter the "<<i+1<<" numbers in second array ";
        cin>>second[i];
    }
    third[0] = first[0];
    
    for (int i = 0; i < secondarraysize; i++)
    {
        third[i + 1] = second[i];
    }
    third[thidarraysize -1] = first[1];

    cout<<"Final array: ";
    for (int i = 0; i < thidarraysize; i++)
    {
        cout<<third[i]<<" ";
    }
    return 0;
}