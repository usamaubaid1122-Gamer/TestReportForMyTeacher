#include<iostream>
using namespace std;
main ()
{
string name;

int mat,ics,ecat;

float pmat,pics, pecat,Aggregate;

cout<<"Enter the student name: ";
cin>> name;

cout<<"Matric Marks: ";
cin>> mat;

cout<<"Ics Marks: ";
cin>> ics;

cout<<"Ecat Marks: ";
cin>> ecat;

pmat = mat *10/1100;
pics = ics *40/550;
pecat = ecat*50/400;

Aggregate = pmat + pics + pecat;
cout<<"Aggregate score for:  " <<name<<" "<<Aggregate;

}