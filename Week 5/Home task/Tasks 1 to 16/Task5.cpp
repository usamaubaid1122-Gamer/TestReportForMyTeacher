#include<iostream>
using namespace std;
int main()
{
    int sum = 0,num,digit;
    cout<<"Enter the number: ";
    cin>>num;
    while (num != 0)
    {
        digit = num % 10;
        sum = sum + digit;
        num = num / 10;
    }
    cout<<"Sum of the digit: "<<sum;
    return 0 ;
}