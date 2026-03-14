#include<iostream>
using namespace std;
main ()
{
    string name_1,name_2;
    cout<<"Enter the first name: ";
    cin>> name_1;
    cout<<"Enter the second name: ";
    cin>> name_2;
    if (name_1 == name_2)
    {
        cout<<"Congratulations you enter the same name";
    }
    else
    {
        cout<<"Try Again";
    }
    
     
}