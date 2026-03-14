#include<iostream>
using namespace std;
main ()
{
    int ticketprice,ireland;
    string name; 
    cout<<"Enter the country name: ";
    cin>>name; 
    cout<<"Enter the price of ticket: ";
    cin>>ticketprice;
    if (name == "ireland" )
    {
        ticketprice = ticketprice - (ticketprice * 10/100);
        cout<<"Discounted Price: "<<ticketprice;
    }
    else
    {
        ticketprice = ticketprice - (ticketprice * 5/100);
        cout<<"Discounted Price: "<<ticketprice;
    }
    
    
}