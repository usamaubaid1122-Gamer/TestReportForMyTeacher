#include<iostream>
using namespace std;
main()
{
    int size;
    cout<<"Enter the size of array: ";
    cin>>size;
    int array[size];

    for (int i = 0; i < size; i++)
    {
        cout<<"Enter "<<i+1<<" integer: ";
        cin>>array[i];
    }
    bool isSpecial = true;

    for (int i = 0; i < size; i++)
    {
        if (i % 2 == 0)
        {
            if (array[i] % 2 != 0)
            {
                isSpecial = false;
                break;
            }
            
        }
        else
        {
            if (array[i] % 2 == 0)
            {
                isSpecial = false;
                break;
            }
            
        }
    }
    if (isSpecial)
    {
        cout<<"The Array is Special.";
    }
    else
    {
        cout<<"The Array is Not Special.";
    }
    
}