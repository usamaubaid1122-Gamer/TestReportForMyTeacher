#include<iostream>
using namespace std;
main()
{
float min,fps,frames;
cout<<"Enter Minutes: ";
cin>> min;
cout<<"Enter fps: ";
cin>> fps;
frames = min * ( fps * 60);
cout<<"Total Frames: "<<frames;
}