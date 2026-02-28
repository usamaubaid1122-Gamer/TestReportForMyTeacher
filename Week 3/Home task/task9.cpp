#include<iostream>
using namespace std;
main()
{
int digits,sum,num1,num2,num3,num4;

cout<< "Enter 4 digit number: ";
cin>>digits;
num1   = digits % 10;
digits = digits / 10;
num2   = digits % 10;
digits = digits / 10;
num3   = digits % 10;
digits = digits / 10;
num4   = digits % 10; 
sum = num1 + num2 + num3 + num4;
cout <<"Sum of integers = " << sum;
}