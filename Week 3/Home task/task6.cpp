#include<iostream>
using namespace std;
main()
{
float price,size,area,poundprice,areaprice;
cout<<"Enter the size of the fertilizer bag in pounds: ";
cin>>size;
cout<<"Enter the cost of the bag: $";
cin>>price;
cout<<"Enter the area in squre feet that can be covered by the bag: ";
cin>>area;
poundprice = price/size;
areaprice = price/area;
cout<<"Cost of fertillizer per pound: $"<<poundprice<<endl;
cout<<"Cost of fertilizing per squre foot: $"<<areaprice;
}