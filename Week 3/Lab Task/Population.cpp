#include<iostream>
using namespace std;
main ()
{
int pop,rate,total,month;
cout<<"Enter the world population: ";
cin>> pop;
cout<<"Enter the monthly birth rate: ";
cin>> rate;
month = 30 * 12;
total = pop + (rate * month);
cout<<"Population in three decades will be: "<<total;
}