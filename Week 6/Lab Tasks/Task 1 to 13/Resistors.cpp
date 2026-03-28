#include<iostream>
using namespace std;
main()
{
    int n;
    cout<<"Enter number of resistors: ";
    cin>>n;
    float resistance[n];
    float total = 0;
    for (int  i = 0; i < n; i++)
    {
        cout<<"Enter resistance R "<<i+1<<" : ";
        cin>>resistance[i];
        total = total + resistance[i];
    }
    cout<<"Total resistance (RT) = "<<total<<" ohms."<<endl;
    return 0;
}