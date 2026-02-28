#include<iostream>
using namespace std;
main()
{
string name;
float adult, child, adultsold,childsold,charity,charitytotal,totalsold,total;
cout<<"The name of the movie: ";
cin>>name;
cout<<"The price of an adult ticket: $";
cin>>adult;
cout<<"The price of a child ticket: $";
cin>>child;
cout<<"The number of adult tickets sold: ";
cin>>adultsold;
cout<<"The number of children's tickets sold: ";
cin>>childsold;
cout<<"Enter the percentage of amount to be donated to charity: ";
cin>>charity;
cout<<"_________________________________________________\n";
totalsold = (adult*adultsold) + (child*childsold);
charitytotal = totalsold*(charity/100);
total = totalsold - charitytotal;
cout<<"Movie: "<<name<<"\n";
cout<<"Total amount generated from ticket sales: $"<<totalsold<<"\n";
cout<<"Donation to charity("<<charity<<"): $"<<charitytotal<<"\n";
cout<<"Remaining amount after donation: $"<<total;
}