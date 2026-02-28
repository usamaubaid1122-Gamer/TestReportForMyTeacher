#include <iostream>
using namespace std;
main()
{
int area,width,height,walls;
cout<<"Number of squre meters you can paint: ";
cin>>area;
cout<<"Width of the single wall: ";
cin>>width;
cout<<"Height of the single wall: ";
cin>>height;
walls = area/ (width*height);
cout<<"Number of walls you can paint:  "<<walls;

}