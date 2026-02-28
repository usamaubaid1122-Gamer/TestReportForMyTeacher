#include<iostream>
using namespace std;
main()
{
int age;
int moves;
int average;
int houses;
cout << "enter the persons age :";
cin >> age;
cout << " enter the number of time they've moved:";
cin >> moves;
houses  = moves +1;
average = age / houses;
cout << "average number of year lived in the house :"<<average;
}