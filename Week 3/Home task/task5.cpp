#include<iostream>
using namespace std;
main()
{
string name;
float weight,days,total;
cout<<"Enter the name of the person: ";
cin>>name;
cout<< "Enter the target weight loss in kg: ";
cin>>days; 
weight = days*15;
cout<<""<<name<< " will need "<<weight<<" days to lose "<<days<<" kg of weight by following the docter suggestions ";
}