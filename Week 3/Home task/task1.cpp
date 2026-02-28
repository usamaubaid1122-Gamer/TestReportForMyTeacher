#include <iostream>
using namespace std;
main()
{
int n,total;
cout<<"Enter the sides of polygon: ";
cin>>n;
total = (n-2) * 180;
cout<<"The total sum of internal angles of a : " <<n<<"-sided polygon is : "<<total<<" degrees"; 
}