#include <iostream>
using namespace std;
main()
{
int area,width,height,walls;
cout<<"Enter paint area: ";
cin>>area;
cout<<"Enter height: ";
cin>>height;
cout<<"Enter width: ";
cin>>width;
walls = area/ (width*height);
cout<<"Walls painted = "<<walls;

}