#include <iostream>
using namespace std;
main()
{
int min,sec,frames;
cout <<"Number of Minutes: ";
cin>>min;
cout <<"Frames per Second: ";
cin>>sec;
frames = min * sec * 60;
cout << "Total Number of Frames: "<<frames;
}