#include<iostream>
using namespace std;
main()
{
float MB,KB,Bytes,Bits;
cout<<"Enter the size in MBs";
cin>> MB;

KB = MB * 1024;
Bytes = KB * 1024;
Bits = Bytes * 8;
cout<<"Enter the size in bits: "<<Bits;
}
