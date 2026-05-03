#include<iostream>
#include<cmath>
using namespace std;
main()
{
    float distance, heigt,angle,rad;
    cout<<"Enter the Distance From the base of the tree (in feet): ";
    cin>>distance;
    cout<<"Enter the angle of elevation (in degree): ";
    cin>>angle;
    rad = angle / 57.2958 ;
    heigt = distance * tan(rad);
    cout<<"The height of the tree is: "<<heigt;
}