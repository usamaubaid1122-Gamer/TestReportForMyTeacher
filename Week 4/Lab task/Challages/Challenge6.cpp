#include<iostream>
using namespace std;
main()
{
    int salary = 10000;
    int laptop = 50000; 
    int month = 6;
    float advance;
    advance = salary * 0.5 * month;
    if (advance >= laptop)
    {
        cout<<"ali buy the laptop";
    }
    else
    {
        float required_month = laptop /(salary*0.5);
        cout<<required_month<<" months requird to buy a laptop";
    }
}