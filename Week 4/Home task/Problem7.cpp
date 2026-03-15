#include <iostream>
using namespace std;
main()
{
    string shape;
    double area,a,b;
    double pi = 3.14159265359; 
    cout<<"Enter the geomatric figure: ";
    cin>>shape;
    if (shape == "square")
    {
        cout<<"Enter ther area: ";
        cin>> a;
        area = a * a;
    }
    else if (shape == "rectangle")
    {
        cout<<"Enter the Lenght: "<<endl<<"Enter the Width";
        cin>> a >>b;
        area = a*b;
    }
    else if (shape == "circle")
    {
        cout<<"enter the area: ";
        cin>> a;
        area = pi*a*a;
    }
    else if (shape == "triangle")
    {
        cout<<"Enter the Lenght: "<<endl<<"Enter the Width";
        cin>>a>>b;
        area = (a*b)/2;
    }
    cout<< area;
    
}