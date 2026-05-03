#include<iostream>
#include<cmath>
using namespace std;
main()
{
    float num_1 , num_2;
    cout<<"Enter first number: ";
    cin>>num_1;
    cout<<"Enter second number: ";
    cin>>num_2;
    cout<<num_1<<" raised to the power "<<num_2<<" is "<<pow(num_1,num_2);
    return 0;
}