#include<iostream>
using namespace std;
main()
{
    float Red_Rose,White_Rose,Tulip,total,Discount;
    cout<<"Red Rose: ";
    cin>>Red_Rose;
    cout<<"White Rose: ";
    cin>>White_Rose;
    cout<<"Tulip: ";
    cin>>Tulip;
    total = Red_Rose*2.00 + White_Rose*4.10 + Tulip*2.50;
    if (total >= 200)
    {
        Discount = total - (total * 0.20);
        cout<<"Orignal price: "<<total<<endl;
        cout<<"Price after discount: "<<Discount;
    }
    else
    {
        cout<<"Orignal price: "<<total;
    }
    
}