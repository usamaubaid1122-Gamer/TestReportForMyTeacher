#include<iostream>
using namespace std;
main ()
{
    float value_1,value_2,total,ulternate;
    char operation;
    cout<<"Enter the number: ";
    cin>>value_1;
    cout<<"Enter the operation: ";
    cin>>operation;
    cout<<"Enter the second number: ";
    cin>>value_2;
    if (operation == '+')
    {
        total = value_1 + value_2;
        ulternate = value_1 - value_2;
        cout<<value_1<<"-"<<value_2<<"="<<ulternate;

    }
    if (operation == '-')
    {
        total = value_1 - value_2;
        ulternate = value_1 + value_2;
        cout<<value_1<<"+"<<value_2<<"="<<ulternate;
    }
    if (operation == '*')
    {
        total = value_1 * value_2;
        ulternate = value_1 / value_2;
        cout<<value_1<<"/"<<value_2<<"="<<ulternate;
    }
     if (operation == '/')
    {
        total = value_1 / value_2;
        ulternate = value_1 * value_2;
        cout<<value_1<<"*"<<value_2<<"="<<ulternate;
    }
}  
