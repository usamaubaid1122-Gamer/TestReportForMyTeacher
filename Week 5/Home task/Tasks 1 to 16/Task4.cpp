#include<iostream>
using namespace std;
main()
{
    int num,digit,rem,count = 0;
    cout<<"Enter the numbers: ";
    cin>>num;
    cout<<"Enter the digit: ";
    cin>>digit;
    for (int i = num; i > 0 ; i = i/10)
    {
       rem = i % 10;
       if (rem == digit)
       {
        count++;
       }
    }
    cout<<"Frequncy: "<<count;
}