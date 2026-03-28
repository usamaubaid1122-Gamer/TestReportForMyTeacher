#include<iostream>
using namespace std;
main ()
{
    int size;
    cout<<"Enter the number of the chords: ";
    cin>>size;
    string array[size];

    for (int i = 0; i < size; i++)
    {
        cout<<"Enter "<<i+1<<" chord: ";
        cin>>array[i];
    }
    cout<<"Jazzify chords: ";
    
    for (int i = 0; i < size; i++)
    {
        int len = array[i].length();

        if (array[i][len -1] == '7')
        {
            cout<< array[i] << " ";
        }
        else
        {
            cout<<array[i]<<"7 ";
        }
    }
    return 0 ;
}