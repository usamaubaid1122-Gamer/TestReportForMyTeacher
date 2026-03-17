#include<iostream>
using namespace std;
main ()
{
    int i,j,rows;
    cout<<"Input the number of rows: ";
    cin>>rows;
    for ( i = 1; i <=rows; i++)
    {
        for ( j = 1; j <= i; j++)
        {
            cout<<"*";
        }
        cout<<"\n";
    }
    for ( i = rows; i >= 1; i--)
    {
        for ( j = 1; j <= i; j++)
        {
            cout<<"*";
        }
        cout<<"\n";
    }
    
}