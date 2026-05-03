#include<iostream>
#include<cmath>
using namespace std;
main()
{
    int num_1 , num_2;
    cout<<"Enter first number: ";
    cin>>num_1;
    cout<<"Enter second number: ";
    cin>>num_2;
    cout<<"Smaller number is "<<min(num_1,num_2);
    return 0;
}