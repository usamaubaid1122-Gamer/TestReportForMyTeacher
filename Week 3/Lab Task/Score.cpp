#include<iostream>
using namespace std;
main ()
{
int wins,losses,draws,total;
cout<<"Enter the wins: ";
cin >> wins;
cout<<"enter the draws: ";
cin>>draws;
cout <<"enter the losses: ";
cin>> losses;
total = (wins * 3) + (draws * 1) + (losses * 0);
cout<<"Pak has obtained " <<total<<  " runs";
}