#include<iostream>
using namespace std;
main()
{
float Fvelocity,Ivelocity,Time,Acceleration;
cout<<"Enter the Initail Velocity(m/s): ";
cin>>Ivelocity;
cout<<"Enter Acceleration (m/s/^2): ";
cin>>Acceleration;
cout<<"Enter Time (s): ";
cin>>Time;
Fvelocity = (Acceleration * Time) + Ivelocity;
cout<<"Final velocity(m/s): "<<Fvelocity;

}